#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


std::vector<int> MaxElements(std::vector<int> Array) {
    std::ofstream out;          // поток для записи
    out.open("output.txt"); // окрываем файл для записи
    std::sort(Array.begin(), Array.end(),std::greater<int>()); // сортировка массива по убыванию
    for (int i = 0; i < Array.size(); ++i) {
        std::cout << Array[i] << std::endl;
    }
    if (Array.size() < 3) {
        for (int i = 0; i < Array.size(); ++i) {//печатаем в файл элементы массива
            out << Array[i] << std::endl;
        }
    } else {
        for (int i = 0; i < 3; ++i) {//печатаем в файл элементы массива
            out << Array[i] << std::endl;
        }
    }
}


int main() {
    std::ifstream in("input.txt"); // окрываем файл для чтения

    std::string StrArray; // Считанная с файла строка с массивом
    int ArrayLen; // кол-во элементов массива

    if (in.is_open()) {
        in >> ArrayLen; // считываем кол-во элементов из файла
        in.get();
        std::getline(in, StrArray); // получаем строку с массивом
    }
    std::vector<int> Array; // сам массив
    std::string delimiter = " "; // разделитель элементов в строке

    size_t pos = 0;
    std::string token;
    while ((pos = StrArray.find(delimiter)) != std::string::npos) {// цикл для получения масива из строки по разделителю пробела
        token = StrArray.substr(0, pos);
        Array.push_back(std::stoi(token)); // добавление элемента в массив
        StrArray.erase(0, pos + delimiter.length());
    }
    Array.push_back(std::stoi(StrArray));
    MaxElements(Array);//вызываем функцию
    return 0;
}