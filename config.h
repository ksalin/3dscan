// Raspberry Pi GPIO numbering
#define DIR_PIN 25	// Pin 22
#define STEP_PIN 8	// Pin 24
#define ENABLE_PIN 15	// Pin 10
//
//  2  4  6  8  10 12 14 16 18 20 22 24 26
//  o  o  o  o  o  o  o  o  o  o  o  o  o
//  o  o  o  o  o  o  o  o  o  o  o  o  o
//  1  3  5  7  9  11 13 15 17 19 21 23 25
//

// Fine tune for motor, these are for ST28
#define STEPS_PER_DEGREE 4096/360
#define STEP_INTERVAL 5000

// Fine tune for camera
#define PRE_PHOTO_DELAY 500000
#define POST_PHOTO_DELAY 500000

#define TAKE_PHOTO_CMD "irsend SEND_ONCE CANON-RC1/RC5 X_KEY_2S"
