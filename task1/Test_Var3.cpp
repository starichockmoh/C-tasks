#include <iostream>
#include <vector>


bool IsPrime(int n) { //вспомогательная функция для определения является ли число простым
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}


void task1() {
    int s = 0;//сумма простых чисел
    for (int i = 10; i <= 99; ++i) {
        if (IsPrime(i)) {//если число простое то прибавляем его
            s += i;
        }
    }
    std::cout << s << std::endl;
}


void task2(double x, double eps) {
    int N = 100000;//делаем операцию 100 раз (должно хватить для точного результата)
    double a = -((x+1) * (x+1));//элемент соотношений
    double S = a;// сумма элементов
    for (int i = 2; i < N; i++){// делаем сто тыс раз
        a *= ((-((x+1) * (x+1))) / i); // an = d * an-1 (в данном случае d равно -(x+1)^2 / n)
        S += a;
    }
    std::cout << "result Sum : " << S << std::endl;
}


void task3(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) { //проверка что нет неположительных чисел
        std::cout << "the number cannot be negative" << std::endl;
    } else if ((a + b) <= c || (a + c) <= b || (b + c) <= a) {
        std::cout << "the side of the triangle is greater than the sum of the others" << std::endl;
    } else {
        std::cout << "ok" << std::endl;
    }
}

void task4(int n, float a, float b) {// (a;b)
    std::vector<float> Arr(n);
    float s = 0;
    std::cout << "Input Array:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> Arr[i];
    }
    for (int i = 0; i < n; ++i) {
        if (Arr[i] <= a || Arr[i] >= b) {
            s += Arr[i];
        }
    }
    std::cout << s << std::endl;
}

void task5() { //ответ 0
    float S = 0;
    for (int i = 2; i <= 6; i++)
        S += 1 / i;
    std::cout << S;
}

void task6(float a, float b, float h) {
    float i = a;
    do {
        std::cout << i << " ";
        i += h;
    } while (i <= b);
}


//task 7
/*
    int main(){
        int n;
        cin >> n;
        int a = new int [n]; // int *a так как мы объявляем массив
        int S = 0;
        for(int i = 0; i <= n; i++) // i < n (так как всего элементов n штук)
            cin >> a[i];
        S += a[i]; // нужно поставить {} после for и включить в блок данную строку
        cout << S;
        return 0;
    }
*/

int main() {
    std::cout << "Choose task (1-6)" << std::endl; // реализуем выбор задачи
    int task;
    std::cin >> task; //выбираем задачу с ввода
    switch (task) { // смотрим какую задачу выбрали
        case 1: { //первая задача (номер 2 в пдф)
            std::cout << "1 task " << std::endl;
            task1();
            break;
        };
        case 2: { // аналогично с остальными задачами
            double x;
            double eps;
            std::cout << "2 task " << std::endl;
            std::cout << "Enter x" << std::endl;
            std::cin >> x;
            std::cout << "Enter eps" << std::endl;
            std::cin >> eps;
            task2(x, eps);
            break;
        };
        case 3: {
            std::cout << "3 task " << std::endl;
            int a, b, c;
            std::cout << "Input a,b,c" << std::endl;
            std::cin >> a >> b >> c;
            task3(a, b, c);
            break;
        };
        case 4: {
            std::cout << "4 task " << std::endl;
            std::cout << "Input array`s length" << std::endl;
            float a, b;
            int n;
            std::cin >> n;
            std::cout << "Input a, b (interval (a;b) a <= b)" << std::endl;
            std::cin >> a >> b;
            if (a > b) {
                std::cout << "a > b !";
            } else {
                task4(n, a, b);
            }
            break;
        };
        case 5: {
            std::cout << "5 task " << std::endl;
            task5();
            break;
        }
        case 6: {
            std::cout << "6 task " << std::endl;
            std::cout << "Input a, b, h" << std::endl;
            float a, b, h;
            std::cin >> a >> b >> h;
            task6(a, b, h);
            break;
        }
        default: {
            std::cout << "Wrong number of task!";
            break;
        };
    }
    return 0;
};