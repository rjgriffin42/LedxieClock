#include "LedxieTube_v1_0.h"

LedxieTube_v1_0::LedxieTube_v1_0()
{
	ring_position = 0;
	first_pixel_position = 0;

	brightness = 255;
	color = {255, 55, 0};
	black = {0, 0, 0};

	current_number_to_display = NUM_LEDS;
	previous_number_to_display = NUM_LEDS;
}

void LedxieTube_v1_0::setTubeRingPosition(int ring_position, int first_pixel_position)
{
	this->ring_position = ring_position;
	this->first_pixel_position = first_pixel_position;
}

void LedxieTube_v1_0::setLEDStrip(Adafruit_NeoPixel led_strip)
{
	this->led_strip = led_strip;
}

void LedxieTube_v1_0::setNumberToDisplay(int number_to_display)
{
	previous_number_to_display = current_number_to_display;
	if (number_to_display < NUM_LEDS && number_to_display >= 0)
	{
		current_number_to_display = number_to_display;
	}
}

void LedxieTube_v1_0::setColorToDisplay(int color[3])
{
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = color[i];
	}
}

void LedxieTube_v1_0::setDisplayBrightness(int brightness)
{
	this->brightness = brightness;
}

void LedxieTube_v1_0::update()
{
    turnNumberOn(current_number_to_display, color);
    turnNumberOff(previous_number_to_display);
}

void LedxieTube_v1_0::turnNumberOn(int number, int color[3])
{
	if (number < NUM_LEDS && number >= 0)
	{
		int pixel_number = led_mapping[number] + first_pixel_position;
		led_strip.setPixelColor(pixel_number, led_strip.Color(color[0], color[1], color[2]));
	}
}

void LedxieTube_v1_0::turnNumberOff(int number)
{
	if (number < NUM_LEDS && number >= 0)
	{
		int pixel_number = led_mapping[number] + first_pixel_position;
		led_strip.setPixelColor(pixel_number, led_strip.Color(black[0], black[1], black[2]));
	}
}

void LedxieTube_v1_0::tubeOff()
{
	for (int led_index = 0; led_index < NUM_LEDS; led_index++)
	{
		turnNumberOff(led_index);
	}
}
