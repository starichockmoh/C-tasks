#include <iostream> //библиотека для потока ввода-вывода
#include <string.h>//библиотека для работы со строками


int taskBit_1(int i) {
    return 1 << i; // используем операцию сдвига влево. В данном случае 1 сдвинется на i битов влево, в результате чего мы
    //получим число 10...0 (кол-во нулей равно i). А это равносильно возведению в степень i.
}


int taskBit_2(int i, int n) {
    return (1 << i) | n; // для того чтобы заменить в числе n i-товый бит на 1, мы возьмем число 2^i и применим побитовую дезъюнкцию с числом n,
    //тем самым сохраним все биты числа n (т к 0 | 0 = 0, а 1 | 0 = 1), а i-товый бит будет равен 1 (1 | 1 = 1, 0 | 1 = 1).
}


int taskBit_3(int i, int n) {
    return ~(1 << i) & n; // для того чтобы заменить в числе n i-товый бит на 0, мы возьмем число 2^i, инвертируем в нем все биты (получится число
    //типа 011...111, где кол-во единиц равно i) и применим побитовую конъюкцию с числом n,
    //тем самым сохраним все биты числа n (т к 0 & 1 = 0, а 1 & 1 = 1), а i-товый бит будет равен 0 (1 & 0 = 0, 0 & 0 = 0).
}


int taskBit_4(int i, int n) {
    return (1 << i) ^ n; // для того чтобы заменить в числе n i-товый бит на противоположный (1 на 0 или 0 на 1),
    //мы возьмем число 2^i и применим строгую дизъюнкцию с числом n,
    //тем самым сохраним все биты числа n (т к 0 ^ 0 = 0, а 1 ^ 0 = 1), а i-товый бит будет равен 'противоположному' биту (1 ^ 1 = 0, 0 ^ 1 = 1).
}


std::string taskBit_5(int n) {
    if ((n & 1) == 0) {
        return "even";
    } else {
        return "not even";
    } // для того чтобы проверить число на четность, мы применим к нему побитовую конъюкцию с числом 1.
    //как известно число в двоичной записи четно, если оканчивается на 0. В случае конъюкции с единицой четного числа мы получим 0,
    // так как 0 & 1 = 0, а нечетного -  1, так как 1 & 1 = 1.
}

int main () {
    std::cout << "Choose task (1-5)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача
            std::cout << "1 task " << std::endl;
            int i;
            std::cout << "i: ";
            std::cin >> i;
            std::cout << "First task: " << taskBit_1(i);
            break;
        }
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task" << std::endl;
            int i, n;
            std::cout << "i: " << std::endl;
            std::cin >> i;
            std::cout << "n: " << std::endl;
            std::cin >> n;
            std::cout << "Second task: " << taskBit_2(i, n) << std::endl;
            break;
        }
        case 3: {
            std::cout << "3 task" << std::endl;
            int i, n;
            std::cout << "i: " << std::endl;
            std::cin >> i;
            std::cout << "n: " << std::endl;
            std::cin >> n;
            std::cout << "Third task: " << taskBit_3(i, n) << std::endl;
            break;
        }
        case 4: {
            std::cout << "4 task" << std::endl;
            int i, n;
            std::cout << "i: " << std::endl;
            std::cin >> i;
            std::cout << "n: " << std::endl;
            std::cin >> n;
            std::cout << "Fourth task: " << taskBit_4(i, n) << std::endl;
            break;
        }
        case 5: {
            std::cout << "5 task" << std::endl;
            int n;
            std::cout << "i: ";
            std::cin >> n;
            std::cout << "Fifth task: " << taskBit_5(n);
            break;
        }
        default: {
            std::cout << "Wrong number of task!";
            break;
        }
    }
    return 0;
}