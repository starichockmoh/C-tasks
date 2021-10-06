#include <iostream> //библиотека для потока ввода-вывода


void task18() {
    std::cout << "Input the coefficients of a straight line: A1, B1, C1: (separated by a space)" << std::endl;;
    int a1, b1, c1; //Задаем уравнение первой прямой (y * b1 + a1 * x + c1 = 0)
    std::cin >> a1 >> b1 >> c1;
    std::cout << "Input the coefficients of a straight line: A2, B2, C2: (separated by a space)"<< std::endl;;
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
    task18();
    return 0;
}