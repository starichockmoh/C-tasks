#include <iostream> //библиотека для потока ввода-вывода


void task1(float x, float y){
    if (x < 0 || y < 0 || x > 70 || y > 70) {
        std::cout << "No";
    } else if (x == y || (x == 70 && y <= 70) || (y == 0 && x <= 70)){
        std::cout << "On the border";
    } else if (y < x) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
}


void task2(char transport) {
    switch (transport) {
        case 'a':
            std::cout << "1228 km/hour";
            break;
        case 'b':
            std::cout << "268 km/hour";
            break;
        case 'm':
            std::cout << "402 km/hour";
            break;
        case 'p':
            std::cout << "3529.56 km/hour";
            break;
        case 't':
            std::cout << "603 km/hour";
            break;
        default:
            std::cout << "Wrong char!";
            break;
    }
}


void task3(int a, int b) {
    for (int i = a; i <= b; i += 1) {
        if (i > 0) std::cout << i << std::endl;
    }
}

void task4() {
    for (int i = 0; i <= 4; i += 1){
        for (int j = 0; j <= 4 - i; j += 1){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}



int main() {
    std::cout << "Choose task (1-4)" << std::endl;
    int task;
    std::cin >> task;
    switch (task) {
        case 1:
            float x, y;
            std::cout << "Print x" << std::endl;
            std::cin >> x;
            std::cout << "Print y" << std::endl;
            std::cin >> y;
            task1(x,y);
            break;
        case 2:
            char transport;
            std::cout << "Choose transport: a - automobile, b - bicycle, m - motorcycle, p - plane, t - train" << std::endl;
            std::cin >> transport;
            task2(transport);
            break;
        case 3:
            int a, b;
            std::cout << "Print a, b" << std::endl;
            std::cin >> a >> b;
            task3(a, b);
            break;
        case 4:
            task4();
    }
    return 0;
}