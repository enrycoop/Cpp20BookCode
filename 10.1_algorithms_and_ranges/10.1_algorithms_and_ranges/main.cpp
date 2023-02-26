//============================================================================
// Name        : algorithms_ranges.cpp
// Author      : Enrycoop
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> input{ 10, 20, 30 };
    vector<int> output{};

    output.resize(input.size());

    ranges::copy(input, output.begin());

    assert(input == output);

    return 0;
}
