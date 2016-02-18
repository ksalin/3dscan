3D scanning control program for RPi
===================================

Copyright (C) 2016 Jussi Salin <salinjus@gmail.com> under GPLv3.

Rotates an object by a stepper motor by 360 degrees by user adjustable steps and sends IR remote command to shoot a photo with a high quality camera every step. The resulting photos can be used in some commercial programs to generate a 3D model of the actual model using image recognition and stable high quality photos taken with accurate rotation.

Install lirc on raspbian and compile this program with "make". Connect stepper motor driver's ENABLE, STEP and DIR pins to the right GPIO pins configured in config.h file. You can also fine tune some other parameters for the motor and camera in use. Sample lirc.conf is one found with google that has remote commands for Canon 350D.

You need to also have correct hardware.conf, of which a sample exists also among this project. You also have to add following line to /boot/config.txt on RPi firmware 3.18.x and newer or lirc module does not work:

    dtoverlay=lirc-rpi,gpio_in_pin=23,gpio_out_pin=22
