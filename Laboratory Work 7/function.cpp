#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

TextMatrix::TextMatrix() : matrix(nullptr), size(0) {}

TextMatrix::TextMatrix(const char* text[], size_t size) : size(size) {
    allocate(size);
    for (size_t i = 0; i < size; ++i) {
        matrix[i] = new char[strlen(text[i]) + 1];
        strcpy(matrix[i], text[i]);
    }
}

TextMatrix::TextMatrix(const TextMatrix& other) : size(other.size) {
    allocate(other.size);
    for (size_t i = 0; i < size; ++i) {
        matrix[i] = new char[strlen(other.matrix[i]) + 1];
        strcpy(matrix[i], other.matrix[i]);
    }
}

TextMatrix::~TextMatrix() {
    deallocate();
}

void TextMatrix::allocate(size_t newSize) {
    matrix = new char* [newSize];
}

void TextMatrix::deallocate() {
    if (matrix) {
        for (size_t i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

TextMatrix& TextMatrix::operator=(const TextMatrix& other) {
    if (this != &other) {
        deallocate();
        size = other.size;
        allocate(size);
        for (size_t i = 0; i < size; ++i) {
            matrix[i] = new char[strlen(other.matrix[i]) + 1];
            strcpy(matrix[i], other.matrix[i]);
        }
    }
    return *this;
}

TextMatrix TextMatrix::operator+(const TextMatrix& other) const {
    TextMatrix result;
    result.size = size + other.size;
    result.allocate(result.size);
    for (size_t i = 0; i < size; ++i) {
        result.matrix[i] = new char[strlen(matrix[i]) + 1];
        strcpy(result.matrix[i], matrix[i]);
    }
    for (size_t i = 0; i < other.size; ++i) {
        result.matrix[size + i] = new char[strlen(other.matrix[i]) + 1];
        strcpy(result.matrix[size + i], other.matrix[i]);
    }
    return result;
}

TextMatrix TextMatrix::operator-(const TextMatrix& other) const {
    TextMatrix result;
    result.allocate(size);
    size_t resultSize = 0;
    for (size_t i = 0; i < size; ++i) {
        bool found = false;
        for (size_t j = 0; j < other.size; ++j) {
            if (strcmp(matrix[i], other.matrix[j]) == 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.matrix[resultSize] = new char[strlen(matrix[i]) + 1];
            strcpy(result.matrix[resultSize], matrix[i]);
            ++resultSize;
        }
    }
    result.size = resultSize;
    return result;
}

TextMatrix TextMatrix::operator*(int n) const {
    TextMatrix result;
    result.size = size * n;
    result.allocate(result.size);
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result.matrix[i * size + j] = new char[strlen(matrix[j]) + 1];
            strcpy(result.matrix[i * size + j], matrix[j]);
        }
    }
    return result;
}

TextMatrix TextMatrix::operator/(int n) const {
    if (n <= 0) throw out_of_range("Деление на ноль или отрицательное число");
    TextMatrix result;
    result.size = size / n;
    result.allocate(result.size);
    for (size_t i = 0; i < result.size; ++i) {
        result.matrix[i] = new char[strlen(matrix[i]) + 1];
        strcpy(result.matrix[i], matrix[i]);
    }
    return result;
}

TextMatrix& TextMatrix::operator++() {
    TextMatrix temp = *this;
    deallocate();
    allocate(size + 1);
    for (size_t i = 0; i < size; ++i) {
        matrix[i] = new char[strlen(temp.matrix[i]) + 1];
        strcpy(matrix[i], temp.matrix[i]);
    }
    matrix[size] = new char[1] {0};
    ++size;
    return *this;
}

TextMatrix TextMatrix::operator++(int) {
    TextMatrix temp = *this;
    ++(*this);
    return temp;
}

TextMatrix& TextMatrix::operator--() {
    if (size > 0) {
        --size;
        delete[] matrix[size];
    }
    return *this;
}

TextMatrix TextMatrix::operator--(int) {
    TextMatrix temp = *this;
    --(*this);
    return temp;
}

bool TextMatrix::operator==(const TextMatrix& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (strcmp(matrix[i], other.matrix[i]) != 0) return false;
    }
    return true;
}

bool TextMatrix::operator!=(const TextMatrix& other) const {
    return !(*this == other);
}

bool TextMatrix::operator>=(const TextMatrix& other) const {
    return size >= other.size;
}

bool TextMatrix::operator<=(const TextMatrix& other) const {
    return size <= other.size;
}

char*& TextMatrix::operator[](size_t index) {
    if (index >= size) throw out_of_range("Индекс вне диапазона");
    return matrix[index];
}

const char* TextMatrix::operator[](size_t index) const {
    if (index >= size) throw out_of_range("Индекс вне диапазона");
    return matrix[index];
}

// Дружественные функции
TextMatrix operator&(const TextMatrix& lhs, const TextMatrix& rhs) {
    TextMatrix result;
    result.allocate(lhs.size); // Максимально возможное количество строк
    size_t resultSize = 0;
    for (size_t i = 0; i < lhs.size; ++i) {
        for (size_t j = 0; j < rhs.size; ++j) {
            if (strcmp(lhs.matrix[i], rhs.matrix[j]) == 0) {
                result.matrix[resultSize] = new char[strlen(lhs.matrix[i]) + 1];
                strcpy(result.matrix[resultSize], lhs.matrix[i]);
                ++resultSize;
                break;
            }
        }
    }
    result.size = resultSize;
    return result;
}

ostream& operator<<(ostream& os, const TextMatrix& tm) {
    for (size_t i = 0; i < tm.size; ++i) {
        os << tm.matrix[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is, TextMatrix& tm) {
    string line;
    vector<string> lines;
    while (getline(is, line)) {
        lines.push_back(line);
    }
    tm.deallocate();
    tm.size = lines.size();
    tm.allocate(tm.size);
    for (size_t i = 0; i < tm.size; ++i) {
        tm.matrix[i] = new char[lines[i].size() + 1];
        strcpy(tm.matrix[i], lines[i].c_str());
    }
    return is;
}

void TextMatrix::addLines(const char* lines[], size_t numLines, bool after) {
    TextMatrix temp = *this;
    deallocate();
    allocate(size + numLines);
    if (after) {
        for (size_t i = 0; i < size; ++i) {
            matrix[i] = new char[strlen(temp.matrix[i]) + 1];
            strcpy(matrix[i], temp.matrix[i]);
        }
        for (size_t i = 0; i < numLines; ++i) {
            matrix[size + i] = new char[strlen(lines[i]) + 1];
            strcpy(matrix[size + i], lines[i]);
        }
    }
    else {
        for (size_t i = 0; i < numLines; ++i) {
            matrix[i] = new char[strlen(lines[i]) + 1];
            strcpy(matrix[i], lines[i]);
        }
        for (size_t i = 0; i < size; ++i) {
            matrix[numLines + i] = new char[strlen(temp.matrix[i]) + 1];
            strcpy(matrix[numLines + i], temp.matrix[i]);
        }
    }
    size += numLines;
}

void TextMatrix::removeLines(int n) {
    if (n >= 0 && static_cast<size_t>(n) <= size) {
        TextMatrix temp;
        temp.size = size - n;
        temp.allocate(temp.size);
        for (size_t i = n; i < size; ++i) {
            temp.matrix[i - n] = new char[strlen(matrix[i]) + 1];
            strcpy(temp.matrix[i - n], matrix[i]);
        }
        *this = temp;
    }
    else {
        throw out_of_range("Неправильное количество строк для удаления");
    }
}

void TextMatrix::encryptText() {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < strlen(matrix[i]); ++j) {
            matrix[i][j] = matrix[i][j] + 1; // Простое шифрование смещением символов
        }
    }
}