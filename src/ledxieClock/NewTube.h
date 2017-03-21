/*
 * NewTube.h
 *
 *  Created on: Mar 20, 2017
 *      Author: Robert Griffin
 */

#ifndef NEWTUBE_H_
#define NEWTUBE_H_

#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"

#define NUM_LEDS 11

class NewTube {
public:
	NewTube();
	virtual ~NewTube();

	void setNumberToDisplay(int value);
	void setColorToDisplay(int color[3]);

	void setDisplayBrightness(int brightness);

	int getNumberToDisplay();
	int getNumberOfLEDS();

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

#endif /* NEWTUBE_H_ */
