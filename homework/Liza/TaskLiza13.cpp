#include <iostream>
#include <cmath>
int recursive (int n) {
    if (n == 1) {
        return 1;
    }
    return recursive(n / 2) + 1;
}

int main () {
    int n;
    std::cout << "Input n:" << std::endl;
    std::cin >> n;
    std::cout << recursive(n) << std::endl;
    if (std::pow(2, recursive(n) - 1) <= n && std::pow(2, recursive(n)) >= n) {
        std::cout << "The inequality is fulfilled" << std::endl;
    }
    return 0;
}