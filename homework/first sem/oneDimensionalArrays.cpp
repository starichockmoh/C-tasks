#include <iostream> //библиотека для потока ввода-вывода
#include <cmath> //библиотека математических функций
#include <vector> //библиотека позволяющая нам пользоваться динамическим массивом - вектором
#include <time.h>


void task2(int n) {
    srand((unsigned int)time(0));// инициализируем время
    std::vector<int> Arr(n);//создаем вектор
    int s = 0;//сумма элементов
    for (int i = 0; i < n; ++i) {
        Arr[i] = rand() % 10; //создаем рандомный элемент
        std::cout << Arr[i] << " ";
        if (i % 2 != 0 && Arr[i] % 2 != 0) { //если номер не кратен 2 и сам элемент не кратен 2, то прибавим его к сумме
            s += Arr[i];
        }
    }
    std::cout << std::endl;
    std::cout << "Sum: " << s;
}


void task6(int n, int x) {
    srand((unsigned int)time(0));// инициализируем время
    std::vector<int> Arr(n);//создаем вектор
    std::vector<int> ResultArr(n);//создаем вектор с результатами
    int j = 0;
    for (int i = 0; i < n; ++i) {
        Arr[i] = rand() % 10;//создаем рандомный элемент
        std::cout << Arr[i] << " ";
        if (Arr[i] % x != 0) { //если элемент не кратен x, добавим в массив его, увеличим счетчик
            ResultArr[j] = i;
            j += 1;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < j; ++i)//выводим результат
        std::cout << ResultArr[i] << " "; 

}


void task12(int n) {
    srand((unsigned int)time(0));// инициализируем время
    std::vector<int> Arr(n);//создаем вектор
    int Maximum = 0;//будущее значение максимума
    for (int i = 0; i < n; ++i) {
        Arr[i] = rand() % 10;//создаем рандомный элемент
        std::cout << Arr[i] << " ";
        if (Arr[i] > Maximum) Maximum = Arr[i];//находим максимальный элемент 
    }
    std::cout << std::endl;
    std::cout << "Max: " << Maximum;
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        if (Arr[i] == Maximum) {//все элементы равные максимуму заменяем на противоположные 
            Arr[i] = -Maximum;
        }
        std::cout << Arr[i] << " ";
    }
}


void task16(int n) {
    srand((unsigned int)time(0));
    std::vector<int> Arr(n);
    int Maximum = 0; //максимальное значение 
    int Minimum = 11;//минимальное значение
    int MaxIndex = -1; //индекс максимального элемента
    int MinIndex = -1; //индекс минимального элемента 
    for (int i = 0; i < n; ++i) {
        Arr[i] = rand() % 10; //создаем рандомный элемент
        std::cout << Arr[i] << " ";
        if (Arr[i] > Maximum) {//находим максимальный элемент и его индекс
            MaxIndex = i;
            Maximum = Arr[i];
        }
        if (Arr[i] < Minimum) {// аналгично с минимальным
            MinIndex = i;
            Minimum = Arr[i];
        }
    }
    std::cout << std::endl;
    if (MaxIndex != -1 && MinIndex != -1) { //если нашлись то меняем местами
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
        std::cout << "Input array`s length " << std::endl;
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
        std::cout << "Input array`s length " << std::endl;
        int n;
        std::cin >> n;
        task12(n);
        break;
    };
    case 4: {
        std::cout << "4 task" << std::endl;
        std::cout << "Input array`s length " << std::endl;
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