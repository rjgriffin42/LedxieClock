#include "RandomLineDisplay.h"

RandomLineDisplay::RandomLineDisplay(int numOfTubes, int pin)
{
	tubeNum = numOfTubes;
	int number_of_pixels = 0;

	tubes = new LedxieTubeV1[numOfTubes];
	for (int i = 0; i < tubeNum; i++)
	{
		tubes[i].setNumberToDisplay(12);
		tubes[i].setTubeRingPosition(i);
		tubes[i].setLEDStrip(pixels);

		number_of_pixels += tubes[i].getNumberOfLEDs();
	}

	pixels = Adafruit_NeoPixel(number_of_pixels, pin, NEO_GRB + NEO_KHZ800);
	pixels.begin();
}


void RandomLineDisplay::randomLine(int tShuffle, int tLast)
{
	int dim = 255;

	for (int i = 0; i < tubeNum; i++)
	{
		tubes[i].setDisplayBrightness(dim);
	}
	updateTubes();

	//shuffle random numbers
	unsigned long tStart;
	tStart = millis();
	unsigned long tEnd = tStart + tShuffle;
	int randomNum;

	//shuffle for time
	while (millis() <= tEnd)
	{
		for (int i = 0; i < tubeNum; i++)
		{
			randomNum = random(10);
			while (tubes[i].getNumberToDisplay() == randomNum)
			{
				randomNum = random(10);
			}
			tubes[i].setNumberToDisplay(randomNum);
		}
		updateTubes();

	}

	//fix decimal dot
	tubes[6].setNumberToDisplay(10);
	updateTubes();

	//generate random stop number
	int list[tubeNum] = {0,1,2,3,4,5,-1,7};
	for (int a=0; a<tubeNum; a++)
	{
		int r = random(tubeNum);
		int temp = list[a];
		list[a] = list[r];
		list[r] = temp;
	}

	//stop according to random order
	for(int i = 0; i < tubeNum; i ++)
	{
		tStart = millis();
		tEnd = tStart + 200;
		while(millis() <= tEnd)
		{
			//mark stop shuffle
			list[i] = -1;
			for (int j = 0; j < tubeNum; j++)
			{
				if(list[j] >= 0)
				{
					randomNum = random(10);
					while (tubes[i].getNumberToDisplay() == randomNum)
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

void RandomLineDisplay::updateTubes()
{
	for (int i = 0; i < tubeNum; i++)
	{
		tubes[i].update();
	}
	delay(10);
}

String RandomLineDisplay::getCurrent() const
{

	String output = "";
	for (int i = tubeNum - 1; i >= 0; i--)
	{
		int thisNum = tubes[i].getNumberToDisplay();
		output = output + " | " + String(thisNum);
	}
	return output;
}


