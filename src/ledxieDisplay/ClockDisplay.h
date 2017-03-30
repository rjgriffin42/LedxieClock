/*
 * ClockDisplay.h
 *
 *  Created on: Mar 21, 2017
 *      Author: shadylady
 */

#ifndef CLOCKDISPLAY_H_
#define CLOCKDISPLAY_H_

#include <Wire.h>
#include "LedDisplayArray.h"
#include "../realTimeClock/RTClib.h"

#define DISPLAY_SIZE 8
#define DISPLAY_PIN_NUMBER 6

class ClockDisplay
{
public:
	ClockDisplay();
	virtual ~ClockDisplay();

	void initialize();
	void update();
private:
	int values[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	LedDisplayArray *ledDisplayArray;
	RTC_DS3231 realtimeClock;
	bool firstTick = true;

	void computeDisplaySignal(int hour, int minute, int second);
};

#endif /* CLOCKDISPLAY_H_ */
