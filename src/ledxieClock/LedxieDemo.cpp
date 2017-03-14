#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Adafruit_NeoPixel.h"
#include "NixieDisp.h"

#define CLOCK_PRESCALER_1   (0x0)

#define PIN_NUMBER 6
#define NUMBER_OF_TUBES 8
//NixieDisp *nixie;
LedxieDisplay *ledxie;

void setup()
{
	//nixie = new NixieDisp(8, 6);
	ledxie = new LedxieDisplay(NUMBER_OF_TUBES, PIN_NUMBER);
	Serial.begin(115200);
	Serial.println("--- Start Serial Monitor SEND_RCVE ---");
}

void loop()
{
	//nixie->randomLine(1000, 1000 * 10);
	ledxie->randomLine(1000, 1000 * 10);
	//Serial.println(nixie->getCurrent());

	//nixie->debug();
}
