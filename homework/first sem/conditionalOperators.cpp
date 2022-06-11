#include <iostream> //библиотека для потока ввода-вывода

#define _USE_MATH_DEFINES //определяем математические константы

#include <cmath> // библиотека для математических операций

int task2(int x, int a) {
    if (x / 10 != 0 | a / 1000 != 0 | a / 100 == 0 | a / 10 == 0)
        return -1; //проверка на правильность введенных значений.
    int n_3 = a % 10; //третья цифра
    int n_2 = a / 10 % 10;//вторая цифра
    int n_1 = a / 100;//первая цифра
    if (n_1 > x && n_2 > x && n_3 > x) {//если все цифры больше х
        return a - 100; //уменьшаем а на 100
    } else if (n_1 > x && n_2 > x) { //если только первая и вторая цифры больше х
        return a + 100; //увеличиваем а на 100
    } else if (n_1 < x && n_2 < x && n_3 < x) {//если все цифры меньше х
        return a - 50; //уменьшаем а на 50
    } else if (n_2 < x && n_3 < x) { //если только третья и вторая цифры меньше х
        return a + 50; //увеличиваем а на 50
    }
    return a + 10; //т к return выполняется в функции 1 раз, else можем не писать. В ост. случаях увеличим а на 10
}


void task6(float x) {
    if (abs(x) == 4 |
        x == 2) { //это следует из того, что x^2 - 16 != 0 и x^2 -4x + 4 != 0 т к эти выражения в знаменателях
        std::cout << "Division by zero";
    } else if (x <
               -5) { // это следует из того, что x + 5 >= 0 так как выражение стоит под корнем. Выражение x^2 -4x + 4 меньше 0 быть не может
        std::cout << "The root of a negative number";
    } else if (x <= 1 && x >= -1) { // это следует из того, что x^2 - 1 > 0 так как выражение стоит в логарифме
        std::cout << "The logarithm of a non-positive number";
    } else { //если х попал в ОДЗ просто считаем пример, соблюдая порядок операций
        float result = sin(log(x * x - 1)) / (x * x - 16) + sqrt(x + 5) / sqrt(x * x - 4 * x + 4);
        std::cout << result;
    }
}


void task14() {
    std::cout << "Choose a figure: 1 - circle, 2 -  square,  3 - triangle,  4 - rectangle"
              << std::endl; //Соотношение введенного номера и фигуры
    int task; // Номер фигуры
    float Area, Per; //Будущие ответы - площадь и периметр
    std::cin >> task;// Вводим номер фигуры
    switch (task) {
        case 1: {
            std::cout << "Your choice is circle" << std::endl;//Круг
            std::cout << "Input radius" << std::endl;
            int R;// Радиус круга
            std::cin >> R;//Вводим радиус
            Area = M_PI * R * R; //Считаем площадь по формуле П * R^2
            Per = 2 * M_PI * R;//Считаем периметр по формуле 2 * П * R
            break;
        }
        case 2: {
            std::cout << "Your choice is square" << std::endl;// Квадрат
            std::cout << "Input side" << std::endl;
            int a;// Сторона квадрата
            std::cin >> a;// Вводим сторону
            Area = a * a; // Площадь квадрата это квадрат его стороны
            Per = 4 * a;// Периметр - сумма сторон
            break;
        }
        case 3: {
            std::cout << "Your choice is triangle" << std::endl; // Треугольник
            std::cout << "Input the base of the triangle, height to base and sides" << std::endl;
            int h, a_b, a2, a3; //Высота, проведенная к основанию, основание и две другие стороны
            std::cout << "H: " << std::endl;;
            std::cin >> h;// Вводим высоту
            std::cout << "Base of the triangle: " << std::endl;;
            std::cin >> a_b;// Вводим основание
            std::cout << "side 2: " << std::endl;;;
            std::cin >> a2;// Вводим вторую сторону
            std::cout << "side 3: " << std::endl;;;
            std::cin >> a3;// Вводим третью сторону
            Area = 0.5 * a_b * h; //Площадь это 1/2 * a * h
            Per = a_b + a2 + a3; // Периметр - сумма сторон
            break;
        }
        case 4: {
            std::cout << "Your choice is rectangle" << std::endl;// Прямоугольник
            int a, b; //Стороны прямоугольника
            std::cout << "Input side1 and side2" << std::endl;
            std::cout << "a: " << std::endl;;
            std::cin >> a; // Сторона а
            std::cout << "b: " << std::endl;;
            std::cin >> b;// Сторона b
            Area = a * b; //Площадь - произведение сторон прямоугольника
            Per = 2 * (a + b);// Периметр - сумма сторон
            break;
        }
        default: { // Если введен неверный номер выводим сообщение об ошибке
            std::cout << "Incorrect number!";
            Area = -1;
            Per = -1;
        }
    }
    std::cout << "The area of the figure: " << Area << std::endl; //Выводим площадь
    std::cout << "Perimeter: " << Per << std::endl;//Выводим периметр
}


