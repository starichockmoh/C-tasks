#include <iostream> //библиотека для потока ввода-вывода


int main () {
    std::cout << "Input n" << std::endl;
    int n;
    std::cin >> n;
    double S = 0;
    for (int i = 1; i <= n; ++i) {
        S += 1 / double(i);
    }
    std::cout << S;
    return 0;
}