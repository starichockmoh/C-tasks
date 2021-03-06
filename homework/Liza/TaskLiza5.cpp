#include <iostream> //библиотека для потока ввода-вывода
#include <cmath> //библиотека математических функций

int main() {
    double e;
    std::cout << "Input e " << std::endl;//e определяет точность вычисления (т е мы вычисляем до тех пор пока очередной
    std::cin >> e;// элемент не станет меньше по модулю чем е (например e = 0.0001))
    int N = 10000; //максимальное количество итераций в цикле (на всякий случай, чтобы не зациклилось)
    double a = 1; //первый элемент ряда
    double S = a; // сумма ряда
    int count = 1; // количество просуммированных слагаемых
    int num = 1; // номер х
    for (double x = 0.2; x <= 0.7; x += 0.1) { //идем по диапозону х
        for (int i = 1; (i < N) && std::abs(a) > e; i++) { // делаем N раз или пока a не станет меньше по модулю чем е
            a = std::pow(-1, i) * pow(x, 2*i) / (i*(i+2)*(i+3)); // формируем очередной элемент ряда
            S += a; // прибавляем элемент к сумме
            count += 1; // увеличиваем счетчик
        }
        std::cout << "N: " << num << " " << x << " " <<  S << " " << count << std::endl; // выводим полученные значения
        num += 1;
        count = 1; // заново определяем счетчик, сумму и элемент
        a = 1;
        S = a;
    }
    return 0;
}
