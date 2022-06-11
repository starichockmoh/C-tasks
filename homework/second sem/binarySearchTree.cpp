/**
 * Дано дерево. Удалить элементы, кратные Х. 
*/

#include <iostream>
#include <string>
#include <sstream>
#include "binarySearchTree.hpp"

int main() {
    // заполнение дерева
    std::cout << "Enter the values to insert in a tree:\n>>> ";
    std::string input;
    std::getline(std::cin, input);
    std::stringstream input_stream(input);

    int value;
    BinarySearchTree<int> t;
    while (input_stream >> value) {
        t.insert(value);
    }

    // вывод заполненного дерева
    std::cout << "A tree has been filled up. Here's the traversal:\n";
    t.inorder_traversal();
    std::cout << '\n';

    std::cout << "\nAnother representation:\n";
    t.print();

    //Удаление элемента
    std::cout << "\nEnter the value of deleted value: ";
    int del_value;
    std::cin >> del_value;
    t.delete_value(del_value);
    t.print();

    //Вставка элемента
    std::cout << "\nEnter the value of inserted value: ";
    int ins_value;
    std::cin >> ins_value;
    t.insert(ins_value);
    t.print();

    // ввод значения X
    int x;
    std::cout << "\nEnter the value of X: ";
    std::cin >> x;

    // удалить элементы, для которых значение предиката true
    t.delete_if([x](int e) { return e % x == 0; });

    // вывод измененного дерева
    std::cout << "Conditional deletion has completed. Resulting tree traversal is:\n";
    t.inorder_traversal();
    std::cout << "\nAnother look:\n";
    t.print();
}