#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <numeric>
#include <set>
#include <iostream>


template <class Container>
void PrintCont(const Container& c) {//Шаблонная функция для печати контейнера на экран
    for (auto it = c.begin(); it != c.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}


void task_1(std::vector<int> values) {
    std::cout << "values:";
    PrintCont(values);   //Печатаем значения использующиеся в задаче
    auto m = values.begin() + 4;// итератор на 5 элемент
    std::nth_element(values.begin(), m, values.end()); //перекидываем элементы меньше 5 влево а большие вправо
    std::cout << "result:" << std::endl;
    PrintCont(values); //Выводим результат
}


void task_2(std::list<int> values) {
    std::cout << "values:";
    PrintCont(values);  //Печатаем значения использующиеся в задаче
    auto max_value = std::max_element(values.begin(), values.end()); //Итератор на первый макс элемент
    std::rotate(values.begin(), max_value, values.end());  // Выполняем циклический сдвиг
    std::cout << "result:" << std::endl;
    PrintCont(values);  //Выводим результат
}

void task_3(std::vector<int> values) {
    std::cout << "values:";
    PrintCont(values);  //Печатаем значения использующиеся в задаче
    std::make_heap(values.begin(), values.end());  //Создаём кучу
    std::cout << "result:" << std::endl;
    PrintCont(values); //Выводим результат
}

void task_4(std::vector<int> values_1, std::vector<int> values_2) {
    std::cout << "first values:"; //Печатаем значения использующиеся в задаче
    PrintCont(values_1);
    std::cout << "second values:"; //Печатаем значения использующиеся в задаче
    PrintCont(values_2);
    int res = std::inner_product(values_1.begin(), values_1.end(), values_2.begin(),0); //считаем скалярное произведение
    std::cout << "result:" << res << std::endl;
}

void task_5(const std::string& s) {
    std::cout << "value:" << s << std::endl; //Печатаем значения использующиеся в задаче
    auto chars = std::set<char>(s.begin(), s.end());  //Создаем множество
    std::cout << "set: ";
    PrintCont(chars);  //Печатаем множество
    std::cout << "result:" << chars.size() << std::endl;  //Выводим результат
}

int main() {

    // объекты с инициализационными данными типа initializer_list, на основе которых будут созданы нужные в задаче контейнеры
    // будь то вектор или список

    std::initializer_list<int> values1 = {2, 7, 5, 8, 10, -3, 2, 1, 4, 3};
    std::initializer_list<int> values2 = {5, 1, 0, 4, 7, 4, 3, 0, -1, 2};
    std::string s = "qwertyytrewq";

    std::cout << "Task 1" << std::endl;
    task_1(values1);
    std::cout << std::endl;
    std::cout << "Task 2" << std::endl;
    task_2(values1);
    std::cout << std::endl;
    std::cout << "Task 3" << std::endl;
    task_3(values1);
    std::cout << std::endl;
    std::cout << "Task 4" << std::endl;
    task_4(values1, values2);
    std::cout << std::endl;
    std::cout << "Task 5" << std::endl;
    task_5(s);
}