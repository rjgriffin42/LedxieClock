#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
	Color();

	static int Black();
	static int White();
	static int Red();
	static int Lime();
	static int Blue();
	static int Yellow();
	static int Cyan();
	static int Magenta();
	static int Silver();
	static int Gray();
	static int Maroon();
	static int Olive();
	static int Green();
	static int Purple();
	static int Teal();
	static int Navy();

	static int DarkRed();
	static int Brown();
	static int FireBrick();
	static int Crimson();
	static int Tomato();
	static int Coral();
	static int IndianRed();
	static int LightCoral();
	static int DarkSalmon();
	static int Salmon();
	static int LightSalmon();
	static int OrangeRed();
	static int DarkOrange();
	static int Orange();
	static int Gold();
};

static int Color::Black()
{
	int color[3] = {0, 0, 0};
	return color;
}

static int Color::White()
{
	int color[3] = {255, 255, 255};
	return color;
}

static int Color::Red()
{
	int color[3] = {255, 0, 0};
	return color;
}

static int Color::Lime()
{
	int color[3] = {0, 255, 0};
	return color;
}

static int Color::Blue()
{
	int color[3] = {0, 0, 255};
	return color;
}

static int Color::Yellow()
{
	int color[3] = {255, 255, 0};
	return color;
}

static int Color::Cyan()
{
	int color[3] = {0, 255, 255};
	return color;
}

static int Color::Magenta()
{
	int color[3] = {255, 0, 255};
	return color;
}

static int Color::Silver()
{
	int color[3] = {192, 192, 192};
	return color;
}

static int Color::Gray()
{
	int color[3] = {128, 128, 128};
	return color;
}

static int Color::Maroon()
{
	int color[3] = {128, 0, 0};
	return color;
}

static int Color::Olive()
{
	int color[3] = {128, 128, 0};
	return color;
}

static int Color::Green()
{
	int color[3] = {0, 128, 0};
	return color;
}

static int Color::Purple()
{
	int color[3] = {128, 0, 128};
	return color;
}

static int Color::Teal()
{
	int color[3] = {0, 128, 128};
	return color;
}

static int Color::Navy()
{
	int color[3] = {0, 0, 128};
	return color;
}

static int Color::DarkRed()
{
	int color[3] = {139, 0, 0};
	return color;
}

static int Color::Brown()
{
	int color[3] = {165, 42, 42};
	return color;
}

static int Color::FireBrick()
{
	int color[3] = {178, 34, 34};
	return color;
}

static int Color::Tomato()
{
	int color[3] = {255, 99, 71};
	return color;
}

static int Color::Coral()
{
	int color[3] = {255, 127, 80};
	return color;
}

static int Color::IndianRed()
{
	int color[3] = {205, 92, 92};
	return color;
}

static int Color::LightCoral()
{
	int color[3] = {240, 128, 128};
	return color;
}

static int Color::DarkSalmon()
{
	int color[3] = {233, 150, 122};
	return color;
}

static int Color::Salmon()
{
	int color[3] = {250, 128, 114};
	return color;
}

static int Color::LightSalmon()
{
	int color[3] = {255, 160, 122};
	return color;
}

static int Color::OrangeRed()
{
	int color[3] = {255, 69, 0};
	return color;
}

static int Color::DarkOrange()
{
	int color[3] = {255, 140, 0};
	return color;
}

static int Color::Orange()
{
	int color[3] = {255, 165, 0};
	return color;
}

static int Color::Gold()
{
	int color[3] = {255, 215, 0};
	return color;
}

#endif //COLOR_H
