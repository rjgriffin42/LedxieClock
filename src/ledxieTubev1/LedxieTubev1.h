#include "../ledxieDisplay/LedxieDisplay.h"
#include "../ledxieDisplay/Adafruit_NeoPixel.h"
#include "../ledxieTube/LedxieTube.h"

#define NUM_LEDS 11


class LedxieTubev1 : public LedxieTube
{
public:
	// constructor
	LedxieTubev1();
	~LedxieTubev1();

	// methods
	void setTubeRingPosition(int ring_position, int first_pixel_position);
	void setLEDStrip(Adafruit_NeoPixel led_strip);

	void setNumberToDisplay(int number);
	void setColorToDisplay(int color[3]);
	void setDisplayBrightness(int brightness);
	void tubeOff();

	void update();

	int getNumberOfLEDs();

private:
	// objects
	static int led_mapping[NUM_LEDS] = {2, 3, 4, 9, 1, 6, 0, 7, 5, 10, 8};
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
