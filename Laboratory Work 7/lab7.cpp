#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "function.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        // Создание объектов TextMatrix и заполнение их строками
        const char* text1[] = { "Привет", "Мир", "Это", "Тест" };
        const char* text2[] = { "Это", "Пример", "Тестового", "Класса" };
        size_t size1 = sizeof(text1) / sizeof(text1[0]);
        size_t size2 = sizeof(text2) / sizeof(text2[0]);

        TextMatrix tm1(text1, size1);
        TextMatrix tm2(text2, size2);

        // Вывод исходных объектов
        cout << "Текст 1:\n" << tm1;
        cout << "Текст 2:\n" << tm2;

        // Примеры операций
        TextMatrix tm3 = tm1 + tm2;
        cout << "\nОбъединение:\n" << tm3;

        tm3 = tm1 - tm2;
        cout << "\nРазность:\n" << tm3;

        tm3 = tm1 * 2;
        cout << "\nДублирование:\n" << tm3;

        tm3 = tm1 / 2;
        cout << "\nСокращение:\n" << tm3;

        ++tm1;
        cout << "\nДобавить строку (префиксный инкремент):\n" << tm1;

        tm1++;
        cout << "\nДобавить строку (постфиксный инкремент):\n" << tm1;

        --tm1;
        cout << "\nУдалить строку (префиксный декремент):\n" << tm1;

        tm1--;
        cout << "\nУдалить строку (постфиксный декремент):\n" << tm1;

        tm1.encryptText();
        cout << "\nШифрование текста:\n" << tm1;

        /*tm3 = tm1 & tm2;
        cout << "\nПересечение текстов:\n" << tm3;*/

    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}