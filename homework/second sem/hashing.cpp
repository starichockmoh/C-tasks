#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>


std::ifstream in("input.txt");

struct date {//дата
    int dd, mm, yy;
};


struct people {//данные о человеке
    std::string Surname; //фамилия
    date DateOfBirth{}; //дата рождения
    std::string Post;
    int Exp{};
    int Salary{}; //зарплата
};

struct ListNode {
    people inf;
    ListNode *next;
    ListNode *prev;
};

struct List {
    ListNode *head;
    ListNode *tail;
};


void push(ListNode *&h, ListNode *&t, people x) { //вставка элемента в конец списка
    ListNode *r = new ListNode; //создаем новый элемент
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


void printPeople(people x) {//вывод в файл
    std::cout << std::setw(10) << std::left << x.Surname;//по левому краю, 10 позиций для фамилии
    std::cout << std::left << std::setw(24) << x.Post;//на должность 24 позиции
    if (x.DateOfBirth.dd < 10) std::cout << std::left << '0' << x.DateOfBirth.dd << '.';//добавляем 0
    else std::cout << std::left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10) std::cout << '0' << x.DateOfBirth.mm << '.';
    else std::cout << x.DateOfBirth.mm << '.';
    std::cout << std::left << std::setw(6) << x.DateOfBirth.yy;//на год 6 позиций
    std::cout << std::left << std::setw(10) << x.Exp;//Стаж
    std::cout << std::left << std::setw(10) << x.Salary << std::endl;//запрлата
}

void print (ListNode *h, ListNode *t){ //печать элементов списка
    ListNode *p = h; //укзатель на голову
    while (p){ //пока не дошли до конца списка
        printPeople(p->inf);
        p = p->next; //переход к следующему элементу
    }
}


ListNode* find(ListNode *h, ListNode *t, std::string surname){ //печать элементов списка
    ListNode *p = h; //укзатель на голову
    while (p != t){ //пока не дошли до конца списка
        if (p->inf.Surname == surname) break; // если нашли, прекращаем цикл
        p = p->next; //переход к следующему элементу
    }
    return p; //возвращаем указатель
}


void del_node (ListNode *&h, ListNode *&t, ListNode *r){ //удаляем после r
    if (r == h && r == t) //единственный элемент списка
        h = t = NULL;
    else if (r == h){ //удаляем голову списка
        h = h->next; //сдвигаем голову
        h->prev = NULL;
    }
    else if (r == t){ //удаляем хвост списка
        t = t->prev; //сдвигаем хвост
        t->next = NULL;
    }
    else{
        r->next->prev = r->prev; //для следующего от r предыдущим
        r->prev->next = r->next; //для предыдущего от r следующим
    }
    delete r; //удаляем r
}


date Str_to_Date(std::string str) {//из строки в дату
    date x;
    std::string temp = str.substr(0, 2);//день
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2);//месяц
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4);//год
    x.yy = atoi(temp.c_str());
    return x;
}

std::vector<people> inFile() {//ввод из файла
    std::vector<people> x;
    people temp;
    while (in.peek() != EOF) {
        in >> temp.Surname;//фамилия
        in >> temp.Post;
        std::string tmp;//дата рождения
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.Exp;
        in >> temp.Salary;//зарплата
        x.push_back(temp);
    }
    return x;
}


int hashing(int x) {
    return x % 11; // метод деления, соответсвенно размерность - 11
}



int main() {
    std::vector<List> hashTable;
    std::vector<people> peopleArray;
    peopleArray = inFile();

    for (int i = 0; i < 11; ++i) {
        List *tmp = new List;
        tmp->tail = nullptr;
        tmp->head = nullptr;
        hashTable.push_back(*tmp);
    }


    for (int i = 0; i < peopleArray.size(); ++i){
        int hashValue = hashing(peopleArray[i].Exp);
        push(hashTable[hashValue].head, hashTable[hashValue].tail, peopleArray[i]);
    }


    for (int i = 0; i < hashTable.size(); ++i) {
        std::cout << '[' << i << ']' << ':' << std::endl;
        std::cout << '[' << std::endl;
        print(hashTable[i].head, hashTable[i].tail);
        std::cout << ']' << std::endl;
    }

    std::cout << "Input surname: " << std::endl;
    std::string surname;
    std::cin.clear();
    std::getline(std::cin, surname);
    std::cout << "Input experience: " << std::endl;
    int exp;
    std::cin >> exp;
    int hashExp = hashing(exp);

    ListNode* foundedPeople = find(hashTable[hashExp].head,hashTable[hashExp].tail, surname);
    if (foundedPeople->inf.Surname == surname) {
        std::cout << "Founded people: " << std::endl;
        printPeople(foundedPeople->inf);
        del_node(hashTable[hashExp].head, hashTable[hashExp].tail, foundedPeople);
        std::cout << "Deleted:" << std::endl;
        for (int i = 0; i < hashTable.size(); ++i) {
            std::cout << '[' << i << ']' << ':' << std::endl;
            std::cout << '[' << std::endl;
            print(hashTable[i].head, hashTable[i].tail);
            std::cout << ']' << std::endl;
        }
    } else {
        std::cout << "Not found" << std::endl;
    }


    return 0;
}