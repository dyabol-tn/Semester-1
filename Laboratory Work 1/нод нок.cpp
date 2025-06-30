#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите 2 числа ==>";
	int a, b, c;
	cin >> a >> b;
	c = a * b;
	if (a < 0 || b < 0) {
		cout << "Вычислить НОД и НОК невозможно";
		while (a != 0 && b != 0) {
			if (a > b) {
				a = a - b;
			}
			else {
				b = b - a;
			}
		}
		cout << "НОД= " << a + b << endl << "НОК=" << c / (a + b);

		return 0;
	}