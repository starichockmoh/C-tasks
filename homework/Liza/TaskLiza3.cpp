#include <iostream> //библиотека для потока ввода-вывода
#include <cmath> //библиотека математических функций


double f(double x) {//вспомогательная функция для подсчета значения
    if (x == 1 || x == -1) {
        return 1;
    }
    else if (x >= 0) {
        return -1 / (1-x);
    }
    else if (x < 0) {
        return 1/(1+x);
    }
}


int main() {
    double A,B,H;
    std::cout << "Input A, B (A <= B), H: " << std::endl;//вводим диапозон и шаг h
    std::cin >> A >> B >> H;
    if (A > B) {
        std::cout << "Error: input A <= B";
        return 1;
    }
    for (double x = A; x <= B; x += H) {//идем по диапозону с шагом h
        std::cout << "f(" << x << ") = " << f(x) << std::endl; //выводим значение функции
    }
    return 0;
}

