//============================================================================
// Name        : output_iterators.cpp
// Author      : Enrycoop
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main() {
	
	std::vector<int> data;
	std::ranges::copy(std::ranges::istream_view<int>(std::cin), std::back_inserter(data)); // @suppress("Symbol is not resolved") @suppress("Invalid arguments")
	std::ranges::sort(data);
	std::ranges::copy(data, std::ostream_iterator<int>{std::cout, " \n"});
	return 0;
}
