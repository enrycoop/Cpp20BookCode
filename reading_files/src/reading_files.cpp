//============================================================================
// Name        : reading_files.cpp
// Author      : Enrycoop
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cerrno>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <system_error>
#include <vector>

int main() {
	std::string input{"test_file.txt"};
	std::string output{"test_output.txt"};
	std::ifstream in{input};
	if (not in)
		std::cerr << input << ": " << std::generic_category().message(errno) << '\n';
	else
	{
		std::vector<int> data{};
		std::ranges::copy(std::ranges::istream_view<int>(in), std::back_inserter(data)); // @suppress("Function cannot be resolved") // @suppress("Symbol is not resolved")
		in.close();
		std::ranges::sort(data); // @suppress("Function cannot be resolved")
		std::ranges::copy(data, std::ostream_iterator<int>{std::cout, " "}); // @suppress("Function cannot be resolved")
		std::ofstream out{output};
		if (out) {
			std::ranges::copy(data, std::ostream_iterator<int>{out, " "}); // @suppress("Function cannot be resolved")
			out.close();
		}
		if (not out)
			std::cerr << output << ": " << std::generic_category().message(errno) << '\n';
	}
}
