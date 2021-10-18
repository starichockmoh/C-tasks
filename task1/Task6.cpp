#include <iostream> //библиотека для потока ввода-вывода
#include <cmath> //библиотека математических функций
#include <vector> //библиотека позволяющая нам пользоваться динамическим массивом - вектором
#include <time.h>


void task2(int n) {
    srand((unsigned int) time(0));
    std::vector<int> Arr(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        Arr[i] = rand() % 10;
        std::cout << Arr[i] << " ";
        if (i % 2 != 0 && Arr[i] % 2 != 0) {
            s += Arr[i];
        }
    }
    std::cout << std::endl;
    std::cout << "Sum: " << s;
}


void task6(int n, int x) {
    srand((unsigned int) time(0));
    std::vector<int> Arr(n);
    std::vector<int> ResultArr(n);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        Arr[i] = rand() % 10;
        std::cout << Arr[i] << " ";
        if (Arr[i] % x != 0) {
            ResultArr[j] = i;
            j += 1;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < j; ++i)
        std::cout << ResultArr[i] << " ";

}


void task12(int n) {
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
            Arr[i] = -Maximum;
        }
        std::cout << Arr[i] << " ";
    }
}


int task16(int n) {
    srand((unsigned int) time(0));
    std::vector<int> Arr(n);
    int Maximum = 0;
    int Minimum = 11;
    int MaxIndex= -1;
    int MinIndex = -1;
    for (int i = 0; i < n; ++i) {
        Arr[i] = rand() % 10;
        std::cout << Arr[i] << " ";
        if (Arr[i] > Maximum) {
            MaxIndex = i;
            Maximum = Arr[i];
        }
        if (Arr[i] < Minimum){
            MinIndex = i;
            Minimum = Arr[i];
        }
    }
    std::cout << std::endl;
    if (MaxIndex != -1 && MinIndex != -1) {
        std::swap(Arr[MaxIndex], Arr[MinIndex]);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << Arr[i] << " ";
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
            int n;
            std::cin >> n; //Вводим значение
            task2(n);//выполняем задачу
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task" << std::endl;
            int n, x;
            std::cout << "Input array`s length " << std::endl;
            std::cin >> n;
            std::cout << std::endl;
            std::cout << "Input x " << std::endl;
            std::cin >> x;
            std::cout << std::endl;
            task6(n, x);
            break;
        };
        case 3: {
            std::cout << "3 task" << std::endl;
            std::cout << "Input number" << std::endl;
            int n;
            std::cin >> n;
            task12(n);
            break;
        };
        case 4: {
            std::cout << "4 task" << std::endl;
            std::cout << "Input number" << std::endl;
            int n;
            std::cin >> n;
            task16(n);
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };
    }
    return 0;
}
