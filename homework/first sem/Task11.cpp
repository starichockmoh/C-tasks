#include <iostream>

int task1Rec(int n) {//рекуривная функция
    if (n == 1) {//если дошли до 1 то выходим из рекурсии
        return 1;
    }
    return n * task1Rec(n-1);
}

int task1 (int n) {//функция с циклом
    int pr = 1;
    for (int i = 2; i <= n; ++i) {
        pr *= i;
    }
    return pr;
}

int task9Rec (int n, int m) {//рекурсивня функция
    if (n == 0 || n == m) {//условия окончания рекурсии
        return 1;
    }
    return task9Rec(n-1, m-1) + task9Rec(n, m-1);//считаем по правилу биноминальные коэффициенты
}

int task9 (int n, int m) {//функция вычмсляющаяся по формуле сочетаний
    return task1Rec(m) / (task1Rec(m-n) * task1Rec(n));
}


void task13(int n) {
    if (n == 0) {//условие окончания рекурсии
        return;
    }
    task13(n / 2);//вызываем для числа поделенненого на 2
    std::cout << n % 2;//получаем цифры двоичного числа
}

void task16(int n, int constN) {//функция для первой половины
    if (n <= 0) return;//условие окончания рекурсии
    task16(n-2, constN);
    for (int i = 1; i <= constN; ++i) {
        if ((i <= (constN - n) / 2) || (i > (constN - n) / 2 + n)) std::cout << " ";//печатаем элементы
        else std::cout << n;
    }
    std::cout << std::endl;
}

void task16dop(int n, int constN) {//для второй половины
    if (n <= 0) return;//условие окончания рекурсии
    for (int i = 1; i <= constN; ++i) {
        if ((i <= (constN - n) / 2) || (i > (constN - n) / 2 + n)) std::cout << " ";
        else std::cout << n;
    }
    std::cout << std::endl;
    task16dop(n-2, constN);
}


int main() {
    std::cout << "Choose task (1-4)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            std::cout << "Input number" << std::endl;
            int n;
            std::cin >> n; //Вводим значение
            std::cout << task1Rec(n) << std::endl; //выполняем задачу
            std::cout << task1(n); //выполняем задачу
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task " << std::endl;
            std::cout << "Input n" << std::endl;
            int n;
            std::cin >> n; //Вводим два значения
            std::cout << "Input m (>= n)" << std::endl;
            int m;
            std::cin >> m;
            std::cout << task9(n, m) << std::endl;
            std::cout << task9Rec(n, m) << std::endl;
            break;
        };
        case 3: {
            std::cout << "3 task " << std::endl;
            std::cout << "Input number" << std::endl;
            int n;
            std::cin >> n;
            task13(n);
            break;
        };
        case 4: {
            std::cout << "4 task " << std::endl;
            std::cout << "Input number" << std::endl;
            int n;
            std::cin >> n;
            task16(n,n);
            task16dop(n,n);
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };

            return 0;
    }
}