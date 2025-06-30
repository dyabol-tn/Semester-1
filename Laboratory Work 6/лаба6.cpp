#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>

#define MAX_LEN 256
#define MAX_TOKENS 50

using namespace std;

void readLineFromFile(const string& fileName, string& line) {
    ifstream file(fileName);
    if (file.is_open()) {
        getline(file, line);
        file.close();
    }
    else {
        cerr << "Не удалось открыть файл: " << fileName << ". Попытка создания файла." << endl;
        ofstream newFile(fileName);
        if (newFile.is_open()) {
            cout << "Файл успешно создан: " << fileName << endl;
            newFile.close();
        }
        else {
            cerr << "Ошибка при создании файла" << endl;
            exit(EXIT_FAILURE);
        }
        line = "";
    }
}

void writeLineToFile(const string& fileName, const string& line) {
    ofstream file(fileName);
    if (file.is_open()) {
        file << line << endl;
        file.close();
    }
    else {
        cerr << "Не удалось открыть файл для записи" << endl;
        exit(EXIT_FAILURE);
    }
}

int splitString(const char* str, const char* delimiters, char tokens[MAX_TOKENS][MAX_LEN]) {
    int count = 0;
    char strCopy[MAX_LEN];
    strcpy(strCopy, str);
    char* token = strtok(strCopy, delimiters);
    while (token != nullptr && count < MAX_TOKENS) {
        strcpy(tokens[count++], token);
        token = strtok(nullptr, delimiters);
    }
    return count;
}

void replaceHexNumbersWithZero(char* str, char tokens[MAX_TOKENS][MAX_LEN], int count) {
    char resultStr[MAX_LEN * 2] = { 0 };
    int k = 0;

    for (int i = 0; i < count; i++) {
        bool isHex = true;
        for (int j = 0; tokens[i][j] != '\0'; j++) {
            if (tokens[i][j] < '0' || tokens[i][j] > '5') {
                isHex = false;
                break;
            }
        }
        if (isHex) {
            strcpy(tokens[i], "0");
        }
    }

    for (int i = 0; i < count; i++) {
        if (i > 0) {
            resultStr[k++] = ' ';
        }
        for (int j = 0; tokens[i][j] != '\0'; j++) {
            resultStr[k++] = tokens[i][j];
        }
    }
    resultStr[k] = '\0';
    strcpy(str, resultStr);
}

void insertionSort(char tokens[MAX_TOKENS][MAX_LEN], int count) {
    for (int i = 1; i < count; i++) {
        char key[MAX_LEN];
        strcpy(key, tokens[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(tokens[j], key) > 0) {
            strcpy(tokens[j + 1], tokens[j]);
            j--;
        }
        strcpy(tokens[j + 1], key);
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    char line1[MAX_LEN], line2[MAX_LEN];
    cout << "Введите первую строку: ";
    cin.getline(line1, MAX_LEN);
    cout << "Введите строку с разделителями: ";
    cin.getline(line2, MAX_LEN);

    cout << "Введена первая строка: " << line1 << endl;
    cout << "Введена строка с разделителями: " << line2 << endl;

    char tokens[MAX_TOKENS][MAX_LEN];
    int tokenCount = splitString(line1, line2, tokens);

    cout << "Лексемы: ";
    for (int i = 0; i < tokenCount; i++) {
        cout << tokens[i] << " ";
    }
    cout << endl;

    replaceHexNumbersWithZero(line1, tokens, tokenCount);

    cout << "Строка после замены чисел на 0: " << line1 << endl;

    insertionSort(tokens, tokenCount);

    cout << "Отсортированные лексемы: ";
    for (int i = 0; i < tokenCount; i++) {
        cout << tokens[i] << " ";
    }
    cout << endl;

    string resultString;
    for (int i = 0; i < tokenCount; i++) {
        resultString += tokens[i];
        if (i < tokenCount - 1) {
            resultString += " ";
        }
    }

    writeLineToFile("output.txt", string(line1));

    string strCpp = resultString;
    size_t pos = strCpp.find_last_of(" ");
    if (pos != string::npos) {
        strCpp.insert(pos, " ADDED_STRING");
    }

    srand(static_cast<unsigned int>(time(NULL)));
    bool digitFound = false;
    while (!digitFound && !strCpp.empty()) {
        int randPos = rand() % strCpp.length();
        if (isdigit(strCpp[randPos])) {
            strCpp.erase(randPos, 1);
            digitFound = true;
        }
    }

    writeLineToFile("output_cpp.txt", strCpp);

    cout << "Результаты записаны в файлы output.txt и output_cpp.txt" << endl;

    return 0;
}

