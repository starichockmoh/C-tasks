#include <iostream> //библиотека для потока ввода-вывода
#include <cmath> //библиотека математических функций
#include <vector> //библиотека позволяющая нам пользоваться динамическим массивом - вектором
#include <time.h>


std::vector<std::vector<int>> CreateDoubleArray(int n) {//вспомогательная функция для создания двумерного массива
    srand((unsigned int) time(0));
    std::vector<std::vector<int>> Arr(n);//инициализируем матрицу
    for (int i = 0; i < n; ++i) { //далее заполнем двумерный массив
        Arr[i] = std::vector<int>(n);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Arr[i][j] = rand() % 10;
        }
    }
    return Arr;
}

void PrintArray(std::vector<std::vector<int>> Arr) {//вспомогательная функция для вывода на экран двумерного массива
    for (int i = 0; i < Arr.size(); ++i) {
        for (int j = 0; j < Arr.size(); ++j) {
            std::cout << Arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void task1(int n, int a, int b) {
    srand((unsigned int) time(0));
    std::vector<int> Arr(n);
    for (int i = 0; i < n; ++i) {
        Arr[i] = rand() % 10;
        std::cout << Arr[i] << " ";
        if (Arr[i] <= b && Arr[i] >= a) {
            Arr[i] = 0;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::vector<std::vector<int>> DArr = CreateDoubleArray(n);
    PrintArray(DArr);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (DArr[i][j] <= b && DArr[i][j] >= a) {
                DArr[i][j] = 0;
            }
        }
    }
    PrintArray(DArr);
}



void task2(int n) {
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
            Arr[i] = 0;
        }
        std::cout << Arr[i] << " ";
    }
}


void task3(int n) {
    std::vector<std::vector<int>> DArr = CreateDoubleArray(n);
    PrintArray(DArr);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += DArr[i][n-i-1];
    }
    std::cout << s << std::endl;
}

void task4(int n) {
    std::vector<std::vector<int>> DArr = CreateDoubleArray(n);
    PrintArray(DArr);
    std::vector<int> Line (n);//будущий вектор x
    std::cout << "Print column: " << std::endl;
    for (int i = 0; i < n; ++i){//формируем этот столбец
        int tmp;
        std::cin >> tmp;
        Line[i] = tmp;
    }
    for (int j = 0; j < n; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                DArr[i][j] = Line[i];
            }
        }
    }
    std::cout << std::endl;
    PrintArray(DArr);
}


int main() {
    std::cout << "Choose task (1-4)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            std::cout << "Input number" << std::endl;
            int n, a, b;
            std::cin >> n; //Вводим значение
            std::cout << "Input a, b" << std::endl;
            std::cin >> a >> b;
            task1(n, a, b);//выполняем задачу
            break;
        };
        case 2: {
            std::cout << "3 task" << std::endl;
            std::cout << "Input number" << std::endl;
            int n;
            std::cin >> n;
            task2(n);
            break;
        };
        case 3: {
            std::cout << "4 task" << std::endl;
            std::cout << "Input number" << std::endl;
            int n;
            std::cin >> n;
            task3(n);
            break;
        };
        case 4:{
            std::cout << "5 task" << std::endl;
            std::cout << "Input number" << std::endl;
            int n;
            std::cin >> n;
            task4(n);
            break;
        }
        default: {
            std::cout << "Wrong number of task!";
            break;
        };
    }
    return 0;
}
