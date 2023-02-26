//
//  main.cpp
//  7.1_more_loops
//
//  Created by Sergio Enrico Coppolecchia on 22/02/23.
//

#include <iostream>

int main() {
    std::cout << '+';
    for (int i{0}; i != 20; ++i)
        std::cout << '-';
    std::cout << "+\n";
    
    for (int i{0}; i != 10; i++)
        std::cout << i << ' ';
    
    return 0;
}
