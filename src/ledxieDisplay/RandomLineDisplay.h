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
	String getCurrent() const ;

private:
	//variables
	int tubeNum;
	int LED[11] = {2, 3, 4, 9, 1, 6, 0, 7, 5, 10, 8};//LED mapping
	Adafruit_NeoPixel pixels;
	LedTube* tubes;

	//functions
	void updateTubes();
};


#endif // NEWNIXIEDISP_H