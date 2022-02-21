#include <iostream> //библиотека для потока ввода-вывода
#include <vector> //библиотека позволяющая нам пользоваться динамическим массивом - вектором
#include <time.h>

void task1(int n) {
    srand((unsigned int) time(0));
    std::vector<int> Arr(n);
    int Maximum = 0;
    for (int i = 0; i < n; ++i) {
        Arr[i] = rand() % 10;
        std::cout << Arr[i] << " ";
        if (Arr[i] > Maximum) Maximum = Arr[i];
    }
    std::cout << std::endl;
    std::cout << "Max: " << Maximum;
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        if (Arr[i] == Maximum) {
            Arr[i] = 0;
        }
        std::cout << Arr[i] << " ";
    }
}


int main () {
    std::cout << "Input number" << std::endl;
    int n;
    std::cin >> n;
    if (n / 1000 != 0 || n / 100 == 0 || n / 10 == 0) {
        std::cout << "input three-digit number!" << std::endl;
    } else {
        std::cout << task1(n) << std::endl;
    }
    return 0;
}