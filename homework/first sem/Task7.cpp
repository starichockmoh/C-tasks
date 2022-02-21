#include <iostream>
#include <vector> //библиотека позволяющая нам пользоваться динамическим массивом - вектором
#include <time.h>

std::vector<std::vector<int>> CreateDoubleArray(int n) {//вспомогательная функция для создания двумерного массива
    srand((unsigned int) time(0));
    std::vector<std::vector<int>> Arr(n);//инициализируем матрицу
    for (int i = 0; i < n; ++i){ //далее заполнем двумерный массив
        Arr[i] = std::vector<int> (n);
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            Arr[i][j] = rand() % 10;
        }
    }
    return Arr;
}

void PrintArray(std::vector<std::vector<int>> Arr){//вспомогательная функция для вывода на экран двумерного массива
    for (int i = 0; i < Arr.size(); ++i){
        for (int j = 0; j < Arr.size(); ++j){
            std::cout << Arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void task2(int n) {
    std::vector<std::vector<int>> Arr = CreateDoubleArray(n); // создаем матрицу
    PrintArray(Arr); //печатаем ее
    for (int j = 1; j < n; j += 2){ //идем по столбам
        for (int i = 0; i < n; ++i){ // идем по строкам
            int tmp = Arr[i][j]; // далее меняем j элемент i строки на j-1 элемент i строки
            Arr[i][j] = Arr[i][j-1];
            Arr[i][j-1] = tmp;
        }
    }
    PrintArray(Arr);//печатаем новый массив
}


void task6 (int n) {
    std::vector<std::vector<int>> Arr = CreateDoubleArray(n); //создаем матрицу
    PrintArray(Arr); //печатаем ее
    int MaxElem = 0; // максимальный элемент
    int MinElem = 11; // минимальный элемент
    int MaxIndex = -1; // индекс макс элемента
    int MinIndex = -1; // индекс мин элемента
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){
            if (Arr[i][j] > MaxElem) {
                MaxElem = Arr[i][j]; //находим макс элемент и строку в которой он находится
                MaxIndex = i;
            }
            if (Arr[i][j] < MinElem) {//находим мин элемент и строку в которой он находится
                MinElem = Arr[i][j];
                MinIndex = i;
            }
        }
    }
    if (MinIndex != -1 && MaxIndex != -1) { // меняем местами строки
        std::vector<int> tmp = Arr[MaxIndex];
        Arr[MaxIndex] = Arr[MinIndex];
        Arr[MinIndex] = tmp;
    }
    PrintArray(Arr);
}


void task12 (int n) {
    std::vector<std::vector<int>> Arr = CreateDoubleArray(n); //создаем матрицу
    PrintArray(Arr); //печатаем ее
    int MaxElem = 0;// максимальный элемент
    int MinElem = 11;// минимальный элемент
    int MaxIndexI = -1; // индекс макс элемента
    int MaxIndexJ = -1;
    int MinIndexI = -1;// индекс мин элемента
    int MinIndexJ = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j < n - i) {// поиск по заштрихованной области включая границы
                if (Arr[i][j] > MaxElem) { // ищем макс элемент и его индексы
                    MaxElem = Arr[i][j];
                    MaxIndexI = i;
                    MaxIndexJ = j;
                }
            } else { // поиск по незаштрихованной области
                if (Arr[i][j] < MinElem) {// ищем мин элемент и его индексы
                    MinElem = Arr[i][j];
                    MinIndexI = i;
                    MinIndexJ = j;
                }
            }
        }
    }
    if (MaxIndexI != -1 && MinIndexI != -1 ) {
        int tmp = Arr[MaxIndexI][MaxIndexJ]; //меняем местами макс и мин элменты
        Arr[MaxIndexI][MaxIndexJ] = Arr[MinIndexI][MinIndexJ];
        Arr[MinIndexI][MinIndexJ] = tmp;
    }
    PrintArray(Arr);
}


void task16() {
    int n = 5;
    int StartElem = 24;
    std::vector<std::vector<int>> Arr(n); //создаем нулевую матрицу
    for (int i = 0; i < n; ++i){
        Arr[i] = std::vector<int> (n);
    }
    for (int i = 0; i < n; ++i){ //заполняем матрицу
        if (i % 2 == 0) { //если номер строки четный то идем справа налево
            for (int j = 0; j < n; ++j){
                Arr[i][j] = StartElem;
                --StartElem;
            }
        } else { // в противном случае идем слева направо
            for (int j = n-1; j >= 0; --j){
                Arr[i][j] = StartElem;
                --StartElem;
            }
        }

    }
    PrintArray(Arr);
}

int main() {
    std::cout << "Choose task (1-4)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            std::cout << "Input array length" << std::endl;
            int n;
            std::cin >> n; //Вводим два значения
            task2(n); //выполняем задачу
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task " << std::endl;
            std::cout << "Input array length" << std::endl;
            int n;
            std::cin >> n; //Вводим два значения
            task6(n); //выполняем задачу
            break;
        };
        case 3: {
            std::cout << "2 task " << std::endl;
            std::cout << "Input array length" << std::endl;
            int n;
            std::cin >> n; //Вводим два значения
            task12(n); //выполняем задачу
            break;
        };
        case 4: {
            task16();
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };
            return 0;
    }
}