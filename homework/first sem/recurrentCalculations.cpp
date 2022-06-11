#include <iostream> //библиотека для потока ввода-вывода


void task1(int n) {
    double y1 = 0.5; //иницмализируем первый элемент
    double y2 = 0.4;// второй
    double a; //вспомогательная переменная
    if (n >= 1) std::cout << 1 << ' ' << y1 << std::endl;// пользователь может ввести 1
    if (n>=2) std::cout << 2 << ' ' << y2 << std::endl;
    for (int i = 3; i <= n; i += 1) {//выполняем рекурентные операции n раз
        a = y2;//записываем в а n-1 элемент
        y2 = 0.5 * y2 + y1 / 3; //вычисляем n элемент
        y1 = a;//n-2 элементу отдаем значение n-1 элемента
        std::cout << i << ' ' << y2 << std::endl;
    }


}



void task6(double x, double eps) {
    int N = 100; //делаем операцию 100 раз (должно хватить для точного результата)
    double a = 1; //элемент соотношений
    double S = a;// сумма элементов
    for (int i = 1; a > eps && i < N; i++){ // делаем сто раз или пока a не станет меньше некого эпсилион, который мы принимаем
        a *= x / i;// an = d * an-1
        S += a;
        std::cout << S << std::endl;
    }
}


void task12(double x, double eps) {
    int N = 100;//делаем операцию 100 раз (должно хватить для точного результата)
    double a = x;//элемент соотношений
    double S = a;// сумма элементов
    for (int i = 1; (i < N) && ((a > eps) || (a < -eps)); i++){// делаем сто раз или пока a не станет меньше по модулю
        // некого эпсилион, который мы принимаем
        a *= (-x*x / ((2 * i + 1) *  (2 * i))); // an = d * an-1
        std::cout << "a : " << a << std::endl;
        S += a;
        std::cout << "S : " << S << std::endl;
    }
}



int main() {
    std::cout << "Choose task (1-3)" << std::endl;
    int task;
    std::cin >> task;
    switch (task) {
        case 1:
            int n;
            std::cout << "Print n" << std::endl;
            std::cin >> n;
            task1(n);
            break;
        case 2:
            double x;
            double eps;
            std::cout << "Enter x" << std::endl;
            std::cin >> x;
            std::cout << "Enter eps" << std::endl;
            std::cin >> eps;
            task6(x, eps);
            break;
        case 3:
            std::cout << "Enter x" << std::endl;
            std::cin >> x;
            std::cout << "Enter eps" << std::endl;
            std::cin >> eps;
            task12(x, eps);
            break;
        default:
            std::cout << "Wrong number";
    }
    return 0;
}