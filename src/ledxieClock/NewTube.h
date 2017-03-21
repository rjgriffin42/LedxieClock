/*
 * NewTube.h
 *
 *  Created on: Mar 20, 2017
 *      Author: shadylady
 */

#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"

#ifndef SRC_LEDXIECLOCK_NEWTUBE_H_
#define SRC_LEDXIECLOCK_NEWTUBE_H_

class NewTube {
public:
	NewTube();
	virtual ~NewTube();

	void setValue(int value);
	void setCurrentValue(int value);
	void setPreviousValue(int value);
	int getValue();
	int getPreviousValue();

	int currentValue;
	int previousValue;

private:

	int LED[11] = {2, 3, 4, 9, 1, 6, 0, 7, 5, 10, 8};//LED mapping

	//Adafruit_NeoPixel* led_strip;
};

#endif /* SRC_LEDXIECLOCK_NEWTUBE_H_ */
