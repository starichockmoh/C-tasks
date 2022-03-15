#include <iostream>


struct list {
    int inf;
    list *next;
    list *prev;
};


void push(list *&h, list *&t, int x) { //вставка элемента в конец списка
    list *r = new list; //создаем новый элемент
    r->inf = x;
    r->next = nullptr; //всегда последний
    if (!h && !t) { //если список пуст
        r->prev = nullptr; //первый элемент
        h = r; //это голова
    } else {
        t->next = r; //r - следующий для хвоста
        r->prev = t; //хвост - предыдущий для r
    }
    t = r; //r теперь хвост
}


void print_rev(list *h, list *t) { //печать элементов списка в обратном порядке
    list *p = t; //укзатель на хвост
    while (p) { //пока не дошли до конца списка
        std::cout << p->inf << " ";
        p = p->prev; //переход к предыдущему элементу
    }
}

void print(list *h, list *t) { //печать элементов списка
    list *p = h; //укзатель на голову
    while (p) { //пока не дошли до конца списка
        std::cout << p->inf << " ";
        p = p->next; //переход к следующему элементу
    }
}

int find(list *h, list *t) { //поиск элементов списка
    int last;
    list *p = h; //укзатель на голову
    while (p) { //пока не дошли до конца списка
        if (p->inf % 2 == 0) last = p->inf; // если нашли, прекращаем цикл
        p = p->next; //переход к следующему элементу
    }
    return last; //возвращаем последний четный
}

void del_node(list *&h, list *&t) { //удаляем после r
    list *Min = nullptr;
    list *p = h; //указатель на голову
    while (p) {
        if (!Min || p->inf < Min->inf) Min = p;
        p = p->next;
    }
    if (Min == h && Min == t) //единственный элемент списка
        h = t = nullptr;
    else if (Min == h) { //удаляем голову списка
        h = h->next; //сдвигаем голову
        h->prev = nullptr;
    } else if (Min == t) { //удаляем хвост списка
        t = t->prev; //сдвигаем хвост
        t->next = nullptr;
    } else {
        Min->next->prev = Min->prev; //для следующего от r предыдущим становится r->prev
        Min->prev->next = Min->next; //для предыдущего от r следующим становится r->next
    }
    delete Min; //удаляем r
}


void insert_after(list *&h, list *&t) { //вставляем после r
    list *Max = nullptr;
    int y = 0;
    list *p1 = h; //указатель на голову
    while (p1) {
        if (!Max || p1->inf >= Max->inf) Max = p1;
        p1 = p1->next;
    }


    list *p = new list; //создаем новый элемент
    p->inf = y;
    if (Max == t) { //если вставляем после хвоста
        p->next = nullptr; //вставляемый эл-т - последний
        p->prev = Max; //вставляем после r
        Max->next = p;
        t = p; //теперь хвост - p
    } else { //вставляем в середину списка
        Max->next->prev = p; //для следующего за r эл-та предыдущий - p
        p->next = Max->next; //следующий за p - следующий за r
        p->prev = Max; //p вставляем после r
        Max->next = p;
    }
}


int main() {
    int n, x;
    std::cout << "Input n" << std::endl;
    std::cin >> n;
    list *head = nullptr;
    list *tail = nullptr;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        push(head, tail, x);
    }
    print_rev(head, tail);
    std::cout << std::endl;
    std::cout << find(head, tail) << std::endl;
    del_node(head, tail);
    print(head, tail);
    std::cout << std::endl;
    insert_after(head,tail);
    print(head,tail);
    return 0;
}