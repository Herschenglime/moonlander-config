#ifndef LED_POSITIONS_H_
#define LED_POSITIONS_H_

// sourced from https://www.reddit.com/r/olkb/comments/1hf13uc/zsa_moonlander_key_matrix_to_led_index/
#ifdef RGB_MATRIX_ENABLE
// This makes names for the different per-key RGB LEDs to aid in setting particular lights.
// The order these go in should match the numbered LEDs, and was somewhat annoying to work out.
enum led_location_map {
	LED_0A, // Left side of keyboard starts in the top left and goes top to bottom then left to right.
	LED_1A,
	LED_2A,
	LED_3A,
	LED_4A,
	LED_0B,
	LED_1B,
	LED_2B,
	LED_3B,
	LED_4B,
	LED_0C,
	LED_1C,
	LED_2C,
	LED_3C,
	LED_4C,
	LED_0D,
	LED_1D,
	LED_2D,
	LED_3D,
	LED_4D,
	LED_0E,
	LED_1E,
	LED_2E,
	LED_3E,
	LED_4E,
	LED_0F,
	LED_1F,
	LED_2F,
	LED_3F,
	LED_0G,
	LED_1G,
	LED_2G,
	LED_5A, // Left thumb cluster
	LED_5B, // Left thumb cluster
	LED_5C, // Left thumb cluster
	LED_5D, // Left thumb cluster red button
	// Keyboard Split
	LED_6G, // Right side keyboad starts in top right and goes top to bottom, then right to left.
	LED_7G,
	LED_8G,
	LED_9G,
	LED_AG,
	LED_6F,
	LED_7F,
	LED_8F,
	LED_9F,
	LED_AF,
	LED_6E,
	LED_7E,
	LED_8E,
	LED_9E,
	LED_AE,
	LED_6D,
	LED_7D,
	LED_8D,
	LED_9D,
	LED_AD,
	LED_6C,
	LED_7C,
	LED_8C,
	LED_9C,
	LED_AC,
	LED_6B,
	LED_7B,
	LED_8B,
	LED_9B,
	LED_6A,
	LED_7A,
	LED_8A,
	LED_BG, //Right thumb cluster goes right to left
	LED_BF, //Right thumb cluster goes right to left
	LED_BE, //Right thumb cluster goes right to left
	LED_BD //Right thumb cluster red button

};

#endif


#endif // LED_POSITIONS_H_
