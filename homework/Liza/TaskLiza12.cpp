#include <iostream>
#include <fstream>
#include <string>

int main () {
    int n;
    std::cout << "Input number of numbers:" << std::endl;
    std::cin >> n;
    std::ofstream out; // поток для записи
    out.open("newfile",std::ios::binary);  // окрываем бинарный файл для записи
    if (out.is_open()) {
        for (int i = 0; i < n; ++i) {
            std::cout << "Input " << i+1 << " number:" << std::endl;
            int tmp;
            std::cin >> tmp;
            out << tmp << std::endl;
        }
    }
    out.close();// закрываем файл


    std::ifstream in;
    int a, b;
    std::cout << "Input a, b (a < b)" << std::endl;
    std::cin >> a >> b;
    in.open("newfile",std::ios::binary); // открываем файл для чтения
    std::string line;
    if (in.is_open()) {
        while (getline(in, line)) { // считываем всё из файла
            if ((std::stoi(line) > a) && (std::stoi(line) < b)) {
                std::cout << line << std::endl;
            }
        }
    }
    in.close();// закрываем файл
    return 0;
}