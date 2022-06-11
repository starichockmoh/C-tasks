#include <iostream>
#include <string>
#include <sstream>
#include <climits>
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
        int value = atoi(val.c_str());
        push(numbers_head, numbers_tail, value);
    }
    std::cout << numbers_head << '\n';

    // пройти по списку, удалить все четные
    List<int>* ptr = numbers_head;
    while (ptr != nullptr) {
        if (ptr->data % 2 == 0) {
            auto next = ptr->next;
            remove(numbers_head, numbers_tail, ptr);
            ptr = next;
        }
        else {
            ptr = ptr->next;
        }
    }

    // вывод измененного списка
    std::cout << "Result: ";
    std::cout << numbers_head << '\n';
}