#include "LedDisplayArray.h"

LedDisplayArray::LedDisplayArray(void)
{
}

LedDisplayArray::LedDisplayArray(int numOfTubes, int pin)
{
	number_of_tubes = numOfTubes;
	int number_of_pixels = 0;

	color = new int[numOfTubes][3];

	tubes = new LedxieTubeV1[numOfTubes];
	for (int i = 0; i < number_of_tubes; i++)
	{
		tubes[i].setNumberToDisplay(12);
		tubes[i].setTubeRingPosition(i);

		number_of_pixels += tubes[i].getNumberOfLEDs();

		color[i][0] = 255;
		color[i][1] = 55;
		color[i][2] = 0;
	}

	pixels = Adafruit_NeoPixel(number_of_pixels, pin, NEO_GRB + NEO_KHZ800);
	pixels.begin();

	for (int i = 0; i < number_of_tubes; i++)
	{
	    tubes[i].setLEDStrip(pixels);
	}
}

LedDisplayArray::~LedDisplayArray(void)
{
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
	for (int j = 0; j < 3; j++)
	{
		this->color[tubeNumber][j] = color[j];
	}
}

void LedDisplayArray::updateValues(int values[])
{
	for (int i = 0; i < number_of_tubes; i++)
	{
		tubes[i].setDisplayBrightness(255);
		tubes[i].setColorToDisplay(color[i]);
		tubes[i].setNumberToDisplay(values[i]);
		tubes[i].update();
	}
	pixels.show();
	delay(100);
}

