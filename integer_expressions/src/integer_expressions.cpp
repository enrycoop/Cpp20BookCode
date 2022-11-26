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
		sum = sum + x;
		count = count + 1;
	}

	std::cout << "average = " << sum / count << "\n";

	return 0;
}
