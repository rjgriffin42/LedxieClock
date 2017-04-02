/*
 * LedxieTubeV1.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: shadylady
 */

#include "LedxieTubeV1.h"

LedxieTubeV1::LedxieTubeV1()
{
	ring_position = 0;
	currentValue = 0;
	previousValue = 0;
}

LedxieTubeV1::~LedxieTubeV1()
{
}

void LedxieTubeV1::setTubeRingPosition(int ring_position)
{
	this->ring_position = ring_position;
}

void LedxieTubeV1::setLEDStrip(Adafruit_NeoPixel& led_strip)
{
	this->led_strip = &led_strip;
}

void LedxieTubeV1::setDisplayBrightness(int brightness)
{
	//this->brightness = brightness;
}

void LedxieTubeV1::setColorToDisplay(int color[3])
{
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = color[i];
	}
}

void LedxieTubeV1::setNumberToDisplay(int value)
{
	setPreviousValue(getNumberToDisplay());
	setCurrentValue(value);
}

void LedxieTubeV1::setCurrentValue(int value)
{
	currentValue = value;
}

void LedxieTubeV1::setPreviousValue(int value)
{
	previousValue = value;
}

int LedxieTubeV1::getNumberToDisplay()
{
	return currentValue;
}

int LedxieTubeV1::getNumberOfLEDs()
{
	return 11;
}

int LedxieTubeV1::getPixelToTurnOn()
{
	return LED[currentValue] + (NUM_LEDS * 0);
}

void LedxieTubeV1::turnOff()
{
	for (int led_index = 0; led_index < NUM_LEDS; led_index++)
	{
		led_strip->setPixelColor(led_index + (NUM_LEDS * ring_position), led_strip->Color(0, 0, 0));
	}
}

void LedxieTubeV1::turnOnNewNumber()
{
	if(getNumberToDisplay() < 11)
	{
		led_strip->setPixelColor(LED[currentValue] + (NUM_LEDS * ring_position), led_strip->Color(color[0], color[1], color[2]));
	}
}

void LedxieTubeV1::turnOffOldNumber()
{
	if(previousValue != currentValue)
		led_strip->setPixelColor(LED[previousValue] + (NUM_LEDS * ring_position), led_strip->Color(0, 0, 0));
}

void LedxieTubeV1::update()
{
	led_strip->setBrightness(brightness);

	turnOnNewNumber();

	turnOffOldNumber();
	led_strip->show();
}
