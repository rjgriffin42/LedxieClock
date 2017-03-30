/*
 * ClockDisplay.cpp`
 *
 *  Created on: Mar 21, 2017
 *      Author: Robert Griffin
 */

#include "ClockDisplay.h"

ClockDisplay::ClockDisplay()
{
	ledDisplayArray = new LedDisplayArray(DISPLAY_SIZE, DISPLAY_PIN_NUMBER);
}

ClockDisplay::~ClockDisplay()
{
	// TODO Auto-generated destructor stub
}

void ClockDisplay::initialize()
{
	if (! realtimeClock.begin())
	{
		Serial.println("Couldn't find the RTC.");
		while(1);
	}

	if (realtimeClock.lostPower())
	{
		Serial.println("RTC lost power, let's set the time!");
		// the RTC is set to the date and time this code was compiled.
		realtimeClock.adjust(DateTime(F(__DATE__), F(__TIME__)));

		// set it to 12AM on January 1st, 2001
		//realtimeClock.adjust(DateTime(2001, 1, 1, 12, 0, 0));
	}
}

void ClockDisplay::update()
{
	DateTime now = realtimeClock.now();

	int hour = now.hour();
	int minute = now.minute();
	int second = now.second();

	computeDisplaySignal(hour, minute, second);

	ledDisplayArray->updateValues(values);
}

void ClockDisplay::computeDisplaySignal(int hour, int minute, int second)
{
	if (second >= 10)
	{
		values[0] = second / 10;
		values[1] = second - values[0];
	}
	else
	{
		values[0] = second;
		values[1] = 0;
	}

	if (minute >= 10)
	{
		values[3] = minute / 10;
		values[4] = minute - values[2];
	}
	else
	{
		values[3] = minute;
		values[4] = 0;
	}

	if (hour >= 10)
	{
		values[6] = hour / 10;
		values[7] = hour - values[2];
	}
	else
	{
		values[6] = hour;
		values[7] = 0;
	}

	// set colon
	values[2] = 10;
	values[5] = 10;
}

