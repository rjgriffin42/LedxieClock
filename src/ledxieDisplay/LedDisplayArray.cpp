#include "LedDisplayArray.h"

LedDisplayArray::LedDisplayArray(int numOfTubes, int pin)
{
	number_of_tubes = numOfTubes;
	int number_of_pixels = 0;

	color = new int[numOfTubes][];

	tubes = new LedxieTubeV1[numOfTubes];
	for (int i = 0; i < number_of_tubes; i++)
	{
		tubes[i].setNumberToDisplay(12);
		tubes[i].setTubeRingPosition(i);
		tubes[i].setLEDStrip(pixels);

		number_of_pixels += tubes[i].getNumberOfLEDs();

		color[i][3] = {255, 255, 0};
	}

	pixels = Adafruit_NeoPixel(number_of_pixels, pin, NEO_GRB + NEO_KHZ800);
	pixels.begin();
}

LedDisplayArray::~LedDisplayArray()
{
	// default destructor
}

void LedDisplayArray::setDisplayBrightness(int brightness)
{
	this->brightness = brightness;
}

void LedDisplayArray::setTubeColors(int color[][3])
{
	for (int i = 0; i < number_of_tubes; i++)
	{
		setTubeColor(i, color[i]);
	}
}

void LedDisplayArray::setTubeColor(int tubeNumber, int color[3])
{
	this->color[tubeNumber] = color;
}

void LedDisplayArray::updateValues(int values[])
{
	for (int i = 0; i < number_of_tubes; i++)
	{
		tubes[i].setDisplayBrightness(brightness);
		tubes[i].setColorToDisplay(color[i]);
		tubes[i].setNumberToDisplay(values[i]);
		tubes[i].update();
	}
	pixels.show();
	delay(10);
}

