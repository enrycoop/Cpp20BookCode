
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>


int main() {
    
    using namespace std;
    int x{42};
    
    cout << "x   = " << x << "\n";
    cout << "++x = " << ++x << "\n";
    cout << "x   = " << x << "\n";
    cout << "x++ = " << x++ << "\n";
    cout << "x   = " << x << "\n";
    return 0;
}
