#ifndef LEDDISPLAYARRAY_H
#define LEDDISPLAYARRAY_H

#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include "../ledTube/ledxieTubeV1/LedxieTubeV1.h"
#include "../ledTube/LedTube.h"

class LedDisplayArray
{
public:
	LedDisplayArray(int numOfTubes, int pin);
	void updateValues(int values[]);

private:
	//variables
	int number_of_tubes;
	int brightness = 255;
	int color[3] = {255, 255, 0};
	Adafruit_NeoPixel pixels;
	LedTube* tubes;
};


#endif // NEWNIXIEDISP_H
