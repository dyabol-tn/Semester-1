#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите длину верхней стороны трапеции L и количество N строк трапеции ==> ";
    int l, n;
    cin >> l >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            cout << '*';
        }
        l++;
        cout << endl;
    }

    return 0;
}