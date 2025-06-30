#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <ctime> 
using namespace std;

void printList(const list<int>& lst) {
    copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void addRandomElements(list<int>& lst, int numElements) {
    srand(time(0));
    for (int i = 0; i < numElements; ++i) {
        int randNum = rand() % 100;
        lst.push_back(randNum);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    list<int> myList;
    int choice, num, X;

    do {
        cout << "Меню:\n";
        cout << "1. Просмотреть состояние списка\n";
        cout << "2. Добавить элемент\n";
        cout << "4. Добавить несколько элементов\n";
        cout << "5. Удалить элемент\n";
        cout << "6. Разделить элементы на две группы (использовать Sort)\n";
        cout << "7. Увеличить все элементы на Х (использовать transform)\n";
        cout << "8. Выход из программы\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printList(myList);
            break;
        case 2:
            cout << "Введите элемент для добавления: ";
            cin >> num;
            myList.push_back(num);
            break;
        case 4:
            int numElements;
            cout << "Введите количество элементов для добавления: ";
            cin >> numElements;
            addRandomElements(myList, numElements);
            break;
        case 5:
            cout << "Введите элемент для удаления: ";
            cin >> num;
            myList.remove(num);
            break;
        case 6:
            myList.sort();
            break;
        case 7:
            cout << "Введите значение Х: ";
            cin >> X;
            transform(myList.begin(), myList.end(), myList.begin(), [X](int& n) { return n + X; });
            break;
        case 8:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 8);

    return 0;
}
