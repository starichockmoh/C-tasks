#include <iostream> //библиотека для потока ввода-вывода


int main() {
    auto c = 'a';
    auto p = &c; // p это указатель на адрес памяти переменной с
    auto d = *p; // с помощью оператора * мы получаем значение переменной по адресу указанному в p
    std::cout << typeid(p).name() << " " << p << std::endl;
    std::cout << typeid(d).name() << " " << d << std::endl; //поэтому у d тип char (символ) а значение 'a'

    auto p1 = new double[5] {5,4,3,2,1};//инициализация массива

    return 0;
}

