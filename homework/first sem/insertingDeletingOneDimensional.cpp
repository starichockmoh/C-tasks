#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include <algorithm>



std::vector<int> CreateArray(int n) {//вспомогательная функция для создания массива
    std::vector<int> Array(n);
    std::cout << "Input array`s elements" << std::endl;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        Array[i] = tmp;
    }
    return Array;
}


void PrintArray(std::vector<int> Arr){//вспомогательная функция для вывода массива
    for (int & i : Arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


void task1(int n){
    std::vector<int> numbers = CreateArray(n);
    auto newEnd = std::remove_if(numbers.begin(), numbers.end(), [](int num) {
        return num < 0;// Фильтруем элементы, перемещая уцелевшие элементы в начало массива
    });
    numbers.erase(newEnd, numbers.end()); // Удаляем все элементы, следующие после
    PrintArray(numbers);
}

bool task6(int n, int x) {
    std::vector<int> numbers = CreateArray(n);//создаем массив
    auto newEnd = std::remove_if(numbers.begin(), numbers.end(), [&x](int num) {
        return abs(num) % 10 == x;// Фильтруем элементы, перемещая уцелевшие элементы в начало массива
    });
    numbers.erase(newEnd, numbers.end()); // Удаляем все элементы, следующие после
    PrintArray(numbers);//выводим массив
}

void task15(int n, int x){
    std::vector<int> a (2*n);//удваиваем кол-во элементов для запаса для сдвигов
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        a[i] = tmp;
        std::cout << a[i] << " ";
        if (a[i] == x) {
            for (int k = n; k > i; k--)//при условии делаем сдвиг элементов от i+1 до n вправо на один
                a[k] = a[k-1];
            a[i+1] = x; //вставляем после элемента значение
            n ++;//увеличим размер массива
            i ++;//перескочим на следущую i
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {//выведем итоговый массив
        std::cout << a[i] << " ";
    }
}

void task19(int n, int x, int y){
    std::vector<int> a (2*n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        a[i] = tmp;
        std::cout << a[i] << " ";
        if (a[i] == x) {
            for (int k = n; k > i; k--)
                a[k] = a[k-1];
            a[i] = y;//всё делаем аналогично за искл того что вставляем перед элементов значение а не после
            n ++;
            i ++;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
}

int main() {
    std::cout << "Choose task (1-4)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            std::cout << "Input array`s length" << std::endl;
            int n;
            std::cin >> n; //Вводим значение
            task1(n); //выполняем задачу
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task " << std::endl;
            std::cout << "Input array`s length" << std::endl;
            int n;
            std::cin >> n; //Вводим два значения
            std::cout << "Input x" << std::endl;
            int x;
            std::cin >> x; //Вводим два значения
            task6(n, x);
            break;
        };
        case 3: {
            std::cout << "3 task " << std::endl;
            std::cout << "Input array`s length" << std::endl;
            int n;
            std::cin >> n; //Вводим два значения
            std::cout << "Input x" << std::endl;
            int x;
            std::cin >> x; //Вводим два значения
            task15(n, x);
            break;
        };
        case 4: {
            std::cout << "4 task " << std::endl;
            std::cout << "Input array`s length" << std::endl;
            int n;
            std::cin >> n;
            std::cout << "Input x" << std::endl;
            int x;
            std::cin >> x;
            std::cout << "Input y" << std::endl;
            int y;
            std::cin >> y;
            task19(n, x, y);
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };

            return 0;
    }
}