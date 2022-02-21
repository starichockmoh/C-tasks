#include "Classes.h"

#include<iomanip>

using namespace std;


// Реализации конструкторов
student::student()
        : group(0), value(0), type(student_type::UNKNOWN) {
}

student::student(int value, std::string student_name, std::string student_surname, std::string student_patronymic,
                 int group, student_type student_type)
        : name(std::move(student_name)), group(std::move(group)), value(std::move(value)),
          type(student_type), surname(move(student_surname)), patronymic(move(student_patronymic)) {

}

student::student(const student &p)
        : name(p.name), type(p.type), group(p.group), value(p.value), patronymic(p.patronymic), surname(p.surname) {

}

student::student(student &&p) noexcept
        : name(move(p.name)), type(p.type), group(p.group), value(p.value), patronymic(move(p.patronymic)),
          surname(move(p.surname)) {

}

// Копирующее присваивание

student &student::operator=(const student &rsh) {

    this->name = rsh.name;

    this->type = rsh.type;

    this->group = rsh.group;

    return *this;

}

// Перемещающее присваивание

student &student::operator=(student &&rsh) noexcept {

    this->name = move(rsh.name);

    this->type = move(rsh.type);

    this->group = move(rsh.group);

    return *this;

}

int student::Get_value() const {
    return value;
}

void student::Set_value(int student_value) {
    this->value = student_value;
}

int student::Get_group() const {
    return group;
}

void student::Set_group(int student_group) {
    this->group = student_group;
}

const string &student::Get_name() const {// Реализация геттеров и сеттеры
    return name;

}

void student::Set_name(const string &student_name) {
    this->name = student_name;

}

void student::Set_name(string &&student_name) {
    this->name = move(student_name);
}

const string &student::Get_surname() const {// Реализация геттеров и сеттеры
    return surname;
}

void student::Set_surname(const string &student_surname) {
    this->surname = student_surname;

}

void student::Set_surname(string &&student_surname) {
    this->surname = move(student_surname);
}

const string &student::Get_patronymic() const {// Реализация геттеров и сеттеры
    return patronymic;
}

void student::Set_patronymic(const string &student_patronymic) {
    this->patronymic = student_patronymic;

}

void student::Set_patronymic(string &&student_patronymic) {
    this->patronymic = move(student_patronymic);
}


const student_type &student::Get_type() const {
    return type;
}


void student::Set_type(const student_type &student_type) {
    this->type = student_type;
}

void student::Set_type(student_type &&student_type) {
    this->type = move(student_type);
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
        };
    }
    json_s.append("\"");
    return json_s;

}

string ToStringType(student_type Type) {
    string student_type;
    switch (Type) {
        case student_type::ASPIRANT: {
            student_type = "aspirant";
            break;
        }
        case student_type::BAKALAVR: {
            student_type = "bakalavr";
            break;
        }
        case student_type::MAGISTR: {
            student_type = "magistr";
            break;
        }
        case student_type::SPECIALIST: {
            student_type = "specialist";
            break;
        }
        case student_type::UNKNOWN: {
            student_type = "unknown";
            break;
        }
        default: {
            student_type = "error";
            break;
        }
    }
    return student_type;
}

// Дружественная функция имеет доступ непосредственно к полям

std::ostream &operator<<(ostream &out, const student &p) {
    string StringType = ToStringType(p.type);
    return out << "{ \"student_name\": "
               << json_string(p.name)
               << ", \"student_surname\": "
               << json_string(p.surname)
               << ", \"student_patronymic\" : "
               << json_string(p.patronymic)
               << " , \"group\": "
               << p.group << ", \"student_type\": "
               << json_string(StringType) << " }";
}

// Функция сравнения

int student::compare(const student &to) const {
    int cmp;
    cmp = name.compare(to.name);

    return cmp;

}

// Операторы сравнения

bool student::operator<(const student &rsh) const {
    return compare(rsh) < 0;
}

bool student::operator>(const student &rsh) const {
    return compare(rsh) > 0;
}

bool student::operator<=(const student &rsh) const {
    return compare(rsh) <= 0;
}

bool student::operator>=(const student &rsh) const {
    return compare(rsh) >= 0;
}

bool student::operator==(const student &rsh) const {
    return compare(rsh) == 0;
}

bool student::operator!=(const student &rsh) const {
    return compare(rsh) != 0;

}

// Деструктор

student::~student() = default;

int main() {
    //конструктор
    student student0(1, "Alena", "Pavlova", "Alexsandrovna", 112, student_type::BAKALAVR);
    cout << student0 << "\n";
    student student1;

    //сеттер
    student1.Set_name("Boris");
    student1.Set_surname("Pokleev");
    student1.Set_patronymic("Alexsandrov");
    student1.Set_group(113);
    student1.Set_type(student_type::SPECIALIST);
    cout << student1 << endl;
    cout << endl;

    //сравнение
    cout << "compare:" << " " << student1.compare(student0) << endl;
    cout << "first < second: " << " "<< boolalpha << (student0 < student1) << endl;
    cout << "first > second: " << " "<< boolalpha << (student0 > student1) << endl;
    cout << "first == second: " << " "<< boolalpha << (student0 == student1) << endl;
    cout << "first != second: " << " "<< boolalpha << (student0 != student1) << endl;
    cout << "first <= second: " << " "<< boolalpha << (student0 <= student1) << endl;
    cout << "first >= second: " << " "<< boolalpha << (student0 >= student1) << endl;
    cout << endl;

    //геттер
    cout << student1.Get_name() << "\n";

    cout << student1.Get_surname() << "\n";

    cout << student1.Get_patronymic() << "\n";

    cout << student1.Get_group() << "\n";

    cout << ToStringType(student1.Get_type()) << "\n";
    cout << endl;

//копирующий конструктор
    student student2(student1);
    cout << student2 << endl;
}