#include <iostream> //библиотека для потока ввода-вывода
#include <cmath> //библиотека математических функций


double f(double x) { //вспомогательная функция для подсчета значения
    return  std::log(x-2) / sqrt(5*x+1);
}

int main() {
    double A,B,H;
    std::cout << "Input A, B (A <= B), H: " << std::endl; //вводим диапозон и шаг h
    std::cin >> A >> B >> H;
    if (A > B) {
        std::cout << "Error: input A <= B";
        return 1;
    }
    for (double x = A; x <= B; x += H) { //идем по диапозону с шагом h
        if (x <= 2) { // если х не удолетв ОДЗ то пишем об этом (одз изза корня и логарифма)
            std::cout << "Does not take a value" << std::endl;
            continue; // переходим на новый х игнорируя что написано ниже
        }
        std::cout << f(x) << std::endl; //если х удолетв ОДЗ выводим значение функции
    }
    return 0;
}

