#include <iostream>
bool stop_()
{
	std::string answere;
	std::cout << "Stop machine? (yes\\no)";
	std::cin >> answere;
	if (answere == "yes" || answere == "Yes" || answere == "YES") return true;
	else if (answere == "no" || answere == "No" || answere == "NO") return false;
}
bool compare(float value, float reference, float epsilon)
{
	return (value >= reference - epsilon) && (value <= reference + epsilon);
}

int main_1()
{
	float speed = 0.0f;
	float temp = speed;
	char pole[6];
	char spd_str[5];
	do
	{
		//sprintf(spd_str, "%.1f", speed);
		std::cout << "Speed: " << spd_str << " mp\\h\n";
		std::cin >> pole;
		temp = std::atof(pole);
		if (speed + temp <= 150.0f)speed += temp;
		else {
			std::cout << "Max speed 150 mp\\h\n";
		}

		if (compare(speed, .0f, 0.01f)) {
			if (stop_()) break;
			speed = 0;
		}


	} while (true);
	return 0;
}