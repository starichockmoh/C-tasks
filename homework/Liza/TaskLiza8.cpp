#include <iostream>
using namespace std;


int main(){
    string s;
    string str1;
    cout << " Input str: " << endl; //Вводим строку
    getline(cin, s);
    cout << "Input str1: " << endl; //Вводим подстроку
    getline(cin, str1);
    size_t pos = s.find(str1); //Итератор на первую найденную подстроку
    while (pos!=string::npos){ //Выполняем пока существует pos
        s.replace(pos, str1.length(), ""); //Заменяем подстроку на пустоту
        pos = s.find(str1); //Переключаемся на следующий итератор
    }
    cout << s << endl;
    return 0;
}