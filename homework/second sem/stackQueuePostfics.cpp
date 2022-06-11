#include <iostream>
#include <stack>
#include <string>
#include <vector>


float doOperation(char op, float op1, float op2) { //функция для подсчета арифм операций
    switch (op) {
        case '+': {
            return op1 + op2;
        }
        case '*': {
            return op1 * op2;
        }
        case '-': {
            return op1 - op2;
        }
        case '/': {
            return op1 / op2;
        }
        default:
            break;
    }
}

int main() {
    std::stack<float> Stack; //структура стек
    std::string str;
    std::string tmp;
    std::cout << "Input math expression: " << std::endl;
    std::getline(std::cin, str);
    for (int i = 0; i < str.size(); ++i) {

        //Идем по строке, анализируем символы
        // если встречается операция, то совершаем ее над двумя вверхними элеметами
        // и записываем в стек, иначе просто записываем число в стек

        if (str[i] != ' ') tmp += str[i];
        else {
            if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/") {
                float oper2 = Stack.top();
                Stack.pop();
                float oper1 = Stack.top();
                Stack.pop();
                char oper = tmp[0];
                float result = doOperation(oper, oper1, oper2);
                Stack.push(result);
            } else {
                float value = stoi(tmp);
                Stack.push(value);
            }
            tmp.clear();
        }
    }
    float oper2 = Stack.top();
    Stack.pop();
    float oper1 = Stack.top();
    Stack.pop();
    char oper = tmp[0];
    float result = doOperation(oper, oper1, oper2);
    Stack.push(result);

    std::cout << Stack.top();


    return 0;
}

//17 10 + 3 * 9 /
//7 8 + 3 2 + /