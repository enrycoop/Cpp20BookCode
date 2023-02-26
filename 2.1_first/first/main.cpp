
#include <iostream>
#include <limits>


int main() {

    //std::cout << "bits per bool: " << std::numeric_limits<bool>::digits << '\n';
    int min{std::numeric_limits<int>::max()};
    int max{std::numeric_limits<int>::min()};
    bool any{false};

    int x;
    while(std::cin >> x){
        any = true;
        if (x < min)
            min = x;
        if (x > max)
            max = x;
    }

    if (any)
        std::cout << "min = " << min << "\nmax = " << max << "\n";

    return 0;
}
