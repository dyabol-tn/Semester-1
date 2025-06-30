#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите натуральное число ==> ";
	int a, b = 1;
	cin >> a;
	if (a < 0) {
		cout << "Нельзя посчитать факториал";
	}
	else {
		for (int i = 1; i <= a; i++) {
			b *= i;
		}
		cout << "Факториал числа " << a << " = " << b;
	}
	return 0;
}
