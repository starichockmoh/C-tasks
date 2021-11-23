#include <iostream>
#include <vector> //библиотека позволяющая нам пользоваться динамическим массивом - вектором
#include <algorithm>

std::vector<std::vector<int>> CreateDoubleArray(int n, int n_2) {//вспомогательная функция для создания двумерного массива
    std::vector<std::vector<int>> Arr(n_2*n);//инициализируем матрицу
    for (int i = 0; i < n; ++i){ //далее заполнем двумерный массив
        Arr[i] = std::vector<int> (n_2*n);
    }
    for (int i = 0; i < n; ++i){
        std::cout << i << " line: " << std::endl;
        for (int j = 0; j < n; ++j){
            int tmp;
            std::cin >> tmp;
            Arr[i][j] = tmp;
        }
    }
    return Arr;
}

void PrintArray(std::vector<std::vector<int>> Arr){//вспомогательная функция для вывода на экран двумерного массива
    for (int i = 0; i < Arr.size(); ++i){
        for (int j = 0; j < Arr.size(); ++j){
            std::cout << Arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void task1 (int n) {
    int start_n = n;// сохраняем стартовый размер массива
    std::vector Arr = CreateDoubleArray(n,2);//создаем массив
    std::vector<int> Line (n);//будущая строка вставляемая после положительных строк
    std::cout << "Print line: " << std::endl;
    for (int i = 0; i < n; ++i){//формируем эту строку
        int tmp;
        std::cin >> tmp;
        Line[i] = tmp;
    }
    std::cout << std::endl;
    bool IsPositive = true;//флаг для обозначения строки со всеми положительными элементами
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){//идем по строке и смотрим какие элементы полож какие нет
            if (Arr[i][j] < 0) {
                IsPositive = false;
                break;//если нашли хоть один отриц элемент меняем флаг и завершаем цикл
            }
        }
        if (IsPositive) {
            for (int k = n; k > i; k--)//при условии делаем сдвиг элементов от i+1 до n вправо на один
                Arr[k] = Arr[k-1];
            Arr[i+1] = Line; //вставляем после элемента строку
            n ++;//увеличим размер массива
            i ++;//перескочим на следущую i
        }
        IsPositive = true;
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i){//вывод нового массива
        for (int j = 0; j < start_n; ++j){
            std::cout << Arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void task6 (int n) {
    int start_n = n;// сохраняем стартовый размер массива
    std::vector Arr = CreateDoubleArray(n,2);//создаем массив
    std::vector<int> Line (n);//будущий столбец вставляемый после нужных
    std::cout << "Print column: " << std::endl;
    for (int i = 0; i < n; ++i){//формируем этот столбец
        int tmp;
        std::cin >> tmp;
        Line[i] = tmp;
    }
    std::cout << std::endl;
    bool IsPositive = true;//флаг для обозначения строки со всеми положительными элементами
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < start_n; ++i){//идем по столбу и смотрим какие элементы полож какие нет
            if (Arr[i][j] % 2 == 0) {
                IsPositive = false;
                break;//если нашли хоть один отриц элемент меняем флаг и завершаем цикл
            }
        }
        if (IsPositive) {
            for (int row = 0; row < start_n; ++row){
                for (int k = n; k > j; k--)//при условии делаем сдвиг элементов от i+1 до n вправо на один
                    Arr[row][k] = Arr[row][k-1];
                Arr[row][j] = Line[row]; //вставляем после элемента значение
            }
            n++;
            j++;
        }
        IsPositive = true;
    }
    std::cout << std::endl;
    for (int i = 0; i < start_n; ++i){//вывод нового массива
        for (int j = 0; j < n; ++j){
            std::cout << Arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void task12 (int n) {
    std::vector<std::vector<int>> Arr = CreateDoubleArray(n,1);//создаем массив
    int start_n = n;// сохраняем стартовый размер массива
    bool isPositive = true;//флаг для обозначения строки со всеми положительными элементами
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < start_n; ++j){//идем по строке и смотрим какие элементы полож какие нет
            if (Arr[i][j] < 0) {
                isPositive = false;//если нашли хоть один отриц элемент меняем флаг и завершаем цикл
                break;
            }
        }
        if (isPositive){
            for (int k = i; k < n-1; ++k){
                Arr[k] = Arr[k+1];//делаем сдвиг вправо, стирая тем самым строку
            }
            --n;//умеьшаем размер массива
            --i;//остаемся на той же строке
        }
        isPositive = true;
    }
    for (int i = 0; i < n; ++i){//вывод нового массива
        for (int j = 0; j < start_n; ++j){
            std::cout << Arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

}


void task17 (int n) {
    int start_n = n;// сохраняем стартовый размер массива
    std::vector Arr = CreateDoubleArray(n,2);//создаем массив
    bool IsChet = true;//флаг для обозначения строки со всеми четными элементами
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < start_n; ++i){//идем по столбу и смотрим какие элементы полож какие нет
            if (Arr[i][j] % 2 != 0) {
                IsChet = false;
                break;//если нашли хоть один нечетный элемент меняем флаг и завершаем цикл
            }
        }
        if (IsChet) {
            for (int row = 0; row < start_n; ++row){//идем по каждой строке и удаляем элементы в искомом столбце
                for (int k = j; k < n-1; ++k){
                    Arr[row][k] = Arr[row][k+1];
                }
            }
            n--;//умеьшаем размер массива
            j--;//остаемся на том же столбце
        }
        IsChet = true;
    }
    std::cout << std::endl;
    for (int i = 0; i < start_n; ++i){//вывод нового массива
        for (int j = 0; j < n; ++j){
            std::cout << Arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    std::cout << "Choose task (1-4)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            std::cout << "Input array`s length" << std::endl;
            int n;
            std::cin >> n; //Вводим значение
            task1(n); //выполняем задачу
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task " << std::endl;
            std::cout << "Input array`s length" << std::endl;
            int n;
            std::cin >> n; //Вводим два значения
            task6(n);
            break;
        };
        case 3: {
            std::cout << "3 task " << std::endl;
            std::cout << "Input array`s length" << std::endl;
            int n;
            std::cin >> n;
            task12(n);
            break;
        };
        case 4: {
            std::cout << "4 task " << std::endl;
            std::cout << "Input array`s length" << std::endl;
            int n;
            std::cin >> n;
            task17(n);
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };

            return 0;
    }
}