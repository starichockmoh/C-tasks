#include <iostream>
#include <string>
#include <sstream>
#include "list.hpp"

int main() {
    // ввод чисел и инициализация значений списка
    List<int>* numbers_head = nullptr;
    List<int>* numbers_tail = nullptr;
    std::cout << "Enter a few integer numbers in one line: ";
    std::string input;
    std::getline(std::cin, input);
    std::stringstream input_stream(input);
    std::string val;
    // заполнить список
    while (input_stream >> val) {
        push(numbers_head, numbers_tail, atoi(val.c_str()));
    }
    std::cout << numbers_head << '\n';

    // сортировка вставками
    for (auto ptr = numbers_head->next; ptr != nullptr; ptr = ptr->next) {
        auto ptr2 = ptr;
        while (ptr2 != numbers_head && ptr2->data < ptr2->prev->data) {
            int x = ptr2->prev->data;
            remove(numbers_head, numbers_tail, ptr2->prev);
            insert(numbers_head, numbers_tail, ptr2, x);
        }
    }

    // вывод результата
    std::cout << "Result: ";
    std::cout << numbers_head << '\n';
}
