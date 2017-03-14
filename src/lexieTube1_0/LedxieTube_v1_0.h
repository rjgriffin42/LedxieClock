#include "../ledxieTube/LedxieTube.cpp"
#include "Adafruit_NeoPixel.h"

#define NUM_LEDS 11
#define LED_MAPPING {2, 3, 4, 9, 1, 6, 0, 7, 5, 10, 8}



class LedxieTube_v1_0 : public LedxieTube
{
public:
	// constructor
	LedxieTube_v1_0();

	// methods
	void setTubeRingPosition(int ring_position);
	void setLEDStrip(Adafruit_NeoPixel strip);

	void setNumberToDisplay(int number);
	void tubeOff();

	int getNumberOfLEDS();

private:
	// objects
	int ring_position;
	Adafruit_NeoPixel strip;

	// methods

};
