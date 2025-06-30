#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double x, e, s = 0, slag = 0;
	int tr, k = 1;
	cout << "Введите число X ==> ";
	cin >> x;
	if (x >= 1)
		cout << "Неверное условие";
	else if (x <= -1)
		cout << "Неверное условие";
	else {
		cout << "Введите точность ==> ";
		cin >> tr;
		slag = x;
		s = x;
		e = pow(10, (double(-tr)));
		while (abs(slag) > e) {
			slag = slag * ((x * k) / (k + 1) * (-1));
			k++;
			s = s + slag;
		}
		cout << "Сумма ==> " << s << endl;
	}
	cout << log(1 + x) << endl;
	return 0;
}