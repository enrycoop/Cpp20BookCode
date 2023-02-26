/*
 Questo algoritmo non può essere compilato con questa versione del CLang di Apple
 Quindi al momento bisogna trovare altre alternative.
 */

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
