#include <iostream>
#include <fstream>
#include <string>

int main () {
    char letter; // введенная буква
    std::cout << "Input letter:\n>>> ";
    std::cin >> letter;
    std::ifstream in("input.txt"); // открываем файл для чтения
    std::string line;
    if (in.is_open()) {
        while (getline(in, line)) { // считываем всё из файла
            if (tolower(line[0]) == tolower(letter)) std::cout << line << std::endl;
            // Если первая буква строки совпадает с введенной, то выводим строку на экран
            // (регистр не учитывается)
        }
    }
    in.close(); // закрываем файл

    return 0;
}