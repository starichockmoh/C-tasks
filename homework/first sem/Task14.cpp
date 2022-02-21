#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cmath>


struct Hotel {//структура отель с ФИО, датой и количеством дней пребывания
    std::string FirstName, LastName, Patron, Date;
    int Days;
    bool IsHere;
};


struct Point {//структура точки с координатами
    int x,y;
};

struct Fraction {//структура дроби с числителем и знаменателем
    int num, den;
};


int SumDays(std::string Date) {
    int Days = 0; // Всего дней от начала времен
    int day = std::stoi(Date.substr(0, 2)); // дни
    int month = std::stoi(Date.substr(3, 5)); // месяцы
    int year = std::stoi(Date.substr(6, 10)); // годы
    Days += day-1; // прибавили сначала дни
    for (int i = 1; i < month; i += 1) {
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: {
                Days += 31;
                break;
            }
            case 4: case 6: case 9: case 11: {
                Days += 30;
                break;
            }
            case 2: {
                Days += 28;
                break;
            }
            default:
                break;
        }
    }
    Days += (year-1)*365;
    return Days;
} // функция для получения количества дней от даты


void task1(int n, std::string NewDate) {
    std::regex rx{
            R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.]\d\d\d\d)"};  //регулярное выражение для проверки даты
    std::vector<Hotel> Hotels(n);                            //массив отелей
    int NewDate_days = SumDays(NewDate);   //кол-во дней в введеной дате
    for (int i = 0; i < n; ++i) { // циклом прописываем всех постояльцев
        Hotel tmp;
        std::cout << "FLP: " << std::endl;
        std::cin >> tmp.FirstName >> tmp.LastName >> tmp.Patron;
        std::cout << "Date (dd.mm.yyyy): " << std::endl;;
        std::cin >> tmp.Date;
        while (!std::regex_match(tmp.Date, rx)) { //валидация введенной даты
            std::cout << "Incorrect date! " << std::endl;
            std::cout << "Date (dd.mm.yyyy): " << std::endl;
            std::cin >> tmp.Date;
        }
        std::cout << "Days: " << std::endl;;
        std::cin >> tmp.Days;
        tmp.IsHere = SumDays(tmp.Date) + tmp.Days >= NewDate_days; // вычисление дней и проверка
        Hotels[i] = tmp;
    }
    for (int i = 0; i < n; ++i) {//вывод на экран людей
        std::cout << i + 1 << " Client" << std::endl;
        std::cout << Hotels[i].FirstName << " " << Hotels[i].LastName << " " << Hotels[i].Patron << std::endl;
        std::cout << Hotels[i].Date << std::endl;
        std::cout << Hotels[i].Days << " Days" << std::endl;
        Hotels[i].IsHere ? std::cout << "will be in hotel in " << NewDate << std::endl : std::cout << "will not be" << std::endl;
    }

}


void task2(int n) {
    std::vector<Point> Points(n); //создаем массив точек с координатами
    for (int i = 0; i < n; ++i) {
        Point tmp;
        std::cout << "x,y:" << std::endl;
        std::cin >> tmp.x >> tmp.y;
        Points[i] = tmp;
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) { //выведем их на экран
        std::cout << i+1 << " Point" <<std::endl;
        std::cout << "(" << Points[i].x << ", " << Points[i].y << ")" << std::endl;
    }
    double MaxSum = 0; //макс сумма расстояний
    Point MaxPoint;  //точка с макс суммой
    for (int i = 0; i < n; ++i) { //цикл по всем точкам
        double TmpSum = 0;
        for (int j = 0; j < n; ++j) {
            int deltaX = (Points[i].x - Points[j].x) * (Points[i].x - Points[j].x); //(x1-x2)^2
            int deltaY = (Points[i].y - Points[j].y) * (Points[i].y - Points[j].y); //(y1-y2)^2
            TmpSum += sqrt(deltaX + deltaY); // корень из квадратов координат это и есть расстояние между точками
        }
        if (TmpSum >= MaxSum) {
            MaxSum = TmpSum;
            MaxPoint = Points[i];
        }
    }
    std::cout << MaxSum << std::endl; //выведем макс сумму
    std::cout << "Max: " << "(" << MaxPoint.x << ", " << MaxPoint.y << ")" << std::endl; //выведем макс точку
}

Fraction InputFraction () { //функция для ввода дроби
    Fraction tmp{};
    std::cout << "Input fraction" << std::endl;
    std::string str;
    std::getline(std::cin, str,'/');
    tmp.num = std::stoi(str); //то что до дроби записываем в числитель
    std::getline(std::cin, str);
    tmp.den = std::stoi(str); // после дроби в знаменатель
    return tmp;
}

void OutputCommonFraction (Fraction Frac) { //функция для вывода дроби
    std::cout << Frac.num << "/" << Frac.den << std::endl;
//    std::cout << Frac.num << std::endl;
//    std::cout << "-" << std::endl;
//    std::cout << Frac.den << std::endl;
}

void ToGoodFrac (Fraction Frac) { //функция для создания правильной дроби
    if (Frac.num < Frac.den) {
        OutputCommonFraction(Frac); //если числитель меньше или равен знаменателю то это уже правильная дробь
    } else if (Frac.num == Frac.den) {
        std::cout << Frac.num;
    } else {
        int IntTmp = Frac.num / Frac.den; //находим целое
        int OstTmp = Frac.num % Frac.den; // находим остаток, который пойдет в числитель
        std::cout << IntTmp << " " << OstTmp << "/" << Frac.den << std::endl;
    }
}

