#include <iostream> //библиотека для потока ввода-вывода


int main() {
    double A,B;
    std::cout << "Input A, B (A <= B): " << std::endl;
    std::cin >> A >> B; //вводим диапозон
    if (A > B) { //если диапозон некорректный выдаем ошибку
        std::cout << "Error: input A > B";
        return 1;
    }
    for (int i = int(A) + 1; i <= B; ++i){ //так как A и B могут быть вещественными округлим A вверх до целого числа
        if (i > 0) { //идем по целым по числам диапозона и если число положительное выводим его
            std::cout << i << " ";
        }
    }
    return 0;
}