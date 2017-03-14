class LedxieTube
{
public:
	virtual void setTubeRingPosition(int ring_position, int first_pixel_position);
	virtual void setLEDStrip(Adafruit_NeoPixel led_strip);

	virtual void setNumberToDisplay(int number);
	virtual void setColorToDisplay(int color[3]);
	virtual void setDisplayBrightness(int brightness);

	virtual void update();
	virtual void tubeOff();

	virtual int getNumberOfLEDS();
	virtual int getCurrentDisplayedNumber();
};
