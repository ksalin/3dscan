/**
 * Control a stepper motor
 *
 * (C) 2016 Jussi Salin
 */

#include <stdio.h>
#include <wiringPi.h> // Include WiringPi library!
#include <unistd.h>
#include <stdlib.h>
#include "config.h"

/**
 * Main program
 */
int main(int argc, const char *argv[])
{
    int i, j, degrees, steps;

    if (argc != 2)
    {
        printf("Usage: 3dscan <degrees per frame>\n");
        printf("Example: motor 10\n");
        return 1;
    }
    degrees = atoi(argv[1]);
    if ((degrees <=0) || (degrees >360))
    {
        printf("Degrees is not a reasonable value between 1 to 360.\n");
        return 1;
    }

    // Initialize Wiring PI library and pins
    wiringPiSetupGpio();

    pinMode(DIR_PIN, OUTPUT);
    pinMode(STEP_PIN, OUTPUT);
    pinMode(ENABLE_PIN, OUTPUT);

    // Set directions and enable motor drivers
    digitalWrite(DIR_PIN, LOW);
    digitalWrite(ENABLE_PIN, LOW); // Inverse logic

    steps = degrees * STEPS_PER_DEGREE;

    // Perform rotation of both motors
    for (j=0; j<360; j+=degrees)
    {
    for (i=0; i<steps/2; i++)
    {
        digitalWrite(STEP_PIN, HIGH);
	usleep(STEP_INTERVAL);
        digitalWrite(STEP_PIN, LOW);
	usleep(STEP_INTERVAL);
    }
    usleep(PRE_PHOTO_DELAY);
    system(TAKE_PHOTO_CMD);
    printf(".");
    fflush(stdout);
    usleep(POST_PHOTO_DELAY);
    }
    printf("\nDone.\n");

    // Disable motor drivers to save energy
    digitalWrite(ENABLE_PIN, HIGH); // Inverse logic

    return 0;
}
