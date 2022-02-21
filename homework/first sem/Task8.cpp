#include <iostream>
#include <vector>


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


void PrintArray(std::vector<int> Array) {//вспомогательная функция для вывода массива
    for (int i: Array) {
        std::cout << i << " ";
    }
}


void task1(int n) {
    std::vector<int> Array = CreateArray(n+1);//создаем массив длиной n+1
    std::vector<int> Der(n); //будущий массив с производной
    for (int i = 0; i < n; ++i) {
        Der[i] = Array[i + 1] * (i + 1); //формируем производную по правилу (x^n)` = nx^n-1
    }
    PrintArray(Der);
}


void task6(int n, int A) {
    std::vector<int> Array = CreateArray(n+1);//создаем массив длиной n+1
    std::vector<int> Pr(n + 3);//будущий массив произведения
    for (int i = 0; i < n + 3; ++i) {//перемножаем элементы
        if (i == 0 || i == 1) {
            Pr[i] = Array[i] * (-A);//для степени 0 и 1, просто умножаем коэф на -A
        } else if (i < n+1) {
            Pr[i] = Array[i] * (-A) + Array[i - 2];//умножаем коэф на -A и еще прибавляем коэф при числе со степенью на 2 меньше (т к оно при умножении
            //на x^2 даст число в i степени
        } else {
            Pr[i] = Array[i - 2];// все те числа со степенью > n получаются при умножении последнего и предпоследенего элементов на x^2
        }
    }
    PrintArray(Pr);
}


int factorial(int n) { //вспомогательная рекурсивная функция для поиска факториала
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void task11(int n) {
    std::vector<int> Array(n + 1);
    for (int k = 0; k <= n; ++k) {
        Array[k] = factorial(n) / (factorial(n-k) * factorial(k));//по правилу бинома Ньютона формируем коэффициенты
    }
    PrintArray(Array);
}

int main() {
    std::cout << "Choose task (1-3)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            std::cout << "Input n" << std::endl;
            int n;
            std::cin >> n; //Вводим два значения
            task1(n); //выполняем задачу
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task " << std::endl;
            std::cout << "Input n" << std::endl;
            int n;
            std::cin >> n; //Вводим два значения
            std::cout << "Input A" << std::endl;
            int A;
            std::cin >> A; //Вводим два значения
            task6(n, A);
            break;
        };
        case 3: {
            std::cout << "3 task " << std::endl;
            std::cout << "Input n" << std::endl;
            int n;
            std::cin >> n;
            task11(n);
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };

            return 0;
    }
}