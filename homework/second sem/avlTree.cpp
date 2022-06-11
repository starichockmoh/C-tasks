
/**
 * Дано дерево. Подсчитать сумму листьев.
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

    // вывод исходного дерева
    std::cout << "A tree has been filled up. Here's the traversal:\n";
    t.preorder_traversal();
    std::cout << "\nAnother representation:\n";
    t.print();
    // вывод суммы листьев
    std::cout << "\nThe sum of leaf nodes is " << t.leaves_sum() << ".\n";
}