#include "../ledxieDisplay/Adafruit_NeoPixel.h"

class LedxieTube
{
public:
	LedxieTube(void) {};
	~LedxieTube(void) {};

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
