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
        std::ranges::copy(std::ranges::istream_view<int>(in), std::back_inserter(data)); 
        in.close();
        std::ranges::sort(data);
        std::ranges::copy(data, std::ostream_iterator<int>{std::cout, " "});
        std::ofstream out{output};
        if (out) {
            std::ranges::copy(data, std::ostream_iterator<int>{out, " "});
            out.close();
        }
        if (not out)
            std::cerr << output << ": " << std::generic_category().message(errno) << '\n';
    }
}
