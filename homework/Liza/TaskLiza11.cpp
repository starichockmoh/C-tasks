#include <iostream>
#include <fstream>
#include <string>

int main () {
    std::ifstream in_1("first_file_numbers.txt"); // открываем файл для чтения
    std::ifstream in_2("second_file_numbers.txt"); // открываем файл для чтения
    std::ofstream out;          // поток для записи
    out.open("output.txt"); // окрываем файл для записи
    std::string line;
    if (in_1.is_open()) {
        while (getline(in_1, line)) { // считываем всё из файла
            if (line[0] != '-') { // Если число положительное записываем в файл
                out << line << std::endl;
            }
        }
    }
    if (in_2.is_open()) {
        while (getline(in_2, line)) { // считываем всё из файла
            if (line[0] == '-') { // Если число отрицательное записываем в файл
                out << line << std::endl;
            }
        }
    }
    in_1.close(); // закрываем файл
    in_2.close(); // закрываем файл
    out.close(); // закрываем файл

    return 0;
}