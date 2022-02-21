#include <iostream>
#include <algorithm>
#include <vector>


std::vector<int> InputVector (int n){ //Вспомогательная функция для создания вектора
    std::vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        vec.push_back(x);
    }
    return vec;
}


void task4 (int n) {
    std::vector<int> vec = InputVector(n); // Создаем вектор
    int Max = *std::max_element(vec.begin(), vec.end()); //Находим значения макс элемента
    std::cout << std::count(vec.begin(), vec.end(), Max); //Считаем кол-о макс эл-ов
}


//Вспомогательные функции для проверки на четность / нечетность
bool odd(int x){
    return x % 2 == 0;
}
bool not_odd(int x){
    return x % 2 != 0;
}

void task7 (int n) {
    std::vector<int> vec = InputVector(n); // Создаем вектор
    auto it = remove_if(vec.begin(), vec.end(), odd); //Перемещаем все четные в конец и получаем итератор на начало четных
    vec.erase( it , vec.end()); //Удаляем все четные
    std::cout << "<- Delete chet elements ->" <<std::endl;
    for(int & iter : vec)
        std::cout << iter << " ";
    std::cout << std::endl;
    int Max = *std::max_element(vec.begin(), vec.end());//Находим значения макс элемента
    int Min = *std::min_element(vec.begin(), vec.end());//Находим значения мин элемента
    std::replace (vec.begin(), vec.end(), Max, Min); //Меняем местами
    std::cout << "<- Replace min - max ->" << std::endl;
    for(int & iter : vec)
        std::cout << iter << " ";
    int X;
    std::cout << std::endl;
    std::cout << "Input X" << std::endl; //Вводим х
    std::cin >> X;
    std::cout << "<-Count of cr X ->" << std::endl;
    std::cout << std::count_if(vec.begin(), vec.end(), [X](int i){return i % X == 0;});
}

//4 6
//9 1 5 4
//10 4 2 1 20 3
void task11 (int n1, int n2) {
    // Создаем векторы
    std::vector<int> vec1 = InputVector(n1);
    std::vector<int> vec2 = InputVector(n2);


    auto it1 = remove_if(vec1.begin(), vec1.end(), odd);
    vec1.erase( it1 , vec1.end());//Удаляем все четные
    std::cout << "<- Delete chet elements ->" << std::endl;
    for(int & iter : vec1)
        std::cout << iter << " ";
    std::cout << std::endl;

    auto it2 = remove_if(vec2.begin(), vec2.end(), not_odd);
    vec2.erase( it2 , vec2.end());//Удаляем все нечетные
    std::cout << "<- Delete nechet elements ->" << std::endl;
    for(int & iter : vec2)
        std::cout << iter << " ";
    std::cout << std::endl;

    //Сортировка векторов
    std::sort(vec1.begin(), vec1.end());
    std::cout << "<- First sorted ->" << std::endl;
    for(int & iter : vec1)
        std::cout << iter << " ";
    std::cout << std::endl;
    std::sort(vec2.begin(), vec2.end());
    std::cout << "<- Second sorted ->" << std::endl;
    for(int & iter : vec2)
        std::cout << iter << " ";
    std::cout << std::endl;

    //Мержим два вектора
    std::vector<int> v(vec1.size() + vec2.size());
    std::merge (vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), v.begin());
    std::cout << "<- Merge ->" << std::endl;
    for(int & iter : v)
        std::cout << iter << " ";

}


int main () {
    std::cout << "Input number of the task:" << std::endl;
    int n;
    std::cin >> n;
    switch (n) {
        case 1:{
            int size;
            std::cout << "Input array`s size: " << std::endl;
            std::cin >> size;
            task4(size);
            break;
        }
        case 2: {
            int size;
            std::cout << "Input array`s size: " << std::endl;
            std::cin >> size;
            task7(size);
            break;
        }
        case 3: {
            int size1, size2;
            std::cout << "Input array`s sizes: " << std::endl;
            std::cin >> size1 >> size2;
            task11(size1, size2);
            break;
        }
        default: {
            std::cout << "Wrong number!";
            break;
        }
    }
    return 0;
}