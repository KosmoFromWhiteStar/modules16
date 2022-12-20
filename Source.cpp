#include <iostream>
#include <stdio.h>
#include <string.h>

bool shit(char* str, char* str_2)
{
	float value_1 = std::atof(str);
	float value_2 = std::atof(str_2);

	if (value_1 <= value_2)return true;
	else return false;

}


bool compare(float value, float reference, float epsilon)
{
	return (value >= reference - epsilon) && (value <= reference + epsilon);
}

int main()
{
	float speed = 0.0f;
	float temp = speed;
	float temp_2 = 0.f;
	char pole[6];
	char spd_str[50] = "";
	do
	{
		std::cout << "Speed: " << spd_str << " mp\\h\n";
		std::cin >> pole;
		temp = std::atof(pole);
		temp_2 = speed + temp;
		std::sprintf(spd_str, "%.01f", temp_2);

		if (shit(spd_str, "150.0")) speed += temp;
		else
		{
			std::cout << "Max speed 150 mp\\h\n";
			std::sprintf(spd_str, "%.01f", speed);
		}

		if (compare(speed, .0f, 0.01f)) {
			speed = 0;
		}

	} while (true);
	return 0;
}