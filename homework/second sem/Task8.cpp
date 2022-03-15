#include <iostream>
#include <string>


template<class QueueType>
struct queue {
    QueueType inf;
    queue *next;
};

template<class QueueType>
void push_q(queue<QueueType> *&h, queue<QueueType> *&t, QueueType x) { //вставка элемента в очередь
    auto *r = new queue<QueueType>; //создаем новый элемент
    r->inf = x;
    r->next = nullptr; //всегда последний
    if (!h && !t) { //если очередь пуста
        h = t = r; //это и голова и хвост
    } else {
        t->next = r; //r - следующий для хвоста
        t = r; //теперь r - хвост
    }
}


template<class QueueType>
QueueType pop_q(queue<QueueType> *&h, queue<QueueType> *&t) { //удаление элемента из очереди
    queue<QueueType> *r = h; //создаем указатель на голову
    int i = h->inf; //сохраняем значение головы
    h = h->next; //сдвигаем указатель на следующий элемент
    if (!h) //если удаляем последний элемент из очереди
        t = nullptr;
    delete r; //удаляем первый элемент
    return i;
}


template<class StackType>
struct stack {
    StackType inf;
    stack *next;
};

template<class StackType>
void push(stack<StackType> *&h, StackType x) {
    auto *r = new stack<StackType>;; //создаем новый элемент
    r->inf = x;  //поле inf = x
    r->next = h;  //следующим элементов является h
    h = r; //теперь r является головой
}

template<class StackType>
StackType pop(stack<StackType> *&h) {
    StackType i = h->inf; //значение первого элемента
    stack<StackType> *r = h; //указатель на голову стека
    h = h->next; //переносим указатель на следующий элемент
    delete r; //удаляем первый элемент
    return i; //возвращаем значение
}

template<class StackType>
void reverse(stack<StackType> *&h) { //"обращение"стека
    stack<StackType> *head1 = nullptr; //инициализация буферного стека
    while (h) //пока стек не пуст
        push(head1, pop(h)); //переписываем из одного стека в другой
    h = head1; //переобозначим указатели
}


stack<std::string> *task1(stack<std::string> *&h, std::string symbol) {
    stack<std::string> *res = nullptr;
    while (h) {
        std::string str = pop(h);
        if (str[str.size() - 1] != symbol[0]) {
            push(res, str);
        }
    }
    return res;
}

stack<int> *task6(stack<int> *&h) {
    stack<int> *copy = nullptr;
    stack<int> *res = nullptr;
    int Max = 0;
    while (h) {
        int tmp = pop(h);
        push(copy, tmp);
        if (tmp > Max) Max = tmp;
    }
    while (copy) {
        int tmp = pop(copy);
        if (tmp < Max) push(res, tmp);
    }
    reverse(res);
    return res;
}

void task14(queue<char> *&head,queue<char> *&tail) {
    queue<char> *res_h = nullptr;
    queue<char> *res_t = nullptr;
    while (head) {
        char tmp = pop_q(head,tail);
        if (std::isdigit(tmp) || std::isalpha(tmp)) push_q(res_h, res_t, tmp);
    }
    while (res_h) std::cout << pop_q(res_h,res_t) << " ";
}

void task16(queue<int> *&head,queue<int> *&tail) {
    queue<int> *res_h = nullptr;
    queue<int> *res_t = nullptr;

    queue<int> *copy_h = nullptr;
    queue<int> *copy_t = nullptr;

    int Min = 100000000;
    int Max = 0;
    while (head) {
        int tmp = pop_q(head,tail);
        if (tmp < Min) {
            Min = tmp;
        }
        if (tmp > Max) {
            Max = tmp;
        }
        push_q(copy_h, copy_t, tmp);
    }
    while (copy_h) {
        int tmp = pop_q(copy_h,copy_t);
        if (tmp == Max) {
            push_q(res_h,res_t,Min);
        }
        push_q(res_h,res_t,tmp);
    }
    while (res_h) std::cout << pop_q(res_h,res_t) << " ";
}

int main() {
    std::cout << "Input number of a task:" << std::endl;
    int task_n;
    std::cin >> task_n;
    switch (task_n) {
        case 1: {
            int n;
            std::string str, symbol;
            stack<std::string> *head = nullptr;
            std::cout << "n = " << std::endl;
            std::cin >> n;
            std::cout << "symbol: " << std::endl;
            std::cin >> symbol;
            std::cin.clear();
            for (int i = 0; i < n; ++i) {
                std::getline(std::cin, str);
                push(head, str);
            }
            stack<std::string> *res = task1(head, symbol); //результат
            while (res) std::cout << pop(res) << " "; //выводим на экран
            std::cout << std::endl;
            break;
        }
        case 2: {
            int n;
            int x;
            stack<int> *head = nullptr;
            std::cout << " n = " << std::endl;
            std::cin >> n;
            for (int i = 0; i < n; ++i) {
                std::cin >> x;
                push(head, x);
            }
            stack<int> *res = task6(head);
            while (res) std::cout << pop(res) << " "; //выводим на экран
            std::cout << std::endl;
            break;
        }
        case 3: {
            int n;
            char x;
            queue<char> *head = nullptr;
            queue<char> *tail = nullptr;
            std::cout << "n = " << std::endl;
            std::cin >> n;
            for (int i = 0; i < n; ++i) {
                std::cin >> x;
                push_q(head,tail, x);
            }
            task14(head,tail);
            break;
        }
        case 4: {
            int n;
            int x;
            queue<int> *head = nullptr;
            queue<int> *tail = nullptr;
            std::cout << "n = " << std::endl;
            std::cin >> n;
            for (int i = 0; i < n; ++i) {
                std::cin >> x;
                push_q(head,tail, x);
            }
            task16(head,tail);
            break;
        }
        default: {
            std::cout << "Wrong number of a task" << std::endl;
            break;
        }


    }
    return 0;
}
