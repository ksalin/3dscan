// Control a stepper motor and take photos using IR controlled camera
// Copyright (C) 2016 Jussi Salin <salinjus@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <wiringPi.h>
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
