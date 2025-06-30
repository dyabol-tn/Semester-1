#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double a, b;
	cout << "Введите число A ==> ";
	cin >> a;
	cout << "Введите число B ==> ";
	cin >> b;
	if (b != 0)
	{
		int x;
		double y;
		x = a / b;
		cout << "Частное при делении А на В ==> " << x << '\n';
		int q, j;
		q = a;
		j = b;
		y = a - (b * x);
		cout << "Остаток при делении А на В ==> " << abs(y) << '\n';
		cout << "Математическое округление числа А ==> " << round(a) << '\n';
		cout << "Математическое округление числа В ==> " << round(b) << '\n';
		cout << "Преобразование операнда А в int ==> " << q << '\n';
		cout << "Преобразование операнда В в int ==> " << j << '\n';
	}
	else
		cout << "На ноль делить нельзя!";
	return 0;
}
