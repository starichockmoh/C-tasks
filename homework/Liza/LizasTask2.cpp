#include <iostream> //библиотека для потока ввода-вывода
#include <cmath>


int main () {
    std::cout << "Input k" << std::endl;
    int k;
    std::cin >> k;
    double S = 0;
    for (int n = 1; n <= k; ++n) {
        S += pow(-1, n+1) / double (n * n);
    }
    std::cout << S;
    return 0;
}