#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"

#define NUM_LEDS 11

class LedxieTubeV1
{
public:
	// constructor
	LedxieTubeV1();
	~LedxieTubeV1();

	// methods
	void setTubeRingPosition(int ring_position, int first_pixel_position);
	void setLEDStrip(Adafruit_NeoPixel led_strip);

	void setNumberToDisplay(int number);
	void setColorToDisplay(int color[3]);
	void setDisplayBrightness(int brightness);
	void tubeOff();

	void update();

	int getNumberOfLEDs();
	int getCurrentlyDisplayedNumber();

private:
	// objects
	int led_mapping[NUM_LEDS] = {2, 3, 4, 9, 1, 6, 0, 7, 5, 10, 8};
	int ring_position;
	int first_pixel_position;

	Adafruit_NeoPixel led_strip;

	int current_number_to_display;
	int previous_number_to_display;

	int color[3] = {255, 55, 0};
	int	black[3] = {0, 0, 0};
	int brightness;

	// methods
	void turnNumberOn(int number, int color[3]);
	void turnNumberOff(int number);

};
/*
class LedTube
{
public:
	LedTube(void) {};
	virtual ~LedTube(void) {};

	virtual void setTubeRingPosition(int ring_position, int first_pixel_position) = 0;
	virtual void setLEDStrip(Adafruit_NeoPixel led_strip) = 0;

	virtual void setNumberToDisplay(int number) = 0;
	virtual void setColorToDisplay(int color[3]) = 0;
	virtual void setDisplayBrightness(int brightness) = 0;

	virtual void update() = 0;
	virtual void tubeOff() = 0;

	virtual int getNumberOfLEDs() = 0;
	virtual int getCurrentDisplayedNumber() = 0;

private:
};
*/


