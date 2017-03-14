#ifndef LEDXIEDISPLAY_H
#define LEDXIEDISPLAY_H

#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include "../ledTube/ledxieTubeV1/LedxieTubeV1.h"
#include "../ledTube/LedTube.h"

class LedxieDisplay
{
public:
	LedxieDisplay(int number_of_tubes, int pin);

	// methods
	void updateTubes();
	void randomLine(int tShuffle, int tLast);

private:
	// members;
	Adafruit_NeoPixel led_strip;
	LedTube* tubes;
	int number_of_tubes;

	// methods
};

#endif // LEDXIEDISPLAY_H
