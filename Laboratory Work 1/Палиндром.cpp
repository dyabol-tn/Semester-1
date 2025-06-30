#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите число ==> ";
	int a, b = 0, c;
	cin >> a, c = a;
	for (int i = 1; a > 0; i++) {
		b = b * 10 + (a % 10);
		a /= 10;
	}
	if (b == c) {
		cout << "Палиндром";
	}
	else {
		cout << "Не палиндром";
	}
	return 0;
}


