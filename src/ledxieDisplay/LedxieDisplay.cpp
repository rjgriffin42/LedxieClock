#include "LedxieDisplay.h"

LedxieDisplay::LedxieDisplay(int number_of_tubes, int pin_number)
{
	this->number_of_tubes = number_of_tubes;
	int number_of_pixels = 0;

	// create each tube and assign it positions
	tubes = new LedxieTube_v1_0[number_of_tubes];
	for (int tube_index; tube_index < number_of_tubes; tube_index++)
	{
		tubes[tube_index].setTubeRingPosition(tube_index, number_of_pixels);
		number_of_pixels += tubes[tube_index].getNumberOfLEDS();
	}

	// create the led strip output and set it to each tube
	led_strip = new Adafruit_NeoPixel(number_of_pixels, pin_number, NEO_GRB + NEO_KHZ800);
	for (int tube_index; tube_index < number_of_tubes; tube_index++)
	{
		tubes[tube_index].setLEDStrip(led_strip);
	}
}

void LedxieDisplay::randomLine(int tShuffle, int tLast)
{
	led_strip.show();
	updateTubes();

	// shuffle random numbers
	unsigned long tStart = millis();
	unsigned long tEnd = tStart + tShuffle;
	int randomNum;

	// shuffle for time
	while (millis() <= tEnd)
	{
		for (int tube_index = 0; tube_index < number_of_tubes; tube_index++)
		{
			randomNum = random(10);
			while (tubes[tube_index].getCurrentDisplayedNumber() == randomNum)
			{
				randomNum = random(10);
			}
			tubes[tube_index].setNumberToDisplay(randomNum);
		}
		updateTubes();
	}

	// fix decimal dot
	tubes[6].setNumberToDisplay(10);
	updateTubes();

	// generate random stop number
	int list[number_of_tubes] = {0, 1, 2, 3, 4, 5, -1, 7};
	for (int tube_index = 0; tube_index < number_of_tubes; tube_index++)
	{
		int r = random(number_of_tubes);
		int temp = list(tube_index);
		list[tube_index] = list[r];
		list[r] = temp;
	}

	// stop according to random order
	for (int tube_index; tube_index < number_of_tubes; tube_index++)
	{
		tStart = millis();
		tEnd = tStart + 200;

		while (millis() <= tEnd)
		{
			// mark stop shuffle
			list[tube_index] = -1;
			for (int j = 0; j < number_of_tubes; j++)
			{
				if (list[j] >= 0)
				{
					randomNum = random(10);

					while (tubes[tube_index].getCurrentDisplayedNumber == randomNum)
					{
						randomNum = random(10);
					}
					tubes[list[j]].setNumberToDisplay(randomNum);
				}
			}

			updateTubes();
		}
	}

	delay(tLast);
}

void LedxieDisplay::updateTubes()
{
	for (int tube_index = 0; tube_index < number_of_tubes; tube_index++)
	{
		tubes[tube_index].update();
	}
	led_strip.show();
	delay(10);
}
