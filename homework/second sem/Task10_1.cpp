#include <iostream>
#include <vector>


struct queue {
    int inf;
    queue *next;
};


void push(queue *&h, queue *&t, int x) { //вставка элемента в очередь
    auto *r = new queue; //создаем новый элемент
    r->inf = x;
    r->next = nullptr; //всегда последний
    if (!h && !t) { //если очередь пуста
        h = t = r; //это и голова и хвост
    } else {
        t->next = r; //r - следующий для хвоста
        t = r; //теперь r - хвост
    }
}


int pop(queue *&h, queue *&t) { //удаление элемента из очереди
    queue *r = h; //создаем указатель на голову
    int i = h->inf; //сохраняем значение головы
    h = h->next; //сдвигаем указатель на следующий элемент
    if (!h) //если удаляем последний элемент из очереди
        t = nullptr;
    delete r; //удаляем первый элемент
    return i;
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

    queue *head = nullptr;
    queue *tail = nullptr;
    for (int i = 0; i < n; ++i){
        Arr.push_back(0);
    }
    Arr[0] = 1; //присваиваем Arr[x] = 1 (помечаем вершину x как посещенную);
    push(head,tail,0);
    std::cout << 0 << " "; //выводим ее на экран
    while (head) {
        int x = pop(head,tail);
        int y;
        for (int i = 0; i < List[x].size(); ++i){
            if (Arr[List[x][i]] == 0){ //если еще не посетили
                y = List[x][i];
                Arr[y] = 1;
                push(head,tail,y);
                std::cout << y << " "; //выводим ее на экран
            }
        }
    }
}