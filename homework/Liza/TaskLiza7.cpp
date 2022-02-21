#include <iostream> //библиотека для потока ввода-вывода
#include <cmath>


int main() {
    double A, B;
    std::cout << "Input A, B (A <= B): " << std::endl;
    std::cin >> A >> B; //вводим диапозон
    if (A > B) { //если диапозон некорректный выдаем ошибку
        std::cout << "Error: input A > B";
        return 1;
    }

    //Цикл for
    for (int i = ceil(A); i <= B; ++i) { //так как A и B могут быть вещественными округлим A вверх до целого числа
        if (i > 0) { //идем по целым по числам диапозона и если число положительное выводим его
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    //Цикл while
    int i = ceil(A);
    while (i <= B) {
        if (i > 0) { //идем по целым по числам диапозона и если число положительное выводим его
            std::cout << i << " ";
        }
        i++;
    }
    std::cout << std::endl;

    //Цикл do while
    int j = ceil(A);
    do {
        if (j > 0) { //идем по целым по числам диапозона и если число положительное выводим его
            std::cout << j << " ";
        }
        j++;
    } while (j <= B);

    return 0;
}