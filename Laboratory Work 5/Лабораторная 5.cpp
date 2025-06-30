/*Разработать программу, запрашивающую у пользователя матрицу размером NxN.
Выполнить отражение матрицы относительно диагонали [1,N]-[N,1] (т.е. элемент [i,j] становится [N-1-j,N-1-i] и наоборот). Обнулить диагональные элементы. Размерность матрицы  считать с консоли,  элементы матрицы - случайным образом. Результаты вывести на консоль. Элементы матрицы вещественные числа..
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = static_cast<double>(rand()) / RAND_MAX * 100.0;
        }
    }
}

void printMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << fixed << setprecision(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Отражение и обнуление
void reflectAndZeroDiagonal(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
        matrix[i][i] = 0.0;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned int>(time(0))); // Генератор случайных чисел

    int N;
    cout << "Введите размерность матрицы N ==> ";
    cin >> N;

    if (N < 0) {
        cout << "Размерность матрицы должна быть положительным числом." << endl;
        return 1;
    }
    if (N == 0) {
        cout << "Пустая матрица." << endl;
        return 1;
    }

    double** matrix = new double* [N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new double[N];
    }

    fillMatrix(matrix, N);
    std::cout << "Исходная матрица:" << endl;
    printMatrix(matrix, N); // Вывод исходной матрицы

    reflectAndZeroDiagonal(matrix, N);

    std::cout << "Матрица после отражения и обнуления диагонали:" << endl;
    printMatrix(matrix, N); // Вывод измененной матрицы

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
