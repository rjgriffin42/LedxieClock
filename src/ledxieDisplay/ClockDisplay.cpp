/*
 * ClockDisplay.cpp`
 *
 *  Created on: Mar 21, 2017
 *      Author: Robert Griffin
 */

#include "ClockDisplay.h"

ClockDisplay::ClockDisplay()
{
	//ledDisplayArray = ;
}

ClockDisplay::~ClockDisplay()
{
	// TODO Auto-generated destructor stub
}

void ClockDisplay::update()
{

	while(true)
	{
		// TODO poll time

		ledDisplayArray.updateValues(values);
	}
}

