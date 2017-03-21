#ifndef NEWNIXIEDISP_H
#define NEWNIXIEDISP_H

#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include <string.h>
#include <stdlib.h>
#include "TimerOne.h"
#include "NewTube.h"


class NewNixieDisp
{
public:
	NewNixieDisp(int numOfTubes, int pin);
	void randomLine(int tShuffle, int tLast);
	String getCurrent() const ;

private:
	//variables
	int NUMPIXELS;
	int tubeNum;
	int LED[11] = {2, 3, 4, 9, 1, 6, 0, 7, 5, 10, 8};//LED mapping
	Adafruit_NeoPixel pixels;
	NewTube* tubes;

	//functions
	void updateTubes();
	void tubeOff(int tubeNum);

};


#endif // NEWNIXIEDISP_H
