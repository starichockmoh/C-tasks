#pragma once

#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>
#include <iostream>


enum class student_type {

    UNKNOWN, //ничего

    BAKALAVR, //бакалавр

    MAGISTR, //магистр

    SPECIALIST, //специалист

    ASPIRANT //аспирант
};



class student { // Объявления класса

private:
    int value;  //идентификатор
    std::string name;  //имя
    std::string surname; //фамилия
    std::string patronymic; //отчество
    int group; //номер группы
    student_type type; //тип

public:
    student(); // Конструктор по умолчанию

    student(int value, std::string  name,  std::string student_surname, std::string student_patronymic, int group, student_type type); // Конструктор с параметрами

    student(const student &p); // Копирующий конструктор

    student(student &&p) noexcept ; // Перемещающий конструктор

    student& operator = (const student& rsh); // Копирующее присваивание

    student& operator = (student&& rsh) noexcept ;// Перемещающее присваивание

    [[nodiscard]] int Get_value() const; // Геттер для простого поля value

    void Set_value(int value); // Сеттер для простого поля value

    [[nodiscard]] int Get_group() const; // Геттер для простого поля group

    void Set_group(int student_group); // Сеттер для простого поля group

    [[nodiscard]] const std::string& Get_name() const; // Геттер для сложного поля name

    void Set_name(const std::string& name); // Сеттер для сложного поля name с константной ссылкой

    void Set_name(std::string&& name); // Сеттер для сложного поля name с rvalue ссылкой

    [[nodiscard]] const std::string& Get_surname() const; // Геттер для сложного поля surname

    void Set_surname(const std::string& familia); // Сеттер для сложного поля familia с константной ссылкой

    void Set_surname(std::string&& familia); // Сеттер для сложного поля surname с rvalue ссылкой

    [[nodiscard]] const std::string& Get_patronymic() const; // Геттер для сложного поля patronymic

    void Set_patronymic(const std::string& patronymic); // Сеттер для сложного поля patronymic с константной ссылкой

    void Set_patronymic(std::string&& patronymic); // Сеттер для сложного поля patronymic с rvalue ссылкой

    [[nodiscard]] const student_type& Get_type() const; // Геттер для поля type

    void Set_type(const student_type& studentType);  // Сеттер для поля studentType с константной ссылкой

    void Set_type(student_type&& type);  // Сеттер для поля type с rvalue ссылкой

    [[nodiscard]] int compare(const student& to) const; // Функция сравнения

// Операторы сравнения в виде дружественных функций

    bool operator < (const student &rsh) const;
    bool operator > (const student &rsh) const;
    bool operator <= (const student &rsh) const;
    bool operator >= (const student &rsh) const;
    bool operator == (const student &rsh) const;
    bool operator != (const student &rsh) const;

    ~student(); // Деструктор

    friend std::ostream & operator << (std::ostream & out, const student &p); // Оператор вывода для дружественной функции
};

#endif