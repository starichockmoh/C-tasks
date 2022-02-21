#include <iostream> //библиотека для потока ввода-вывода


int main() {
    int n;
    std::cout << "Input n " << std::endl; // вводим n
    std::cin >> n;
    int b = -1; // первый элемент пос-ти
    for (int i = 2; i <=n ; ++i) { // идем до n и вычисляем по формуле элемент
        b = 9 - 2 * b;
        std::cout << "b" << i << " = " << b << std::endl;
    }
    return 0;
}
