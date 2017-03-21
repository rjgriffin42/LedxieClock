/*
 * LedxieTubeV1.h
 *
 *  Created on: Mar 20, 2017
 *      Author: Robert Griffin
 */

#ifndef LEDXIETUBEV1_H_
#define LEDXIETUBEV1_H_

#include "../LedTube.h"
#include "../../adafruit_NeoPixel/Adafruit_NeoPixel.h"

#define NUM_LEDS 11

class LedxieTubeV1 : public LedTube
{
public:
	LedxieTubeV1();
	virtual ~LedxieTubeV1();

	void setNumberToDisplay(int value);
	void setColorToDisplay(int color[3]);

	void setDisplayBrightness(int brightness);

	int getNumberToDisplay();
	int getNumberOfLEDs();

	void setTubeRingPosition(int ring_position);
	void setLEDStrip(Adafruit_NeoPixel& led_strip);

	void turnOff();
	void update();


private:

	int LED[11] = {2, 3, 4, 9, 1, 6, 0, 7, 5, 10, 8};//LED mapping

	int ring_position;
	Adafruit_NeoPixel* led_strip;

	int currentValue;
	int previousValue;

	int color[3] = {255, 55, 0};
	int brightness = 255;

	void setCurrentValue(int value);
	void setPreviousValue(int value);

	void turnOnNewNumber();
	void turnOffOldNumber();
};

#endif /* LEDXIETUBEV1_H_ */
