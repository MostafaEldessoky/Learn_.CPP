#include <iostream>

enum class Colors {
	red = 10,
	green = 20,
	blue = 30
};

std::ostream& operator<<(std::ostream& io,Colors colors) {
	switch (colors) {
	case Colors::red :
		io << "Red" << std::endl;
		io << (int)colors; // Explicitly cast to int for output
		break;
	case Colors::green :
		io << "Green";
		io << (int)colors; // Explicitly cast to int for output
		break;
	case Colors::blue :
		io << "Blue";
		io << (int)colors; // Explicitly cast to int for output
		break;
	default :
		io << "Unknown Color";
		break;
	}
	return io;
}


int main() {

	std::cout << Colors::red << std::endl;


	int colorValue = (int)(Colors::green);
	//int colorValue = Colors::green; // This line will cause a compilation error because Colors::green is not implicitly convertible to int
	std::cout << "Color value as int: " << colorValue << std::endl;


	Colors color = Colors::blue;
	std::cout << "Color value: " << color << std::endl;
	std::cout << "Color value: " << (int)color << std::endl;


	return 0;
}	