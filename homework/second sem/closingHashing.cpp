#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>


std::ifstream in("input.txt");

struct date {//дата
    int dd, mm, yy;
};


struct people {//данные о человеке
    std::string Surname; //фамилия
    date DateOfBirth{}; //дата рождения
    std::string Post;
    int Exp{};
    int Salary{}; //зарплата
};

date Str_to_Date(std::string str) {//из строки в дату
    date x;
    std::string temp = str.substr(0, 2);//день
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2);//месяц
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4);//год
    x.yy = atoi(temp.c_str());
    return x;
}

std::vector<people> inFile() {//ввод из файла
    std::vector<people> x;
    people temp;
    while (in.peek() != EOF) {
        in >> temp.Surname;//фамилия
        in >> temp.Post;
        std::string tmp;//дата рождения
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.Exp;
        in >> temp.Salary;//зарплата
        x.push_back(temp);
    }
    return x;
}

int auxiliaryHashing(int x) {
    double ATmp = x * ((sqrt(5) - 1) / 2.0);
    return int((ATmp - int(ATmp)) * 32);
}

void printPeople(people x) {//вывод в файл
    std::cout << std::setw(10) << std::left << x.Surname;//по левому краю, 10 позиций для фамилии
    std::cout << std::left << std::setw(24) << x.Post;//на должность 24 позиции
    if (x.DateOfBirth.dd < 10) std::cout << std::left << '0' << x.DateOfBirth.dd << '.';//добавляем 0
    else std::cout << std::left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10) std::cout << '0' << x.DateOfBirth.mm << '.';
    else std::cout << x.DateOfBirth.mm << '.';
    std::cout << std::left << std::setw(6) << x.DateOfBirth.yy;//на год 6 позиций
    std::cout << std::left << std::setw(10) << x.Exp;//Стаж
    std::cout << std::left << std::setw(10) << x.Salary << std::endl;//запрлата
}

int main() {
    std::vector<people> peopleArray;
    people NullPeople;
    NullPeople.Post = "NULL";


    std::vector<people> hashTable(32, NullPeople);
    peopleArray = inFile();
    for (int i = 0; i < peopleArray.size(); ++i){
        int hashValue = auxiliaryHashing(peopleArray[i].DateOfBirth.yy);
        if (hashTable[hashValue].Post == "NULL") {
            hashTable[hashValue] = peopleArray[i];
        } else {
            int j = hashValue + 1;
            while (j != hashTable.size() - 1) {
                if (hashTable[j].Post == "NULL") {
                    hashTable[j] = peopleArray[i];
                    break;
                } else {
                    j++;
                }
            }
        }
    }

    for (int i = 0; i < hashTable.size(); ++i) {
        std::cout << '[' << i << ']' << ": ";
        printPeople(hashTable[i]);
        std::cout << std::endl;
    }


    std::cout << "Input surname: " << std::endl;
    std::string surname;
    std::cin.clear();
    std::getline(std::cin, surname);
    int Year;
    std::cout << "Input year" << std::endl;
    std::cin >> Year;
    int hashYear = auxiliaryHashing(Year);
    int j = hashYear;
    while (true) {
        if (hashTable[j].Surname != surname && hashTable[j].Post != "NULL") {
            j++;
        } else {
            if (hashTable[j].Post != "NULL") printPeople(hashTable[j]);
            else std::cout << "Not found" << std::endl;
            break;
        }
    }

    return 0;
}