#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>
#include <fstream>
#include <cctype>




void task1 (int n) {
    std::set<int> FilterNumbers; //Цифры в дву-ых числах
    std::set<int> BadNumbers; //Все остальные цифры
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        if (tmp / 100 == 0 && tmp / 10 > 0) { //Проверяем что число двузначное
            FilterNumbers.insert(tmp / 10); //Записываем в множество обе цифры
            FilterNumbers.insert(tmp % 10);
        } else {
            while (tmp) {
                BadNumbers.insert(tmp % 10); //Записываем цифры числа в множество
                tmp /= 10;
            }
        }
    }
    std::vector <int> res(FilterNumbers.size());
    for (auto iter = FilterNumbers.begin(); iter != FilterNumbers.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    for (auto iter = BadNumbers.begin(); iter != BadNumbers.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::set_difference(FilterNumbers.begin(), FilterNumbers.end(), BadNumbers.begin(), BadNumbers.end(), res.begin());
    //Находим элементы, которые есть в фильтре, но отсутствуют в плохих

    std::cout << std::endl;
    std::cout << "Res: " << std::endl;
    for (int i = 0; i < res.size(); ++i) { //Выводим результат
        if (i > 0 && res[i] == 0) break;
        std::cout << res[i] << " ";
    }

}

void task7 () {
    std::set<std::string> vopr; //Множество со словами в вопросительных предложениях
    std::set<std::string> pov; //Множество со словами в повествовательных предложениях
    std::set<std::string> vosk; //Множество со словами в восклицательных предложениях
    std::string razd = "!?.";
    std::string str; //Строка со всеми предложениями
    int pos = 0; //номер с которого будет вестись поиск знака
    _flushall(); //очищаем буфер для работы getline
    std::cout << "Input string: " << std::endl;
    std::getline(std::cin, str);
    while (true) {
        int k = str.find_first_of(razd, pos); //Номер вхождения ?.!
        if (k == -1) break; //Условие выхода из цикла
        std::string temp = str.substr(pos, k - pos) + " "; //Записываем предложение
        if (temp[0] == ' ') temp = temp.substr(1); //Обрезаем в начале при необхлодимсоти пробел
        pos = k + 1; //Изменяем позицию с которой ищем след знак
        char tmp = str[k]; //Фиксируем сам знак
        int pos1 = 0; //Позиция для поиска слов
        while (true) {
            int k1 = temp.find_first_of(" ", pos1); // Конец первого слова
            if (k1 == -1) break; //Условие выхода из цикла
            std::string word = temp.substr(pos1, k1 - pos1);//Записываем слово
            if(std::isupper(word.front())){ //Приводим к нижнему регистру
                word.front()=std::tolower(word.front());
            }
            pos1 = k1 + 1;
            switch (tmp) { //В зависимости от знака добавляем слово в то или иное множество
                case '!':{
                    vosk.insert(word);
                    break;
                }
                case '?':{
                    vopr.insert(word);
                    break;
                }
                case '.':{
                    pov.insert(word);
                    break;
                }
                default:{
                    break;
                }
            }
        }
    }
    std::cout << "?" << std::endl;
    for (auto iter = vopr.begin(); iter != vopr.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::cout << "!" << std::endl;
    for (auto iter = vosk.begin(); iter != vosk.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::cout << "." << std::endl;
    for (auto iter = pov.begin(); iter != pov.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::vector <std::string> tmp_res;
    std::set_intersection(vopr.begin(), vopr.end(), vosk.begin(), vosk.end(),  std::back_inserter(tmp_res));
    //Находим пересечение двух множеств

    for (int i = 0; i < tmp_res.size(); ++i) {
        std::cout << tmp_res[i] << " ";
    }
    std::cout << std::endl;

    std::vector <std::string> res;
    std::set_difference(tmp_res.begin(), tmp_res.end(), pov.begin(), pov.end(), std::back_inserter(res));
    //Разность

    std::cout << "Res: " << std::endl;
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << " ";
    }

}
//Is mom going to market today? Mom is not go to the market! But mom is cooking now.

void task12 () {
    std::map<std::string, int> Dict;//Словарь со всеми словами в качестве ключа и кол-вом вхождений в качестве значения
    std::string line;
    std::string str;
    std::ifstream in("input.txt"); // открываем файл для чтения
    if (in.is_open()) {
        while (getline(in, line)) {//считываем всё из файла
            str += line;
        }
    }
    str += " ";
    int pos = 0;
    while (true) {
        int k = str.find_first_of(" ", pos); //Аналогично с пред заданием считываем слова
        if (k == -1) break;
        std::string word = str.substr(pos, k - pos);
        if (std::isalpha(word[0])) { // Проверка, что слово не число
            if (Dict.count(word)) { //Если слово уже есть в словаре, то прибавляем к кол-ву 1
                Dict[word] += 1;
            } else { //Иначе вхождение одно
                Dict[word] = 1;
            }
        }
        pos = k + 1;
    }
    for (auto iter = Dict.begin(); iter != Dict.end(); iter++) {  // выводим их
        std::cout  << iter->first << " " << iter->second << std::endl;
    }

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
            task1(size);
            break;
        }
        case 2: {
            task7();
            break;
        }
        case 3: {
            task12();
            break;
        }
        default: {
            std::cout << "Wrong number!";
            break;
        }
    }
    return 0;
}


