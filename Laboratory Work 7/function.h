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
    // ������������ � ����������
    TextMatrix();
    TextMatrix(const char* text[], size_t size);
    TextMatrix(const TextMatrix& other);
    ~TextMatrix();

    // ���������� ����������
    TextMatrix& operator=(const TextMatrix& other);
    TextMatrix operator+(const TextMatrix& other) const;
    TextMatrix operator-(const TextMatrix& other) const;
    TextMatrix operator*(int n) const;
    TextMatrix operator/(int n) const;
    TextMatrix& operator++(); // ����������
    TextMatrix operator++(int); // �����������
    TextMatrix& operator--(); // ����������
    TextMatrix operator--(int); // �����������
    bool operator==(const TextMatrix& other) const;
    bool operator!=(const TextMatrix& other) const;
    bool operator>=(const TextMatrix& other) const;
    bool operator<=(const TextMatrix& other) const;
    char*& operator[](size_t index);
    const char* operator[](size_t index) const;

    // ������������� �������
    friend TextMatrix operator&(const TextMatrix& lhs, const TextMatrix& rhs);
    friend ostream& operator<<(ostream& os, const TextMatrix& tm);
    friend istream& operator>>(istream& is, TextMatrix& tm);

    // ������
    void addLines(const char* lines[], size_t numLines, bool after = true);
    void removeLines(int n);
    void encryptText();

private:
    void allocate(size_t newSize);
    void deallocate();
};

#endif // TEXTMATRIX_H