Fraction Reduction (Fraction Frac) { // функция для сокращения дроби
    Fraction c{};
    int a = Frac.num;
    int b = Frac.den;
    while (a > 0 && b > 0) { // реализация поиска НОДа
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    c.num = Frac.num / (a+b); // сокращаем числитель и знаменааетль на НОД
    c.den = Frac.den / (a+b);
    return c;
}

Fraction operator + (Fraction a, Fraction b) { //функция сложения
    Fraction c{};
    c.num = b.den * a.num + a.den * b.num;//находим числитель
    c.den = a.den*b.den;//общий знаменатель
    return c;
}

Fraction operator - (Fraction a, Fraction b) { //фукнция вычитания
    Fraction c{};
    c.num = b.den * a.num - a.den * b.num; //находим числитель
    c.den = a.den*b.den;  //общий знаменатель
    return c;
}

Fraction operator * (Fraction a, Fraction b) { //функция умножения
    Fraction c{};
    c.num = a.num * b.num; // перемножаем числители
    c.den = a.den * b.den; // перемножаем знаменатели
    return c;
}

Fraction operator / (Fraction a, Fraction b) { //фукнция деления
    Fraction c{};
    c.num = a.num * b.den;// перемножаем числители для перевернутой второй дроби
    c.den = a.den * b.num;// перемножаем знаменатели для перевернутой второй дроби
    return c;
}

void task3() {
    int NumOfOperation;
    std::cout << "Input operation" << std::endl <<  "1 - input / output" << std::endl <<  "2 - sum" << std::endl <<  "3 - difference" << std::endl;
    std::cout << "4 - Multiplication" << std::endl <<  "5 - division" << std::endl <<  "6 - reduction" << std::endl;
    std::cout << "7 - to decimal " << std::endl << "8 - to good frac" << std::endl;
    std::cin >> NumOfOperation;
    Fraction FracA{};
    Fraction FracB{};
    switch (NumOfOperation) {//осуществляем выбор операции
        case 1: {
            FracA = InputFraction();
            OutputCommonFraction(FracA);
            FracB = InputFraction();
            OutputCommonFraction(FracB);
        }
        case 2: {
            std::cout << "Sum" << std::endl;
            FracA = InputFraction();
            FracB = InputFraction();
            OutputCommonFraction(Reduction(FracA + FracB));
        }
        case 3: {
            std::cout << "Difference" << std::endl;
            FracA = InputFraction();
            FracB = InputFraction();
            OutputCommonFraction(Reduction(FracA - FracB));
        }
        case 4: {
            std::cout << "Multiplication" << std::endl;
            FracA = InputFraction();
            FracB = InputFraction();
            OutputCommonFraction(Reduction(FracA * FracB));
        }
        case 5: {
            std::cout << "Division" << std::endl;
            FracA = InputFraction();
            FracB = InputFraction();
            OutputCommonFraction(Reduction(FracA / FracB));
        }
        case 6: {
            std::cout << "Reduction" << std::endl;
            FracA = InputFraction();
            OutputCommonFraction(Reduction(FracA));
        }
        case 7: {
            std::cout << "Conversion to decimal" <<std::endl; // привидение к десятичной дроби
            FracA = InputFraction();
            std::cout << double(FracA.num) / FracA.den << std::endl;
        }
        case 8: {
            std::cout << "Conversion to nice frac" <<std::endl;
            FracA = InputFraction();
            ToGoodFrac(FracA);
            break;
        }
        default:{
            std::cout << "Wrong num!";
        }
    }
}

int main() {
    std::cout << "Choose task (1-3)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    std::cin.get();
    switch (task) { // смотрим какую задачу выбрали
        case 1: {
            std::regex rx{
                    R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.]\d\d\d\d)"};//регулярное выражение для проверки даты
            std::cout << "1 task " << std::endl;
            int n;
            std::string Date;
            std::cout << "Input array`s size:" << std::endl;
            std::cin >> n;
            std::cout << "Input date:" << std::endl;
            std::cin >> Date;
            if (std::regex_match(Date, rx)) {
                task1(n, Date); //выполняем задачу
            } else {
                std::cout << "Wrong format of date";
            }
            break;
        };
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task " << std::endl;
            int n;
            std::cout << "Input array`s size" << std::endl;
            std::cin >> n;
            task2(n);
            break;
        };
        case 3: {
            std::cout << "3 task " << std::endl;
            task3();
            break;
        };
        default: {
            std::cout << "Wrong number of task!";
            break;
        };
    }
}



//std::string DepartureDate(std::string Date, int Days) {
//    std::string NewDate;
//    int day = std::stoi(Date.substr(0,2));
//    std::cout << day << std::endl;
//    int month = std::stoi(Date.substr(3,5));
//    std::cout << month << std::endl;
//    int year = std::stoi(Date.substr(6, 10));
//    std::cout << year << std::endl;
//    switch (month) {
//        case (1, 3, 5, 7, 8, 10, 12): {
//            if (day + Days > 31) {
//                int tmpDay = day + Days - 31;
//                if (tmpDay < 10) {
//                    NewDate += "0";
//                    NewDate += std::to_string(tmpDay);
//                } else {
//                    NewDate += std::to_string(tmpDay);
//                }
//                NewDate += ".";
//                int tmpMonth = month + 1;
//                if (tmpMonth < 10) {
//                    NewDate += "0";
//                    NewDate += std::to_string(tmpMonth);
//                } else {
//                    NewDate += std::to_string(tmpMonth);
//                }
//                NewDate += ".";
//            }
//            break;
//        }
//        case (4,6, 9, 11): {
//
//            break;
//        }
//        case 2: {
//
//            break;
//        }
//        default: break;
//    }
//
//}