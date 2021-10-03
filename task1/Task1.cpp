#include <iostream> //библиотека для потока ввода-вывода
#include <cmath> //библиотека математических функций
#include <vector> //библиотека позволяющая нам пользоваться динамическим массивом - вектором


float task1_2(float x, float y) {
    return x * y / 5 + sqrt((exp(x - 1) + exp(y - 1)) /
                            pow(cos(x + 2 * y), 2));// соблюдая порядок выполнения операций вернем нужное значение
}


double task1_10(int x, int y) {
    return sqrt(cos(exp(sqrt(y + x)) /
                    pow(sin(sqrt(x * x - y * y)), 2)));// соблюдая порядок выполнения операций вернем нужное значение. Заметим что так как значение косинуса
                    //может быть отрицательным и при этом оно стоит под корнем. Возможен ответ nan
}


std::vector<int> helper(int x) { // вспомогательная функция для нахождения цифр 3значного числа
    std::vector<int> arr(3); // реализуем вектор состоящий из трех int значений
    arr[0] = x % 10; //находим разряд единицы
    arr[1] = x / 10 % 10; // находим разряд десятка
    arr[2] = x / 100; // находим разряд сотни
    return arr;
}


std::vector<int> task1_14(int x) {
    std::vector<int> numbers = helper(
            x); // находим цифры числа, где numbers[2] - это первая цифра, numbers[1] - вторая, numbers[0] - третья
    int tmp = numbers[0] * numbers[1] * numbers[2]; // произведение цифр
    int tmp1 = numbers[0] + numbers[1] + numbers[2]; // сумма цифр
    int result = tmp % tmp1; // остаток от деления произведения на сумму
    int y = 100 * numbers[2] + 10 * numbers[0] + numbers[1]; // составим число y - поменяем местами десятки с единицами
    std::vector<int> res{result, y}; // реализуем вектор состоящий из остатка и искомого y
    return res;
}


int task1_16(int x) {
    std::vector<int> numbers = helper(x); // находим цифры числа, где numbers[2] - это первая цифра, numbers[1] - вторая, numbers[0] - третья
    int FirstNum = (numbers[1] + numbers[0]) % 10; //формируем превую цифру y
    int SecondNum = abs(numbers[2] - numbers[0]);  //формируем вторую цифру y
    int ThirdNum = numbers[1] % numbers[2]; //формируем третью цифру y
    return FirstNum * 100 + SecondNum * 10 + ThirdNum; //возвращаем y
}


int main() {
    std::cout << "Choose task (1-4)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            std::cout << "Input two numbers" << std::endl;
            float x, y;
            std::cin >> x >> y; //Вводим два значения
            std::cout << "First task: " << task1_2(x, y) << std::endl; //выполняем задачу
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task" << std::endl;
            std::cout << "Input two numbers (for example 120 2)" << std::endl;
            int x, y;
            std::cin >> x >> y;
            std::cout << "Second task: " << task1_10(x, y) << std::endl;
            break;
        };
        case 3: {
            std::cout << "3 task" << std::endl;
            std::cout << "Input number" << std::endl;
            int x;
            std::cin >> x;
            std::vector<int> result = task1_14(x);
            std::cout << "Third task ostatock: " << result[0] << std::endl;
            std::cout << "Third task Y: " << result[1] << std::endl;
            break;
        };
        case 4: {
            std::cout << "4 task" << std::endl;
            std::cout << "Input number" << std::endl;
            int x;
            std::cin >> x;
            std::cout << "Fourth task: " << task1_16(x) << std::endl;
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };
    }
    return 0;
}
