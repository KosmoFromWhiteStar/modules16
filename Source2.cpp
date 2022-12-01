#include <iostream>
#include <iosfwd>
#include <string>
#include <sstream>


int main() {
	std::string str;
	double a, b;
	char operate;

	std::cin >> str;	
	std::stringstream str_stream; 
	str_stream << str;
	str_stream >> a >> operate >> b;
	if (operate == '+') a += b;
	if (operate == '-') a -= b;
	if (operate == '*') a *= b;
	if (operate == '/') a /= b;
	std::cout << "Result: " << a << std::endl;
}