#include "LedDisplayArray.h"

LedDisplayArray::LedDisplayArray(int numOfTubes, int pin)
{
	number_of_tubes = numOfTubes;
	int number_of_pixels = 0;

	tubes = new LedxieTubeV1[numOfTubes];
	for (int i = 0; i < number_of_tubes; i++)
	{
		tubes[i].setNumberToDisplay(12);
		tubes[i].setTubeRingPosition(i);
		tubes[i].setLEDStrip(pixels);

		number_of_pixels += tubes[i].getNumberOfLEDs();
	}

	pixels = Adafruit_NeoPixel(number_of_pixels, pin, NEO_GRB + NEO_KHZ800);
	pixels.begin();
}

void LedDisplayArray::updateValues(int values[])
{
	for (int i = 0; i < number_of_tubes; i++)
	{
		tubes[i].setDisplayBrightness(brightness);
		tubes[i].setColorToDisplay(color);
		tubes[i].setNumberToDisplay(values[i]);
		tubes[i].update();
	}
	pixels.show();
	delay(10);
}

