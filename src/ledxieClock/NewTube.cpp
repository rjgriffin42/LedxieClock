/*
 * NewTube.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: shadylady
 */

#include "NewTube.h"

NewTube::NewTube()
{
}

NewTube::~NewTube()
{
}

void NewTube::setValue(int value)
{
	setPreviousValue(getValue());
	setCurrentValue(value);
}

void NewTube::setCurrentValue(int value)
{
	currentValue = value;
}

void NewTube::setPreviousValue(int value)
{
	previousValue = value;
}

int NewTube::getValue()
{
	return currentValue;
}

int NewTube::getPreviousValue()
{
	return previousValue;
}
