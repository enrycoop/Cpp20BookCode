//============================================================================
// Name        : arrays_and_vectors.cpp
// Author      : Enrycoop
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>

int main() {

	std::vector<int> data{};  // vettore vuoto
	int x{};

	//leggo interi
	while(std::cin >> x)
		data.emplace_back(x); //memorizza ogni intero nel vettore.


	std::ranges::sort(data);   // @suppress("Function cannot be resolved")


	for(int element : data)
		std::cout << element << '\n';

	return 0;
}
