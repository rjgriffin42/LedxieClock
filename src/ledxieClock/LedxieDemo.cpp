#ifndef LEDXIEDEMO_H
#define LEDXIEDEMO_H

#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include "NixieDisp.h"
#include "../ledxieDisplay/RandomLineDisplay.h"

#define CLOCK_PRESCALER_1   (0x0)

#define PIN_NUMBER 6
#define NUMBER_OF_TUBES 8
RandomLineDisplay *display;

void setup()
{
	display = new RandomLineDisplay(NUMBER_OF_TUBES, PIN_NUMBER);
	Serial.begin(115200);
	Serial.println("--- Start Serial Monitor SEND_RCVE ---");
}

void loop()
{
	display->randomLine(1000, 1000 * 10);
	//ledxie->randomLine(1000, 1000 * 10);
	//Serial.println(display->getCurrent());

}

#endif // LEDXIEDEMO_H
