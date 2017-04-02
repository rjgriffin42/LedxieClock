#ifndef LEDDISPLAYARRAY_H
#define LEDDISPLAYARRAY_H

#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include "../ledTube/ledxieTubeV1/LedxieTubeV1.h"
#include "../ledTube/LedTube.h"

class LedDisplayArray
{
public:
	LedDisplayArray(int numOfTubes, int pin);
	LedDisplayArray(void);
	 ~LedDisplayArray(void);

	void setDisplayBrightness(int brightness);
	void setTubeColors(int color[][3]);
	void setTubeColor(int tubeNumber, int color[3]);
	void updateValues(int values[]);

private:
	//variables
	int number_of_tubes;
	int brightness = 255;
	int (*color)[3];
	Adafruit_NeoPixel pixels;
	//LedxieTubeV1 *tubes;
	LedTube *tubes;
};


#endif // LedDisplayArray
