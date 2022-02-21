#include "Books.h"

using namespace std;


// Реализации конструкторов
book::book()
        : ID(0), genre(book_genre::UNKNOWN) {
}


book::book(int ID, std::string name, std::string author, book_genre genre)
        : name(std::move(name)), author(std::move(author)), genre(std::move(genre)), ID(std::move(ID)) {
}

book::book(const book &p)
        : name(p.name), author(p.author), ID(p.ID), genre(p.genre) {
}


book::book(book &&p) noexcept
        : name(std::move(p.name)), author(std::move(p.author)), genre(std::move(p.genre)), ID(std::move(p.ID)) {
}


book &book::operator = (const book &rsh) = default; // Копирующее присваивание


book &book::operator = (book &&rsh) noexcept { // Перемещающее присваивание
    this->name = move(rsh.name);
    this->author = move(rsh.author);
    this->genre = move(rsh.genre);
    this->ID = move(rsh.ID);
    return *this;
}

// Реализация геттеров и сеттеров
int book::get_ID() const {
    return ID;
}

void book::set_ID(int book_ID) {
    this->ID = book_ID;
}


const string &book::get_name() const {
    return name;

}

void book::set_name(const string &book_name) {
    this->name = book_name;
}

void book::set_name(string &&book_name) {
    this->name = move(book_name);
}

const string &book::get_author() const {
    return author;
}

void book::set_author(const string &book_author) {
    this->author = book_author;

}

void book::set_author(string &&book_author) {
    this->author = move(book_author);
}


const book_genre &book::get_genre() const {
    return genre;
}


void book::set_genre(const book_genre &book_genre) {
    this->genre = book_genre;
}

void book::set_genre(book_genre &&book_genre) {
    this->genre = move(book_genre);
}


static string json_string(const string &s) { // Экранирование строки
    string json_s;
    json_s.append("\"");
    for (char c: s) {
        switch (c) {
            case '\n':
            case '\v':
                json_s.append("\\n");
                break;
            case '\0':
                json_s.append("\\0");
                break;
            case '\t':
                json_s.append("\\t");
                break;
            case '\r':
                json_s.append("\\r");
                break;
            case '"':
                json_s.append("\\\"");
                break;
            default:
                json_s.push_back(c);
        }
    }
    json_s.append("\"");
    return json_s;
}


string ToStringType(book_genre genre) { //функция для создания строки на основе жанра
    string book_genre;
    switch (genre) {
        case book_genre::ADVENTURE: {
            book_genre = "adventure";
            break;
        }
        case book_genre::CLASSIC: {
            book_genre = "classic";
            break;
        }
        case book_genre::HISTORY: {
            book_genre = "history";
            break;
        }
        case book_genre::PHILOSOPHY: {
            book_genre = "philosophy";
            break;
        }
        case book_genre::UNKNOWN: {
            book_genre = "unknown";
            break;
        }
        default: {
            book_genre = "error";
            break;
        }
    }
    return book_genre;
}

// Дружественная функция имеет доступ непосредственно к полям
std::ostream &operator << (ostream &out, const book &p) {
    string string_genre = ToStringType(p.genre);
    return out << "{ \"ID\": "
               << p.ID
               << ", \"name\": "
               << json_string(p.name)
               << ", \"author\" : "
               << json_string(p.author)
               << ", \"genre\": "
               << json_string(string_genre) << " }";
}


// Функция сравнения (по названию)
int book::compare(const book &to) const {
    int cmp;
    cmp = name.compare(to.name);
    return cmp;
}

// Операторы сравнения
bool book::operator < (const book &rsh) const {
    return compare(rsh) < 0;
}

bool book::operator > (const book &rsh) const {
    return compare(rsh) > 0;
}

bool book::operator <= (const book &rsh) const {
    return compare(rsh) <= 0;
}

bool book::operator >= (const book &rsh) const {
    return compare(rsh) >= 0;
}

bool book::operator == (const book &rsh) const {
    return compare(rsh) == 0;
}

bool book::operator != (const book &rsh) const {
    return compare(rsh) != 0;
}


book::~book() = default; // Деструктор

int main() {
    book book1(1, "History of Russia", "A.A. Orlov", book_genre::HISTORY); //конструктор с параметрами
    cout << book1 << endl;
    cout << endl;

    //сеттер с rvalue ссылкой
    book book2;
    book2.set_name("Dialogs");
    book2.set_author("Platon");
    book2.set_ID(2);
    book2.set_genre(book_genre::PHILOSOPHY);
    cout << book2 << endl;
    cout << endl;

    //сеттер с константной ссылкой
    book book2_1;
    const string name = "Master and Margarita";
    const string author = "M. A. Bulgakov";
    const book_genre genre = book_genre::CLASSIC;
    const int ID = 3;
    book2_1.set_name(name);
    book2_1.set_author(author);
    book2_1.set_ID(ID);
    book2_1.set_genre(genre);
    cout << book2_1 << endl;
    cout << endl;

    //сравнение
    cout << "compare:" << " " << book1.compare(book2) << endl;
    cout << book1.get_name() <<" < " << book2.get_name() << ": " << boolalpha << (book1 < book2) << endl;
    cout << book1.get_name() <<" > " << book2.get_name() << ": " << boolalpha << (book1 > book2) << endl;
    cout << book1.get_name() <<" == " << book2.get_name() << ": " << boolalpha << (book1 == book2) << endl;
    cout << book1.get_name() <<" != " << book2.get_name() << ": " << boolalpha << (book1 != book2) << endl;
    cout << book1.get_name() <<" <= " << book2.get_name() << ": " << boolalpha << (book1 <= book2) << endl;
    cout << book1.get_name() <<" >= " << book2.get_name() << ": " << boolalpha << (book1 >= book2) << endl;
    cout << endl;

    cout << "compare:" << " " << book1.compare(book2_1) << endl;
    cout << book1.get_name() <<" < " << book2_1.get_name() << ": " << boolalpha << (book1 < book2_1) << endl;
    cout << book1.get_name() <<" > " << book2_1.get_name() << ": " << boolalpha << (book1 > book2_1) << endl;
    cout << book1.get_name() <<" == " << book2_1.get_name() << ": " << boolalpha << (book1 == book2_1) << endl;
    cout << book1.get_name() <<" != " << book2_1.get_name() << ": " << boolalpha << (book1 != book2_1) << endl;
    cout << book1.get_name() <<" <= " << book2_1.get_name() << ": " << boolalpha << (book1 <= book2_1) << endl;
    cout << book1.get_name() <<" >= " << book2_1.get_name() << ": " << boolalpha << (book1 >= book2_1) << endl;
    cout << endl;

    //геттер
    cout << book2.get_ID() << "\n";
    cout << book2.get_name() << "\n";
    cout << book2.get_author() << "\n";
    cout << ToStringType(book2.get_genre()) << "\n";
    cout << endl;

    book book3(book2);//копирующий конструктор
    cout << book3 << endl;
    book book6(std::move(book2)); // перемещающий конструктор
    cout << book6 << endl;

    const book& book4 = book3;  // копирующее присваивание
    cout << book4 << endl;
    const book& book5 = std::move(book3); // перемещающее присваивание
    cout << book5 << endl;
}