void task18() {
    std::cout << "Input the coefficients of a straight line: A1, B1, C1: " << std::endl;;
    int a1, b1, c1; //Задаем уравнение первой прямой (y * b1 + a1 * x + c1 = 0)
    std::cin >> a1 >> b1 >> c1;
    std::cout << "Input the coefficients of a straight line: A2, B2, C2: " << std::endl;;
    int a2, b2, c2;//Задаем уравнение второй прямой (y * b2 + a2 * x + c2 = 0)
    std::cin >> a2 >> b2 >> c2;
    if (a1 == 0 && a2 == 0 && b1 == 0 &&
        b2 == 0) { //Если коэффициенты возле x и y равны нулю это не уравнение прямой (оба уравнения не прямых)
        std::cout << "There are not straight lines" << std::endl;
    } else if (a1 == 0 && b1 ==
                          0) { //Если коэффициенты возле x и y равны нулю это не уравнение прямой (первое уравнение не прямой)
        std::cout << "The 1 not straight line" << std::endl;
    } else if (a2 == 0 && b2 ==
                          0) { //Если коэффициенты возле x и y равны нулю это не уравнение прямой (второе уравнение не прямой)
        std::cout << "The 2 not straight line" << std::endl;
    } else if ((float(a2) / a1) == (float(b2) / b1) && (float(a2) / a1) == (float(c2) /
                                                                            c1)) { // Если отношения коэффициентов двух прямых равны, то они совпадают
        // например 2y + x + 1 = 0 и 4y + 2x + 2 = 0. Во втором можем всё поделить на 2, и получим первое уравнение
        std::cout << "The straight lines match" << std::endl;
    } else if ((float(a1) / b1 == float(a2) / b2) | (a1 == a2 && a1 == 0) |
               (b1 == b2 && b1 == 0)) { // Если представить уравнение прямой в
        // виде y = kx + b, где k в нашем случае a / b, то при
        // совпадении k у двух прямых, считается что они параллельны. Если a1 = a2 = 0 или b1 = b2 = 0 они также парал-ны.
        std::cout << "The straight lines are parallel" << std::endl;
    } else {
        float kx, kc, k2x, k2c, x, y;// Задаем вспомогательные переменные для решения системы уравнений, а также x и y - ответ на задачу
        if (b1 != 0 && b2 != 0) { //Если возле y стоит коэф. отличный от нуля
            kx = float(a1) / b1; // Делим коэф. возле х и свободный член на b1
            kc = float(c1) / b1;
            k2x = float(a2) / b2; // Тоже только для второй прямой. Получаем два уравнение вида y = kx + b
            k2c = float(c2) / b2;
            float tmp1 = kx - k2x;// Приравниваем обе части и переносим неизвестные влево, известные вправо
            float tmp2 = k2c - kc;
            x = tmp2 / tmp1; //Находим x
            y = (-a1 * x - c1) / b1; // Подставив в одно из уравнений х находим y
        } else if (b1 == 0 && b2 != 0) { //Если возле y стоит коэф. равный 0
            x = float(-c1) / a1; // Сразу находим x (так как уравнение имеет вид 0 = kx + b, x = -b / k)
            y = (-a2 * x - c2) / float(b2);// Подставив в другое уравнение х находим y
        } else {
            x = float(-c2) / a2; //Аналогично, только для другой прямой
            y = (-a1 * x - c1) / float(b1);
        }
        std::cout << x << " "; // Выводим x
        std::cout << y; // Выводим y
    }
}


int main() {
    std::cout << "Choose task (1-4)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            std::cout << "Input two numbers" << std::endl;
            float x, y;
            std::cin >> x >> y; //Вводим два значения
            std::cout << "First task: " << task2(y, x) << std::endl; //выполняем задачу
            break;
        }
        case 2: { // аналогично с остальными задачами
            std::cout << "2 task" << std::endl;
            std::cout << "Input number" << std::endl;
            int x;
            std::cin >> x;
            task6(x);
            break;
        }
        case 3: {
            std::cout << "3 task" << std::endl;
            task14();
            break;
        }
        case 4: {
            std::cout << "4 task" << std::endl;
            task18();
            break;
        }
        default: {
            std::cout << "Wrong number of task!";
            break;
        }
    }
    return 0;
}