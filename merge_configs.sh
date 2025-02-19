#!env bash
set -e # exit on error instead of continuing

# turn this into a nix thing later if I get a ton of time - would fix the annoyances of shell script and skip the need for docker

# set layout id and geometry - modify here to be default
layout_id="NWALw"
layout_geometry="moonlander"

layout_path="$(pwd)/${layout_id}"

# Set keyboard directory and make prefix
keyboard_directory="$HOME/dev/qmk_firmware/keyboards/zsa"
make_prefix="zsa/"


# get any code changes from qmk_firmware

# sync qmk_firmware keymap to moonlander-config
echo "Getting ${layout_id} from qmk_firmware"
rsync -rauv "${keyboard_directory}/${layout_geometry}/keymaps/${layout_id}/" "$(readlink -f $layout_path)"

# commit unstaged changes right away to streamline dev process
git commit -a -m "some local changes" || echo "No new local changes"
git push


# checkout oryx branch of repo to pull changes into
git checkout oryx

# Download the full history for the merge to work correctly
git pull

# Download layout source
# hardcode geometry and layout_id for now, will fix when turning into nix expression
response=$(curl --location 'https://oryx.zsa.io/graphql' --header 'Content-Type: application/json' --data '{"query":"query getLayout($hashId: String!, $revisionId: String!, $geometry: String) {layout(hashId: $hashId, geometry: $geometry, revisionId: $revisionId) {  revision { hashId, qmkVersion, title }}}","variables":{"hashId":"NWALw","geometry":"moonlander","revisionId":"latest"}}' | jq '.data.layout.revision | [.hashId, .qmkVersion, .title]')
hash_id=$(echo "${response}" | jq -r '.[0]')
firmware_version=$(printf "%.0f" $(echo "${response}" | jq -r '.[1]'))
change_description=$(echo "${response}" | jq -r '.[2]')
if [[ -z "${change_description}" ]]; then
  change_description="latest layout modification made with Oryx"
  fi

curl -L "https://oryx.zsa.io/source/${hash_id}" -o source.zip

echo firmware_version=${firmware_version}
echo change_description=${change_description}

# Unzip the source file
unzip -oj source.zip '*_source/*' -d ${layout_id}
rm source.zip


# Commit and Push changes
git add $layout_id
git commit -m "✨(oryx): ${change_description}" || echo "No layout change"
git push

# Merge Oryx with custom QMK
git fetch origin main
git checkout -B main origin/main
git merge -Xignore-all-space oryx || $(echo "merge failed, fix it" && exit)
git push

# Checkout the right firmware branch - don't do this every time for speed
# cd ~/qmk_firmware
# git submodule update --init --remote
# git fetch origin firmware${firmware_version}
# git checkout -B firmware${firmware_version} origin/firmware${firmware_version}
# git submodule update --init --recursive

# Build the layout
# just skip symlinking so it doesn't recompile each time
# forcibly symlink the folder so my changes actually make it through the copy
# ln -sf "$(readlink -f $layout_path)" "${keyboard_directory}/${layout_geometry}/keymaps/"

# use rsync to copy folder directly so edits can be carried out in qmk_firmware
# with proper lsp support
# since code edits are made from within qmk_firmware, copy changes to this repo, merge, then send back


# sync moonlander-config keymap to qmk_firmware
echo "Sending ${layout_id} to qmk_firmware"
rsync -rauv "$(readlink -f $layout_path)" "${keyboard_directory}/${layout_geometry}/keymaps/"

# Build the layout
# qmk setup zsa/qmk_firmware -b firmware${firmware_version} -y
qmk compile -kb ${make_prefix}${layout_geometry} -km ${layout_id}

# Find and export built layout
normalized_layout_geometry="$(echo "${layout_geometry}" | sed 's/\//_/g')"
built_layout_file="$HOME/dev/qmk_firmware/zsa_moonlander_${layout_id}.bin"
echo built_layout_file="$built_layout_file"
echo normalized_layout_geometry=${normalized_layout_geometry}

# flash with wally
wally-cli "${built_layout_file}"
