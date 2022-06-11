#include <iostream>
#include <vector>


struct Fraction {//структура дроби с числителем и знаменателем
    int num, den;
};


int NOD(int a, int b) { // функция для поиска НОДа
    while (a > 0 && b > 0) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

Fraction InputFraction() { //функция для ввода дроби
    Fraction tmp{};
    std::cout << "Input fraction" << std::endl;
    std::string str;
    std::getline(std::cin, str, '/');
    tmp.num = std::stoi(str); //то что до дроби записываем в числитель
    std::getline(std::cin, str);
    tmp.den = std::stoi(str); // после дроби в знаменатель
    return tmp;
}

void OutputCommonFraction(Fraction Frac) { //функция для вывода дроби
    std::cout << Frac.num << "/" << Frac.den << std::endl;
}

Fraction Reduction(Fraction Frac) { // функция для сокращения дроби
    Fraction c{};
    int a = Frac.num;
    int b = Frac.den;
    int nod = NOD(a,b);
    c.num = Frac.num /nod; // сокращаем числитель и знаменааетль на НОД
    c.den = Frac.den / nod;
    return c;
}
Fraction operator + (Fraction a, Fraction b) { //функция сложения
    Fraction c{};
    c.num = b.den * a.num + a.den * b.num;//находим числитель
    c.den = a.den*b.den;//общий знаменатель
    return Reduction(c); //возвращаем сокращенную дробь
}



int main() {

    std::cout << "Fraction for reduction: " << std::endl;
    Fraction FracC{};
    FracC = InputFraction();
    std::cout << "Abbreviated fraction: " << std::endl;
    OutputCommonFraction(Reduction(FracC));

    std::cout << "Input to numbers for NOK: " << std::endl;
    int a,b;
    std::cin >> a >> b;
    std::cout << a * b / NOD(a,b) << std::endl;

    std::cout << "Fractions for addition: " << std::endl;
    Fraction FracA{};
    Fraction FracB{};
    FracA = InputFraction();
    FracB = InputFraction();
    std::cout << "The result of addition: " << std::endl;
    OutputCommonFraction(FracA + FracB);

    std::cout << "Input n: " << std::endl;
    int n;
    std::vector<int> Vec; //массив с n чисел
    std::cin >> n;
    std::cout << "Input numbers:" << std::endl;
    for (int i = 0; i < n; ++i){
        int tmp;
        std::cin >> tmp;
        Vec.push_back(tmp);
    }
    int nod = Vec[0];
    for (int i = 1; i < n; ++i){//в цикле вычисляем нод
        int tmp = nod;
        nod = NOD(Vec[i], tmp);
    }

    std::cout << "NOD:  " << nod << std::endl;



    return 0;
}