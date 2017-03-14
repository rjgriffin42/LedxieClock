#include "LedxieTube_v1_0.h"

LedxieTube_v1_0::LedxieTube_v1_0()
{
	ring_position = 0;
}

void LedxieTube_v1_0::setTubeRingPosition(int ring_position)
{
	this->ring_position = ring_position;
}

void LedxieTube_v1_0::setLEDStrip(Adafruit_NeoPixel strip)
{
	this->strip = strip;
}

void LedxieTube_v1_0::setNumberToDisplay(int number)
{
	// todo
}

void LedxieTube_v1_0::tubeOff()
{
	for (int led_index = 0; led_index < NUM_LEDS; led_index++)
	{
		strip.setPixelColor(led_index, strip.Color(0, 0, 0));
	}
}
