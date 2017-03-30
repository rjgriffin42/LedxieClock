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
#include "LedDisplayArray.h"

class RandomLineDisplay
{
public:
	RandomLineDisplay(int numOfTubes, int pin);
	void randomLine(int tShuffle, int tLast);
    void randomLineAlt(int tShuffle, int tLast);
    void updateValues(int values[]);

private:
	//variables
	int tubeNum;
	LedDisplayArray *ledDisplay;

	int (*value);

	//functions
	void updateTubes(int brightness, int value[]);
};


#endif // NEWNIXIEDISP_H
