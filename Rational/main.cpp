#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "rational.hpp"

std::string isTrue(bool b) {
	if (b) return "true";
	return "false";
}

int main() {
	

	Rational a;
	Rational b;
	
	
	std::cout << "Enter a rational number (int)/(int): ";
	std::cin >> a;
	std::cout << std::endl << "Enter a second rational number in the same format: ";
	std::cin >> b;
	std::cout << std::endl;
	
	std::cout << "a = " << a << ", " << "b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << "Addition: " << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << std::endl;
	std::cout << "Substraction: " << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << std::endl;
	std::cout << "Multiplication: " << std::endl;;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << std::endl;
	std::cout << "Division: " << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << std::endl;

	std::cout << "User input a to float = " << static_cast<float>(a) << std::endl;
	std::cout << std::setprecision(17);
	std::cout << "User input a to double = " << static_cast<double>(a) << std::endl;

	std::cout << std::endl;	
	std::cout << "Logical Operators" << std::endl;
	std::cout << "a <  b: " << isTrue(a < b) << std::endl;
	std::cout << "a <= b: " << isTrue(a <= b) << std::endl;
	std::cout << "a >  b: " << isTrue(a > b) << std::endl;
	std::cout << "a >= b: " << isTrue(a >= b) << std::endl;
	std::cout << "a == b: " << isTrue(a == b) << std::endl;
	std::cout << "a != b: " << isTrue(a != b) << std::endl;
	
	std::cout << std::endl;
	std::cout << "Example of plus equals: " << std::endl;
	a += b;
	std:: cout << "a += b = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "Example of minus equals: " << std::endl;
	a -= b;
	std::cout << "a -= b = " << a << std::endl;
	std::cout << std::endl;


	std::cout << "Example of times equals: " << std::endl;
	a *= b;
	std::cout << "a *= b = " << a << std::endl;
	std::cout << std::endl;


	std::cout << "Example of divide equals: " << std:: endl;
	a /= b;
	std:: cout << "a /= b " << a << std::endl;
	std::cout << std::endl;



	return EXIT_SUCCESS;
}
