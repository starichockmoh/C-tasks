#pragma once

#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>
#include <iostream>


enum class book_genre {
    UNKNOWN, //ничего
    HISTORY, //историческая
    PHILOSOPHY, //философия
    ADVENTURE, //приключения
    CLASSIC //классика
};



class book { // Объявления класса
private:
    int ID;  //идентификатор
    std::string name;  //название книги
    std::string author; //автор книги
    book_genre genre; //жанр книги

public:
    book(); // Конструктор по умолчанию

    book(int ID, std::string name, std::string author, book_genre genre); // Конструктор с параметрами

    book(const book &p); // Копирующий конструктор

    book(book &&p) noexcept; // Перемещающий конструктор

    book& operator = (const book &rsh); // Копирующее присваивание

    book& operator = (book &&rsh) noexcept ;// Перемещающее присваивание

    [[nodiscard]] int get_ID() const; // Геттер для простого поля ID

    void set_ID(int ID); // Сеттер для простого поля ID

    [[nodiscard]] const std::string& get_name() const; // Геттер для сложного поля name

    void set_name(const std::string& name); // Сеттер для сложного поля name с константной ссылкой

    void set_name(std::string&& name); // Сеттер для сложного поля name с rvalue ссылкой

    [[nodiscard]] const std::string& get_author() const; // Геттер для сложного поля author

    void set_author(const std::string& author); // Сеттер для сложного поля author с константной ссылкой

    void set_author(std::string&& author); // Сеттер для сложного поля author с rvalue ссылкой

    [[nodiscard]] const book_genre& get_genre() const; // Геттер для поля genre

    void set_genre(const book_genre& genre);  // Сеттер для поля genre с константной ссылкой

    void set_genre(book_genre&& genre);  // Сеттер для поля genre с rvalue ссылкой

    [[nodiscard]] int compare(const book &to) const; // Функция сравнения

// Операторы сравнения в виде дружественных функций

    bool operator < (const book &rsh) const;
    bool operator > (const book &rsh) const;
    bool operator <= (const book &rsh) const;
    bool operator >= (const book &rsh) const;
    bool operator == (const book &rsh) const;
    bool operator != (const book &rsh) const;

    ~book(); // Деструктор

    friend std::ostream & operator << (std::ostream & out, const book &p); // Оператор вывода для дружественной функции
};

#endif