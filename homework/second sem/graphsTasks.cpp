#include <iostream>
#include <vector>
#include <algorithm>    // std::find

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

static std::vector<int> pr;
static std::vector<int> used;
static std::vector<std::vector<int>> cycles;
static std::vector<std::vector<int>> sort_cycles;
static std::vector<std::vector<int>> Gr;


void add_cycles(int start, int end) {
    int cur = end;
    std::vector<int> tmp;
    while (cur != start) {
        tmp.push_back(cur);
        cur = pr[cur];
    }
    tmp.push_back(start);
    std::vector<int> tmpRev;
    std::reverse(tmp.begin(), tmp.end());
    for(auto e : tmp) tmpRev.push_back(e);
    cycles.push_back(tmpRev);
    std::sort(tmpRev.begin(), tmpRev.end());
    sort_cycles.push_back(tmpRev);
}

void find_cycle(int x) {
    used[x] = 1;
    for (int i = 0; i < Gr[x].size(); ++i){
        if (pr[Gr[x][i]] == x) {
            break;
        }
        if (used[Gr[x][i]] == 0) {
            pr[Gr[x][i]] = x;
            find_cycle(Gr[x][i]);
        } else {
            add_cycles(Gr[x][i], x);
        }
    }
    used[x] = 0;
}

int main() {
    int n; //количество вершин
    std::vector<std::vector<int>> List; //список смежности
    std::cout << "Input count of vertexes: " << std::endl;
    std::cin >> n;
    List = CreateList(n); //создание списка смежности
    PrintList(List);


    // Task 1
    std::cout << "Input vertex:" << std::endl;
    int vertex;
    std::cin >> vertex;
    for (int i : List[vertex]) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Task 2
    std::cout << "Input vertexes:" << std::endl;
    int vertexA, vertexB;
    std::cin >> vertexA >> vertexB;
    std::vector<int>::iterator it; //проверяем связаны ли вершины
    it = find (List[vertexA].begin(), List[vertexA].end(), vertexB);
    if (it != List[vertexA].end())
        std::cout << "vertexes already together" << std::endl;
    else {
        List[vertexA].push_back(vertexB); //создаем ребро
        List[vertexB].push_back(vertexA);
    }
    PrintList(List);

    // Task 3
    for (int i = 0; i < List.size(); ++i) {
        std::cout << "Vertex" << i << " :" << List[i].size() << std::endl;
    }

    //Task 4
    stack *Stack = nullptr;
    for (int i = 0; i < n; ++i){
        used.push_back(0);
        pr.push_back(-1);
    }
    Gr = CreateList(n); //создание списка смежности
    used[0] = 1; //присваиваем Arr[x] = 1 (помечаем вершину x как посещенную);
    push(Stack,0); //помещаем вершину x в стек;
    std::cout << 0 << " "; //выводим ее на экран
    while (Stack) { //пока стек не пустой
        bool fl = false; // флаг, что вершина текущая
        int x = Stack->inf;
        int y;

        for (int i = 0; i < Gr[x].size(); ++i){
            if (used[Gr[x][i]] == 0){ //если еще не посетили
                y = Gr[x][i];
                fl = true;
                break;
            }
        }
        if (fl) {
            used[y] = 1; //ставим посещение
            push(Stack, y); //переключаемся на новую вершину
            std::cout << y << " ";
        } else {
            pop(Stack); //возвращаемся на предыдущую вершину
        }
    }


    //Task 5
//    int n1; //количество вершин
//    std::vector<std::vector<int>> List1; //список смежности
//    std::vector<int> Arr;
//    std::cout << "Input count of vertexes: " << std::endl;
//    std::cin >> n;
//    List = CreateList(n);
//    PrintList(List);
//
//    queue *head = nullptr;
//    queue *tail = nullptr;
//    for (int i = 0; i < n; ++i){
//        Arr.push_back(0);
//    }
//    Arr[0] = 1; //присваиваем Arr[x] = 1 (помечаем вершину x как посещенную);
//    push(head,tail,0);
//    std::cout << 0 << " "; //выводим ее на экран
//    while (head) {
//        int x = pop(head,tail);
//        int y;
//        for (int i = 0; i < List1[x].size(); ++i){
//            if (Arr[List1[x][i]] == 0){ //если еще не посетили
//                y = List1[x][i];
//                Arr[y] = 1;
//                push(head,tail,y);
//                std::cout << y << " "; //выводим ее на экран
//            }
//        }
//    }


    return 0;
}