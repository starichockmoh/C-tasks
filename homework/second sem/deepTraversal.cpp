#include <iostream>
#include <vector>

struct stack {
    int inf;
    stack *next;
};
void push(stack *&h, int x) {
    auto *r = new stack; //создаем новый элемент
    r->inf = x;  //поле inf = x
    r->next = h;  //следующим элементов является h
    h = r; //теперь r является головой
}


int pop(stack *&h) {
    int i = h->inf; //значение первого элемента
    stack *r = h; //указатель на голову стека
    h = h->next; //переносим указатель на следующий элемент
    delete r; //удаляем первый элемент
    return i; //возвращаем значение
}


std::vector<std::vector<int>> CreateList(int n) {
    std::vector<std::vector<int>> List; //список смежности
    for (int i = 0; i < n; ++i) {
        std::vector<int> tmp;
        int counter;
        std::cout << "Input count of vertex " << i << ":" <<std::endl;
        std::cin >> counter;
        for (int j = 0; j < counter; ++j) {
            int x;
            std::cin >> x;
            tmp.push_back(x);
        }
        List.push_back(tmp);

    }
    std::cout << std::endl;
    return List;
}

void PrintList(const std::vector<std::vector<int>>& List) {
    std::cout << "Your list:" << std::endl;
    for (auto & i : List) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    int n; //количество вершин
    std::vector<std::vector<int>> List; //список смежности
    std::vector<int> Arr;
    std::cout << "Input count of vertexes: " << std::endl;
    std::cin >> n;
    List = CreateList(n);
    PrintList(List);

    stack *Stack = nullptr;
    for (int i = 0; i < n; ++i){
        Arr.push_back(0);
    }
    Arr[0] = 1; //присваиваем Arr[x] = 1 (помечаем вершину x как посещенную);
    push(Stack,0); //помещаем вершину x в стек;
    std::cout << 0 << " "; //выводим ее на экран
    while (Stack) { //пока стек не пустой
        bool fl = false; // флаг, что вершина текущая
        int x = Stack->inf;
        int y;
        for (int i = 0; i < List[x].size(); ++i){
            if (Arr[List[x][i]] == 0){ //если еще не посетили
                y = List[x][i];
                fl = true;
                break;
            }
        }
        if (fl) {
            Arr[y] = 1; //ставим посещение
            push(Stack, y); //переключаемся на новую вершину
            std::cout << y << " ";
        } else {
            pop(Stack); //возвращаемся на предыдущую вершину
        }
    }
    return 0;
}

