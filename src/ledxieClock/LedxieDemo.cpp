#ifndef LEDXIEDEMO_H
#define LEDXIEDEMO_H

#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include "NixieDisp.h"
#include "../ledxieDisplay/RandomLineDisplay.h"
#include "../ledxieDisplay/ClockDisplay.h"
#include "../ledxieDisplay/LedDisplayArray.h"


#define CLOCK_PRESCALER_1   (0x0)

#define PIN_NUMBER 6
#define NUMBER_OF_TUBES 8
//RandomLineDisplay *display;
ClockDisplay *display;
//LedDisplayArray *displayArray;
int number_of_pixels;

void setup()
{
	//display = new RandomLineDisplay(NUMBER_OF_TUBES, PIN_NUMBER);
	display = new ClockDisplay();
	Serial.begin(115200);
	Serial.println("--- Start Serial Monitor SEND_RCVE ---");

	//displayArray = new LedDisplayArray(NUMBER_OF_TUBES, PIN_NUMBER);

}

void loop()
{
	/*
	int values[8];
	for (int i = 0; i < 8; i++)
	{
	   values[i] = 6;
	}
	*/

	//displayArray->updateValues(values);


	//display->updateValues(values);
	display->update();

	//display->randomLine(1000, 1000 * 10);

	Serial.println("what");
	Serial.println(3);

}

#endif // LEDXIEDEMO_H
