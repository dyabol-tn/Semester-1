#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

int krat3(int a) {
    bool t = false;
    int s = 0;
    while (a > 0) {
        s += a % 10;
        a /= 10;
    }
    if (s % 3 == 0 && s != 0) t = true;
    else t = false;
    return t;
}
int krat9(int a) {
    bool t = false;
    int s = 0;
    while (a > 0) {
        s += a % 10;
        a /= 10;
    }
    if (s % 9 == 0 && s != 0) t = true;
    else t = false;
    return t;
}
int nekrat(int a) {
    bool t = false;
    int s = 0;
    while (a > 0) {
        s += a % 10;
        a /= 10;
    }
    if (s % 3 != 0) t = true;
    else t = false;
    return t;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    int A[10], a = 10;

    //for (int i = 0; i < a; i++) cin >> A[i];

    for (int i = 0; i < a; i++)  A[i] = rand() % 100;
    for (int i = 0; i < a; i++) cout << A[i] << " ";
    cout << '\n';

    for (int i = 0; i < a; i++)
        if (krat3(A[i]) == true) cout << A[i] << " ";

    cout << "0 ";

    for (int i = 0; i < a; i++)
        if (krat9(A[i]) == true) cout << A[i] << " ";

    cout << "0 ";

    for (int i = 0; i < a; i++)
        if (nekrat(A[i]) == true) cout << 0 << " ";

    return 0;
}