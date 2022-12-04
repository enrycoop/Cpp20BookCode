//============================================================================
// Name        : strings.cpp
// Author      : Enrycoop
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

int main() {
	//std::string shape; //automatically init to ""
	//
	int sides{};

	std::cout << "Shape\t\tSides\n" << "-----\t\t-----\n";
	std::cout << "Square\t\t" << 4 << '\n' <<
			"Circle\t\t?\n" //lacks a << operator, the compiler combines them automatically (only to strings)
			"Triangle\t" << 3 <<'\n';

	//std::cout << shape << '\t' << sides << '\n';
	return 0;
}
