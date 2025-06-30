#pragma once
#ifndef TEXTMATRIX_H
#define TEXTMATRIX_H

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class TextMatrix {
private:
    char** matrix;
    size_t size;

public:
    // Конструкторы и деструктор
    TextMatrix();
    TextMatrix(const char* text[], size_t size);
    TextMatrix(const TextMatrix& other);
    ~TextMatrix();

    // Перегрузка операторов
    TextMatrix& operator=(const TextMatrix& other);
    TextMatrix operator+(const TextMatrix& other) const;
    TextMatrix operator-(const TextMatrix& other) const;
    TextMatrix operator*(int n) const;
    TextMatrix operator/(int n) const;
    TextMatrix& operator++(); // Префиксный
    TextMatrix operator++(int); // Постфиксный
    TextMatrix& operator--(); // Префиксный
    TextMatrix operator--(int); // Постфиксный
    bool operator==(const TextMatrix& other) const;
    bool operator!=(const TextMatrix& other) const;
    bool operator>=(const TextMatrix& other) const;
    bool operator<=(const TextMatrix& other) const;
    char*& operator[](size_t index);
    const char* operator[](size_t index) const;

    // Дружественные функции
    friend TextMatrix operator&(const TextMatrix& lhs, const TextMatrix& rhs);
    friend ostream& operator<<(ostream& os, const TextMatrix& tm);
    friend istream& operator>>(istream& is, TextMatrix& tm);

    // Методы
    void addLines(const char* lines[], size_t numLines, bool after = true);
    void removeLines(int n);
    void encryptText();

private:
    void allocate(size_t newSize);
    void deallocate();
};

#endif // TEXTMATRIX_H