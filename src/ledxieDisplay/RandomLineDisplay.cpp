#include "RandomLineDisplay.h"

RandomLineDisplay::RandomLineDisplay(int numOfTubes, int pin)
{
	tubeNum = numOfTubes;
	ledDisplay = new LedDisplayArray(numOfTubes, pin);

	value = new int[numOfTubes];
}

void RandomLineDisplay::randomLineAlt(int tShuffle, int tLast)
{
	int dim = 255;

	ledDisplay->setDisplayBrightness(dim);
	ledDisplay->updateValues(value);

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
			while (value[i] == randomNum)
			{
				randomNum = random(10);
			}
			value[i] = randomNum;
		}
		ledDisplay->updateValues(value);

	}

	//fix decimal dot
	value[6] = 10;
	ledDisplay->updateValues(value);

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
					while (value[i] == randomNum)
					{
						randomNum = random(10);
					}
					value[list[j]] = randomNum;
				}
			}
			ledDisplay->updateValues(value);
		}
	}

	delay(tLast);
}

void RandomLineDisplay::updateValues(int values[])
{
	ledDisplay->updateValues(values);
}

void RandomLineDisplay::randomLine(int tShuffle, int tLast)
{
	int dim = 255;

	updateTubes(dim, value);

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
			while (value[i] == randomNum)
			{
				randomNum = random(10);
			}
			value[i] = randomNum;
		}
		updateTubes(dim, value);

	}

	//fix decimal dot
	value[6] = 10;
	updateTubes(dim, value);

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
					while (value[i] == randomNum)
					{
						randomNum = random(10);
					}
					value[list[j]] = randomNum;
				}
			}
			updateTubes(dim, value);
		}
	}

	delay(tLast);
}

void RandomLineDisplay::updateTubes(int brightness, int value[])
{
	ledDisplay->setDisplayBrightness(brightness);
	ledDisplay->updateValues(value);

	delay(10);
}


