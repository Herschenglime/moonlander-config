#include "swapper.h"

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t forward,
    uint16_t back,
    uint16_t modifier,
    uint16_t keycode,
    keyrecord_t *record
) {
    // if either the forward or back keycode is directed, run the logic
    if (keycode == forward || keycode == back) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }

            // if its a forward motion, don't wrap in a modifier
            if (keycode == forward) {
                register_code(tabish);
            }

            // otherwise use the modifier to augment the tabish press
            else {
                register_code(modifier);
                register_code(tabish);
                unregister_code(modifier);
            }
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}
