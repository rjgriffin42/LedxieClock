#include "NewNixieDisp.h"

NewNixieDisp::NewNixieDisp(int numOfTubes, int pin)
{
	tubeNum = numOfTubes;
	NUMPIXELS = tubeNum * 11;
	tubes = new NewTube[numOfTubes];
	for (int i = 0; i < tubeNum; i++)
	{
		tubes[i].setPreviousValue(tubes[i].getValue());
		tubes[i].setCurrentValue(12);
		tubes[i].setRingPosition(i);
		tubes[i].setLEDStrip(pixels);
	}
	//initialize pixels
	pixels = Adafruit_NeoPixel(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800);
	//start the pixel;
	pixels.begin();
}


void NewNixieDisp::randomLine(int tShuffle, int tLast)
{
	int dim = 255;
	pixels.setBrightness(dim);
	pixels.show();
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
			while (tubes[i].getValue() == randomNum)
			{
				randomNum = random(10);
			}
			tubes[i].setValue(randomNum);
		}
		updateTubes();

	}

	//fix decimal dot
	tubes[6].setValue(10);
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
					while (tubes[i].getValue() == randomNum)
					{
						randomNum = random(10);
					}
					tubes[list[j]].setValue(randomNum);
				}
			}
			updateTubes();
		}
	}

	delay(tLast);
}

void NewNixieDisp::updateTubes()
{
	for (int i = 0; i < tubeNum; i++)
	{
		tubes[i].turnOnNewNumber();
	}
	pixels.show();
	delay(5);
	//turn off old numbers
	for (int i = 0; i < tubeNum; i++)
	{
		tubes[i].turnOffOldNumber();
	}
	pixels.show();
	delay(10);
}

void NewNixieDisp::tubeOff(int tubeNum)
{
	for (int i = 0; i < 11; i++)
	{
		pixels.setPixelColor(i + (11 * tubeNum), pixels.Color(0, 0, 0));
	}
}

String NewNixieDisp::getCurrent() const
{

	String output = "";
	for (int i = tubeNum - 1; i >= 0; i--)
	{
		int thisNum = tubes[i].getValue();
		output = output + " | " + String(thisNum);
	}
	return output;
}


