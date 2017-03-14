#include "../ledxieTube/LedxieTube.cpp"

class LedxieDisplay
{
public:
	LedxieDisplay(int number_of_tubes, int pin);

private:
	Adafruit_NeoPixel pixels;
	LedxieTube* tubes;
};
