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
    // заполнить список, одновременно находя максимальный элемент
    List<int>* max_elem = nullptr;
    while (input_stream >> val) {
        int value = atoi(val.c_str());
        push(numbers_head, numbers_tail, value);
        if (max_elem != nullptr) {
            max_elem = max_elem->data < numbers_tail->data ? numbers_tail : max_elem;
        }
        else {
            max_elem = numbers_tail;
        }
    }
    std::cout << numbers_head << '\n';
    std::cout << "max_elem->data = " << max_elem->data << '\n';

    // выполнять циклический сдвиг до тех пор,
    // пока на первом месте не станет максимальный элемент
    std::cout << "Working on it...\n";
    while (numbers_head != max_elem) {
        insert(numbers_head, numbers_tail, numbers_tail, numbers_head->data);
        remove(numbers_head, numbers_tail, numbers_head);
        std::cout << numbers_head << '\n';
    }

    // вывод измененного списка
    std::cout << "Result: ";
    std::cout << numbers_head << '\n';
}