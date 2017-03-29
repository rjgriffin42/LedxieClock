#ifndef RANDOMLINEDISPLAY_H
#define RANDOMLINEDISPLAY_H

#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include <string.h>
#include <stdlib.h>
#include "../ledTube/ledxieTubeV1/LedxieTubeV1.h"
#include "../ledTube/LedTube.h"

class RandomLineDisplay
{
public:
	RandomLineDisplay(int numOfTubes, int pin);
	void randomLine(int tShuffle, int tLast);
	void randomLineAlt(int tShuffle, int tLast);
	void randomLineAltAlt(int tShuffle, int tLast);
	String getCurrent() const ;

private:
	//variables
	int tubeNum;
	Adafruit_NeoPixel pixels;
	LedTube* tubes;

	LedDisplayArray ledDisplay;

	int brightness[];
	int value[];

	//functions
	void updateTubes();
	void updateTubes(int brightness[], int value[]);
};


#endif // NEWNIXIEDISP_H
