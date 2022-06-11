#include <iostream>

template <typename T>
struct List {
    T data;
    List* next;
    List* prev;
};

template <typename T>
void push(List<T>*& h, List<T>*& t, T x) {
    List<T>* n = new List<T>();
    n->data = x;
    n->next = nullptr;
    if (h == nullptr && t == nullptr) {
        n->prev = nullptr;
        h = n;
    }
    else {
        t->next = n;
        n->prev = t;
    }
    t = n;
}

template <typename T>
void remove(List<T>*& h, List<T>*& t, List<T>* r) {
    if (r == h && r == t) {
        h = t = nullptr;
    }
    else if (r == h) {
        h = h->next;
        h->prev = nullptr;
    }
    else if (r == t) {
        t = t->prev;
        t->next = nullptr;
    }
    else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

template <typename T>
std::ostream& operator<<(std::ostream& s, List<T>* h) {
    if (h == nullptr) {
        return s << "[]";
    }
    List<T>* ptr = h;
    s << "[";
    while (ptr->next != nullptr) {
        s << ptr->data << ", ";
        ptr = ptr->next;
    }
    return s << ptr->data << "]";
}

template <typename T>
void print(std::ostream& s, List<T>* h, List<T>* t) {
    if (h == nullptr) {
        s << "[]";
    }
    List<T>* ptr = h;
    s << "[";
    while (ptr->next != t) {
        s << ptr->data << ", ";
        ptr = ptr->next;
    }
    s << ptr->data << "]";
}

template <typename T>
void insert(List<T>*& h, List<T>*& t, List<T>* r, T y) {
    List<T>* p = new List<T>();
    p->data = y;
    if (r == t) {
        p->next = nullptr;
        p->prev = r;
        r->next = p;
        t = p;
    }
    else {
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}