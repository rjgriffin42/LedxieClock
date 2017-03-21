/*
 * ClockDisplay.h
 *
 *  Created on: Mar 21, 2017
 *      Author: shadylady
 */

#ifndef CLOCKDISPLAY_H_
#define CLOCKDISPLAY_H_

#include "LedDisplayArray.h"

#define DISPLAY_SIZE 8
#define DISPLAY_PIN_NUMBER 6

class ClockDisplay
{
public:
	ClockDisplay();
	virtual ~ClockDisplay();

	void update();
private:
	int values[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	LedDisplayArray ledDisplayArray = LedDisplayArray(DISPLAY_SIZE, DISPLAY_PIN_NUMBER);
};

#endif /* SRC_LEDXIEDISPLAY_CLOCKDISPLAY_H_ */
