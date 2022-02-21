#include <iostream> //библиотека для потока ввода-вывода
#include <vector> //библиотека позволяющая нам пользоваться динамическим массивом - вектором

#define _USE_MATH_DEFINES //определяем математические константы

#include <cmath> // библиотека для математических операций

bool helper(int x) { //реализуем функцию проверки числа на простату
    for (int j = 2; j * j <= x; j += 1) { // перебираем возможные делители от 2 до корня из числа
        if (x % j == 0) return false; // если делитель нашелся - число не простое
    }
    return true;
}


int task2(int n) {
    int k = 1; // счетчик чисел (начинается с 1, т к 2 - простое число)
    int i = 3; //числа, которые мы проверяем
    std::cout << 2 << std::endl; //2 - простое
    while (k < n) { // пока счетчик не сравняется с n
        if (helper(i)) { // проверяем число на простату
            std::cout << i << std::endl; // если простое то выводим на экран и увеличим счетчик
            k += 1;
        }
        i += 2; //увеличим число
    }
}


void task6(int a, int b) { //a/b
    int p = 0; //частное
    int q = 0; // остаток
    while (a >= b) { // пока a больше b отнимаем от него b, и при каждом вычитании прибавляем к частному единицу
        a = a - b;
        p += 1;
    }
    q = a; // остаток - это то что останется от а в результате вычитания
    std::cout << p << std::endl;
    std::cout << q << std::endl;
}


void task11(float a, float b, int h) {
    for (a; a <= b; a += h){ //идем от a до b включительно с шагом h
        if (a <= 4) { //2x - 8 > 0, так как под логарифмом
            std::cout << "The logarithm of a non-positive number" << std::endl;
            continue;
        } else if (a > -1 && a < 1) { // x^2 - 1 >= 0 так как под корнем
            std::cout << "The root of a negative number" << std::endl;
            continue;
        } else if (2 * a == 9) { // ln = 0 при 2*x - 8 = 1
            std::cout << "Division by zero" << std::endl;
            continue;
        }
        float result = sqrt(a*a - 1) / log(2 * a - 8); //если значение попало в ОДЗ, считаем выражение
        std::cout << result << std::endl;
    }


}


void task16() {
    std::cout << 1 << std::endl;
    std::cout << 2 << std::endl;
    for (int i = 2; i <= 4; i += 1) { // заметим что количество чисел в строке зависит от значений чисел. Если это 2 то 2 числа, 3 - 3 числа и тд.
        // а после каждого числа идет число умноженное на 2
        for (int j = 1; j <= i; j += 1) {
            std::cout << i << ' ';
        }
        std::cout << "\n";
        for (int j = 1; j <= i; j += 1) {
            std::cout << i*2 << ' ';
        }
        std::cout << "\n";
    }
}


int main() {
    std::cout << "Choose task (1-4)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            std::cout << "Input number" << std::endl;
            int x;
            std::cin >> x; //Вводим значение
            task2(x); //выполняем задачу
            break;
        }
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task" << std::endl;
            std::cout << "Input number" << std::endl;
            int x, y;
            std::cin >> x >> y;
            task6(x, y);
            break;
        }
        case 3: {
            std::cout << "3 task" << std::endl;
            float a, b;
            int h;
            std::cout << "Input [a,b] and h" << std::endl;
            std::cout << "a:" << std::endl;
            std::cin >> a;
            std::cout << "b:" << std::endl;
            std::cin >> b;
            std::cout << "h:" << std::endl;
            std::cin >> h;
            task11(a,b,h);
            break;
        }
        case 4: {
            std::cout << "4 task" << std::endl;
            task16();
            break;
        }
        default: {
            std::cout << "Wrong number of task!";
            break;
        }
    }
    return 0;
}