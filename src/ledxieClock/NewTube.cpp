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

void NewTube::setTubeRingPosition(int ring_position)
{
	this->ring_position = ring_position;
}

void NewTube::setLEDStrip(Adafruit_NeoPixel& led_strip)
{
	this->led_strip = &led_strip;
}

void NewTube::setDisplayBrightness(int brightness)
{
	this->brightness = brightness;
}

void NewTube::setColorToDisplay(int color[3])
{
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = color[i];
	}
}

void NewTube::setNumberToDisplay(int value)
{
	setPreviousValue(getNumberToDisplay());
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

int NewTube::getNumberToDisplay()
{
	return currentValue;
}

int NewTube::getNumberOfLEDS()
{
	return NUM_LEDS;
}

void NewTube::turnOff()
{
	for (int led_index = 0; led_index < NUM_LEDS; led_index++)
	{
		led_strip->setPixelColor(led_index + (NUM_LEDS * ring_position), led_strip->Color(0, 0, 0));
	}
}

void NewTube::turnOnNewNumber()
{
	if(getNumberToDisplay() < 11)
	{
		led_strip->setPixelColor(LED[currentValue] + (NUM_LEDS * ring_position), led_strip->Color(color[0], color[1], color[2]));
	}
}

void NewTube::turnOffOldNumber()
{
	if(previousValue != currentValue)
		led_strip->setPixelColor(LED[previousValue] + (NUM_LEDS * ring_position), led_strip->Color(0, 0, 0));
}

void NewTube::update()
{
	led_strip->setBrightness(brightness);
	led_strip->show();

	turnOnNewNumber();
	led_strip->show();

	turnOffOldNumber();
	led_strip->show();
}
