#include <iostream>
#include <string>

int main() {
	std::string ind = "";
	std::string after_point = "";
	double result = 0.0f;
	std::cout << "Ex2";
	std::cout << "Input integer: ";
	std::cin >> ind;
	std::cout << "Input num after point: ";
	std::cin >> after_point;
	ind += '.';
	ind += after_point;
	result = std::stod(ind);
	std::cout << result;

}