#include <iostream>
#include <vector>

template <typename X> //шаблон функции
std::vector<std::vector<X>> CreateDoubleArray(X c, int n, int m) {//вспомогательная функция для создания двумерного массива
    std::vector<std::vector<X>> Arr(n);//инициализируем матрицу
    for (int i = 0; i < n; ++i){ //далее заполнем двумерный массив
        Arr[i] = std::vector<X> (m);
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            std::cin >> Arr[i][j];
        }
    }
    return Arr;
}

template<typename X>//шаблон функции
std::vector<X> CreateArray(X c, int m){//вспомогательная функция для создания массива
    std::vector<X> Arr (m);
    for (int i = 0; i < m; ++i){ //далее заполнем двумерный массив
        std::cin >> Arr[i];
    }
    return Arr;
}

template <typename X>//шаблон функции
void PrintArray(std::vector<std::vector<X>> Arr,int n,int m){//вспомогательная функция для вывода на экран двумерного массива
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            std::cout << Arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename X>//шаблон функции
void task4(int n,int m,std::vector<std::vector<X>> Arr) {
    PrintArray(Arr, n, m); //печатаем ее
    for (int j = 1; j < m; j += 2){ //идем по столбам
        for (int i = 0; i < n; ++i){ // идем по строкам
            std::swap(Arr[i][j], Arr[i][j-1]);
        }
    }
    PrintArray(Arr, n, m);//печатаем новый массив
}


template<typename X>//шаблон функции
void task11(int n,int m,std::vector<std::vector<X>> Arr, std::vector<X> Str) {
    PrintArray(Arr, n, m); //печатаем ее
    for (int i = 0; i < n; i += 2) {
        Arr[i] = Str;
    }
    PrintArray(Arr, n, m);//печатаем новый массив
}


int main() {
    std::cout << "Choose task (1-2)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            int n,m,k;
            std::cout << "Input array`s size n" << std::endl;
            std::cin >> n; //Вводим значение
            std::cout << "Input array`s size m" << std::endl;
            std::cin >> m; //Вводим значение
            std::cout << "Input type:\n1 - int\n2 - double\n3 - char\n4 - float\n"; //реализуем выбор типа
            std::cin >> k;
            std::cout << "Input array" << std::endl;
            switch (k) {
                case 1:{
                    int c = 1; //инициализационное значения для вывода типа
                    std::vector<std::vector<int>> Arr = CreateDoubleArray(c,n,m);
                    task4(n, m, Arr);
                    break;
                }
                case 2:{
                    double c1 = 1;
                    std::vector<std::vector<double>> Arr = CreateDoubleArray(c1,n,m);
                    task4(n, m, Arr);
                    break;
                }
                case 3:{
                    char c2 = '1';
                    std::vector<std::vector<char>> Arr = CreateDoubleArray(c2,n,m);
                    task4(n, m, Arr);
                    break;
                }
                case 4:{
                    float c3 = 1;
                    std::vector<std::vector<float>> Arr = CreateDoubleArray(c3,n,m);
                    task4(n, m, Arr);
                    break;
                }
                default:{
                    std::cout << "Error" <<std::endl;
                }

            } //выбираем нужный тип
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "1 task " << std::endl;
            int n,m,k;
            std::cout << "Input array`s size n" << std::endl;
            std::cin >> n; //Вводим значение
            std::cout << "Input array`s size m" << std::endl;
            std::cin >> m; //Вводим значение
            std::cout << "Input type:\n1 - int\n2 - double\n3 - char\n4 - float\n";
            std::cin >> k;
            std::cout << "Input array" << std::endl;
            switch (k) {
                case 1:{
                    int c = 1;
                    std::vector<std::vector<int>> Arr = CreateDoubleArray(c,n,m);
                    std::cout << "Input X" << std::endl;
                    std::vector<int> Str = CreateArray(c,m);
                    task11(n, m, Arr,Str);
                    break;
                }
                case 2:{
                    double c1 = 1;
                    std::vector<std::vector<double>> Arr = CreateDoubleArray(c1,n,m);
                    std::cout << "Input X" << std::endl;
                    std::vector<double> Str = CreateArray(c1,m);
                    task11(n, m, Arr, Str);
                    break;
                }
                case 3:{
                    char c2 = '1';
                    std::vector<std::vector<char>> Arr = CreateDoubleArray(c2,n,m);
                    std::cout << "Input X" << std::endl;
                    std::vector<char> Str = CreateArray(c2,m);
                    task11(n, m, Arr,Str);
                    break;
                }
                case 4:{
                    float c3 = 1;
                    std::vector<std::vector<float>> Arr = CreateDoubleArray(c3,n,m);
                    std::cout << "Input X" << std::endl;
                    std::vector<float> Str = CreateArray(c3, m);
                    task11(n, m, Arr, Str);
                    break;
                }
                default:{
                    std::cout << "Error" <<std::endl;
                }

            }
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };
    }
}