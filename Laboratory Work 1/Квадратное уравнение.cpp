#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите коэффициенты ==> ";
	int a, b, c, d;
	cin >> a >> b >> c;
	double x1, x2;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				cout << "Корень - любое число";
			}
			else {
				cout << "Уравнение не имеет смысла";
			}
		}
		else {
			x1 = c * (-1) / b;
			cout << "Корень уравнения = ";
		}
	}
	else {
		d = b * b - 4 * a * c;
		if (d > 0) {
			x1 = (b * (-1) + sqrt(d)) / (2 * a);
			x2 = (b * (-1) - sqrt(d)) / (2 * a);
			cout << "Корни уравнения = " << x1 << " и " << x2;
		}
		else if (d == 0) {
			x1 = (b * (-1)) / (2 * a);
			cout << "Корень уравнения = " << x1;
		}
		else if (d < 0) {
			cout << "Корней нет";
		}
	}
		return 0;
	}