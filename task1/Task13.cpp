#include <iostream>
#include <string>
#include <cctype> // для функции isalpha
#include <set>
#include <fstream>
#include <regex>
#include <vector>


void task1(std::string str){
    for (char & i : str) {//цикл по строке
        char tmp = std::tolower(i);//переводим в нижний регистр
        if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u' || tmp == 'y') {
            i = ' ';//если символ это гласная буква то заменяем пробелом
        }
    }
    std::cout << str;
}


void task2(std::string str){
    std::string resStr;//самое длинное слово
    std::string tmpStr;//формируемое слово
    int resCounter = 0;//количество букв в слове
    for (int i = 0; i < str.size(); ++i) {//цикл по строке
       if (isalpha(str[i])){
           tmpStr += str[i];//формируем слово
       } else {
           if (tmpStr.size() > resCounter) {
               resCounter = tmpStr.size();//поиск самого длинного слова
               resStr = tmpStr;
           }
           tmpStr = "";
       }
    }
    if (tmpStr.size() > resCounter) {
        resCounter = tmpStr.size();
        resStr = tmpStr;
    }
    tmpStr = "";
    std::cout << resStr;
}


void task3(std::string str){
    std::string resStr;
    std::string tmpStr;
    int resCounter = 0;
    for (int i = 0; i < str.size(); ++i) {//аналогично пред задаче
        if (isalpha(str[i])){
            tmpStr += tolower(str[i]);
        } else {
            std::set <char>st ( begin( tmpStr ) , end( tmpStr ) );//для подсчета уникальных букв используем множество
            if (st.size() > resCounter) {
                resCounter = st.size();//находим максимальное количество уникальных букв
            }
            tmpStr = "";
        }
    }
    std::set <char>st ( begin( tmpStr ) , end( tmpStr ) );
    if (st.size() > resCounter) {
        resCounter = st.size();
    }
    tmpStr = "";

    std::cout << resCounter << std::endl;

    for (int i = 0; i < str.size(); ++i) {
        if (isalpha(str[i])){
            tmpStr += tolower(str[i]);
        } else {
            std::set <char>sts ( begin( tmpStr ) , end( tmpStr ) );
            if (sts.size() == resCounter) {
                std::cout << tmpStr << std::endl;
            }
            tmpStr = "";
        }
    }//снова идем по циклу и находим слова с макс кол-вом уникальных букв
    std::set <char>sts ( begin( tmpStr ) , end( tmpStr ) );
    if (sts.size() == resCounter) {
        std::cout << tmpStr << std::endl;
    }
    tmpStr = "";
}


void task4(){
    std::regex rx{R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.]\d\d\d\d)"};//регулярное выражение для проверки даты
    std::string line;
    std::string str;
    std::ifstream in("input.txt"); // окрываем файл для чтения
    std::ofstream out;          // поток для записи
    out.open("output.txt"); // окрываем файл для записи
    std::vector<std::string> Strings;//массив с корректными предлождениями
    if (in.is_open()) {
        while (getline(in, line)) {//считываем всё из файла
            std::cout << line << std::endl;
            str += line;
        }
    }
    bool isCorrectDate = false;
    std::string CorrectStr;
    for (int i = 0; i < str.size(); ++i) {//цикл по строке
        CorrectStr += str[i];
        if (std::isdigit(str[i])) {
            std::string tmpStr = str.substr(i, 10);
            if (std::regex_match(tmpStr, rx) && !isCorrectDate) {//проверка что данная последовательность это дата
                std::cout << tmpStr << std::endl;
                isCorrectDate = true;
            }
        }
        if ((str[i] == '.' || str[i] == '!' || str[i] == '?') && !isdigit(str[i+1])) {
            if (isCorrectDate) {
                Strings.push_back(CorrectStr);
            }
            isCorrectDate = false;
            CorrectStr = "";
            i+=1;
        }
    }

    for (int i = 0; i < Strings.size(); ++i) {//печатаем в файл все предложения с датами
        out << Strings[i] << std::endl;
    }

    in.close();     // закрываем файл
    out.close();
}


int main() {
    std::cout << "Choose task (1-4)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    std::cin.get();
    switch (task) { // смотрим какую задачу выбрали
        case 1: {
            std::cout << "1 task " << std::endl;
            std::cout << "Input line" << std::endl;
            std::string str;
            std::getline(std::cin, str);
            std::cout << "STRING: " << str << std::endl;
            task1(str); //выполняем задачу
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task " << std::endl;
            std::cout << "Input line" << std::endl;
            std::string str;
            std::getline(std::cin, str);
            std::cout << "STRING: " << str << std::endl;
            task2(str); //выполняем задачу
            break;
        };
        case 3: {
            std::cout << "2 task " << std::endl;
            std::cout << "Input line" << std::endl;
            std::string str;
            std::getline(std::cin, str);
            task3(str); //выполняем задачу
            break;
        };
        case 4: {
            task4();
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };
    }
}