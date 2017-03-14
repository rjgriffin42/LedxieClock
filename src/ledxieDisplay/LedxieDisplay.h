#include "../ledxieDisplay/Adafruit_NeoPixel.h"
#include "../ledxieTube/LedxieTube.h"


class LedxieDisplay
{
public:
	LedxieDisplay(int number_of_tubes, int pin);

	// methods
	void updateTubes();

private:
	// members;
	Adafruit_NeoPixel led_strip;
	LedxieTube* tubes;
	int number_of_tubes;

	// methods
	void randomLine(int tShuffle, int tLast);
};
