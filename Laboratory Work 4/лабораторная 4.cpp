/*4.13.Разработать программу, запрашивающую у пользователя размерность массива N, выполняющую Сортировки
его элементов по убыванию.Сортировки осуществлять с помощью сортировок «пузырька» и «бинарной».Ввод,
вывод, Сортировки выделить в отдельные функции.Тип массива longlong.*/

#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "RU");
	srand(time(0));
	long long* a;
	int n;
	cout << "Введите размерность массива N =>> ";
	cin >> n;
	if (n < 0)
		cout << "N должно быть больше 0.";
	else if (n == 0)
		cout << "Пустой массив.";
	else {
		a = new long long[n];
		for (int i = 0; i < n; i++)
			a[i] = (long long)(rand() % 100);
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j] < a[j + 1]) {
					swap(a[j], a[j + 1]);
				}
			}
		}
		for (int i = 0; i < n; i++) cout << a[i] << " ";
	}
	return 0;
}