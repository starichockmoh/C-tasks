#include <iostream>
#include <vector> //библиотека позволяющая нам пользоваться динамическим массивом - вектором
#include <algorithm>


std::vector<std::vector<int>> CreateDoubleArray(int n) {//вспомогательная функция для создания двумерного массива
    std::vector<std::vector<int>> Arr(n);//инициализируем матрицу
    for (int i = 0; i < n; ++i){ //далее заполнем двумерный массив
        Arr[i] = std::vector<int> (n);
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


void Quicksort(std::vector<int> &mas, int first, int last) {
    int mid, tmp;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //вычисление опорного элемента
    do {
        while (mas[f] < mid) f++; //оставляем слева от опорного всё что меньше его
        while (mas[l] > mid) l--; //оставляем справа что больше
        if (f <= l) {  //перестановка элементов
            tmp = mas[f];
            mas[f] = mas[l];
            mas[l] = tmp;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) Quicksort(mas, first, l);//рекурсивно вызываем сортировку для левого отрезка
    if (f < last) Quicksort(mas, f, last); //для правого
}

void Merge(std::vector<int> &mas, int first, int last, bool vozr) {//функция для слияния двух массивов
    int middle, l1, l2, j;
    std::vector<int> buf(100); //вектор с промежуточными данными
    middle = (first + last) / 2; //вычисление среднего элемента
    l1 = first; //начало левой части
    l2 = middle + 1; //начало правой части
    for (j = first; j <= last; j++) //выполнять от начала до конца
        if ((l1 <= middle) && ((l2 > last) || (vozr? mas[l1] < mas[l2]: mas[l1] > mas[l2]))) {
            buf[j] = mas[l1];
            l1++;
        } else {
            buf[j] = mas[l2];
            l2++;
        }

    for (j = first; j <= last; j++) mas[j] = buf[j]; //возвращение результата в вектор
}

void MergeSort(std::vector<int> &mas, int first, int last, bool vozr) { ;//рекурсивная функция сортировки
    if (first < last) {
        MergeSort(mas, first, (first + last) / 2,vozr); //сортировка левой части
        MergeSort(mas, (first + last) / 2 + 1, last,vozr); //сортировка правой части
        Merge(mas, first, last,vozr); //слияние двух частей
    }
}

void ChoiceSort(std::vector<int> &mas) {
    for (int i = 0; i < mas.size(); ++i) {
        int tmp = mas[i];
        int min_index = i; //индекс минимального элемента
        for (int j = i+1; j < mas.size(); ++j) { //ищем минимальный элемент среди [i, n-1]
            if (mas[j] > mas[min_index]) min_index = j;
        }
        mas[i] = mas[min_index]; //меняем iтовый с минимальным
        mas[min_index] = tmp;
    }
}

void task1 (int n) {
    std::vector<std::vector<int>> Arr = CreateDoubleArray(n);
    std::cout << "Array before:" << std::endl;
    PrintArray(Arr);
    for (int j = 0; j < n; ++j) {
        std::vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.push_back(Arr[i][j]);
        }
        Quicksort(tmp,0,tmp.size()-1);
        for (int i = 0; i < n; ++i) {
            Arr[i][j] = tmp[i];
        }
    }
    std::cout << "Array after:" << std::endl;
    PrintArray(Arr);

}

void task8 (int n) {
    std::vector<std::vector<int>> Arr = CreateDoubleArray(n);
    std::cout << "Array before:" << std::endl;
    PrintArray(Arr);
    for (int i = 0; i < n; ++i){
        if ((i+1) % 3 == 0){
            MergeSort(Arr[i],0,n-1, false);
        } else {
            MergeSort(Arr[i],0,n-1, true);
        }
    }
    std::cout << "Array after:" << std::endl;
    PrintArray(Arr);
}

void task14 (int n) {
    std::vector<std::vector<int>> Arr = CreateDoubleArray(n);
    std::cout << "Array before:" << std::endl;
    PrintArray(Arr);
    for (int k = 1; k < 2*n - 2; ++k) {
        std::vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            if (k-i < n && k-i >= 0) {
                tmp.push_back(Arr[i][k-i]);
            }
        }
        ChoiceSort(tmp);
        int L = 0;
        for (int i = 0; i < n; ++i) {
            if (k-i < n && k-i >= 0) {
                Arr[i][k-i] = tmp[L];
                L ++;
            }
        }
    }
    std::cout << "Array after:" << std::endl;
    PrintArray(Arr);

}

int main() {
    std::cout << "Input task (1-3)" << std::endl;
    int task,n;
    std::cin >> task;
    std::cout << "Input array`s length" << std::endl;
    std::cin >> n;
    switch (task) {
        case 1: {
            task1(n);
            break;
        }
        case 2: {
            task8(n);
            break;
        }
        case 3: {
            task14(n);
            break;
        }
        default: {
            std::cout << "Wrong number of a task!" << std::endl;
            break;
        }
    }
    return 0;
}

