# Arduino Ultrasonic Parking Sensor

## Overview

An Arduino-based parking sensor prototype that measures the distance to nearby objects using an ultrasonic sensor. A buzzer provides audio feedback based on distance, while an LCD displays the measured distance in centimeters.

## Components

* Arduino board
* HC-SR04-compatible ultrasonic sensor and `SR04` library
* Buzzer
* 16x2 LCD
* Jumper wires

## Features

* Measures distance using an ultrasonic sensor
* Changes buzzer pitch and beep intervals based on distance
* Displays distance readings on an LCD
* Provides a stop warning when an object is very close

## Libraries

* `SR04.h`
* `pitches.h`
* `LiquidCrystal.h`

## Status

Initial working prototype. Further testing and code improvements are planned.
