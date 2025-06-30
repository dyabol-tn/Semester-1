#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите число ==> ";
	int a, sum = 0;
	cin >> a;
	int i = 1;
	while (a != 0) {
		if (a < 0) {
			a = a * (-1);
		}
		sum = sum + (a % 10);
		a = a / 10;
	}
	cout << "Сумма цифр числа = " << sum;
	return 0;
}
