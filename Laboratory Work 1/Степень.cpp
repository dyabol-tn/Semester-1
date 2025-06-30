#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите число Х и степень N числа Х ==> ";
	int x;
	double n;
	cin >> x >> n;
	if (x == 0 && n < 0) {
		cout << "0 нельзя возвести в отрицательную степень!";
	}
	else if (x < 0 && (round(n) - n) < 1) {
		cout << "Отрицательное число нельзя возвести в нецелую степень!";
	}
	else {
		cout << pow(x, n);
	}
return 0;
}
