#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите натуральное число ==> ";
	int a; bool t = true;
	cin >> a;
	if (a == 1 || a == 0) {
		cout << "Ни простое, ни составное";
	}
	else if (a < 0) {
		cout << "Составное";
	}
	else {
		for (int i = 2; i <= sqrt(a); i++) {
			if (a % i == 0) {
				cout << "Составное";
				t = false;
				break;
			}
		}
		if (t == true) {
			cout << "Простое";
		}
	}
		return 0;
	}

