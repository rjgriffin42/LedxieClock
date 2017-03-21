#ifndef LEDTUBE_H
#define LEDTUBE_H

#include "../adafruit_NeoPixel/Adafruit_NeoPixel.h"

class LedTube
{
public:
	LedTube(void) {};
	virtual ~LedTube(void) {};

	virtual void setTubeRingPosition(int ring_position) = 0;
	virtual void setLEDStrip(Adafruit_NeoPixel& led_strip) = 0;

	virtual void setNumberToDisplay(int number) = 0;
	virtual void setColorToDisplay(int color[3]) = 0;
	virtual void setDisplayBrightness(int brightness) = 0;

	virtual void update() = 0;
	virtual void turnOff() = 0;

	virtual int getNumberOfLEDs() = 0;
	virtual int getNumberToDisplay() = 0;
private:
};

#endif // LEDTUBE_H

