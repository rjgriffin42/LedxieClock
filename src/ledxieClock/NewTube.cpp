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

void NewTube::setRingPosition(int ring_position)
{
	this->ring_position = ring_position;
}

void NewTube::setLEDStrip(Adafruit_NeoPixel& led_strip)
{
	this->led_strip = &led_strip;
}

void NewTube::turnOnNewNumber()
{
	turnOnNewNumber(*led_strip);
}

void NewTube::turnOffOldNumber()
{
	turnOffOldNumber(*led_strip);
}

void NewTube::turnOnNewNumber(Adafruit_NeoPixel& led_strip)
{
	turnOnNewNumber(ring_position, led_strip);
}

void NewTube::turnOffOldNumber(Adafruit_NeoPixel& led_strip)
{
	turnOffOldNumber(ring_position, led_strip);
}

void NewTube::turnOnNewNumber(int ring_position, Adafruit_NeoPixel& led_strip)
{
	if(getValue() < 11)
	{
		led_strip.setPixelColor(LED[getValue()] + (11 * ring_position), led_strip.Color(255, 55, 0));
	}
}

void NewTube::turnOffOldNumber(int ring_position, Adafruit_NeoPixel& led_strip)
{
	if(getPreviousValue() != getValue())
		led_strip.setPixelColor(LED[getPreviousValue()] + (11 * ring_position), led_strip.Color(0, 0, 0));
}
