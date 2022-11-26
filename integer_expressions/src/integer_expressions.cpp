//============================================================================
// Name        : integer_expressions.cpp
// Author      : Enrycoop
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int main() {
	int sum{0};
	int count{};

	int x;
	while(std::cin >> x){
		if(x % 2 != 0)
			std::cout << "The number is even.\n";
		else
			std::cout << "The number is odd.\n";
		sum = sum + x;
		count = count + 1;
	}
	if(count != 0)
		std::cout << "average = " << sum / count << "\n";
	else
		std::cout << "No data.\n";

	return 0;
}
