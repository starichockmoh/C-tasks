/**
 * Дано дерево. Вывести путь от корня до узла X.
*/

#include <iostream>
#include <string>
#include <sstream>
#include "binarySearchTree.hpp"

int main() {
    // инициализация элементов дерева
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

    // ввод значения X
    int x;
    std::cout << "\nEnter the value of X: ";
    std::cin >> x;

    // вывод пути от корня до элемента X
    std::cout << "The path from the root to element X is:\n";
    t.print_path(x);
    std::cout << '\n';
}