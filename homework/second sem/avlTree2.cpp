/**
 * Дано дерево. Определить высоту узла X.
*/

#include <iostream>
#include <string>
#include <sstream>
#include "avlTree.hpp"

int main() {
    // заполнение дерева
    std::cout << "Enter the values to insert in a tree:\n>>> ";
    std::string input;
    std::getline(std::cin, input);
    std::stringstream input_stream(input);

    int value;
    AVLTree<int> t;
    while (input_stream >> value) {
        t.insert(value);
    }

    // вывод заполненного дерева
    std::cout << "A tree has been filled up. Here's the traversal:\n";
    t.preorder_traversal();
    std::cout << "\nAnother representation:\n";
    t.print();

    // ввод значения X
    int x;
    std::cout << "\nEnter the value of X: ";
    std::cin >> x;

    auto node = t.search(x);
    if (node == nullptr) {
        std::cerr << "There is no node with such value.\n";
        return 1;
    }
    // вывод высоты, на которой находится элемент X
    std::cout << "The height of node X is " << height(node) << ".\n";
}