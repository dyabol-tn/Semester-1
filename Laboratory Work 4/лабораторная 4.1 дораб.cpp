#include <iostream>

using namespace std;

void inputArray(long long* arr, int size) {
    cout << "Введите " << size << " элементов массива ==> ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

void outputArray(const long long* arr, int size) {
    cout << "Отсортированный массив ==> ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void binarySort(long long* arr, int size) {
    for (int i = 1; i < size; ++i) {
        long long key = arr[i];
        int left = 0;
        int right = i - 1;

        // Бинарный поиск для нахождения позиции вставки
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < key) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        // Сдвигаем элементы
        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int N;
    cout << "Введите размерность массива ==> ";
    cin >> N;

    if (N < 0) {
        cout << "Размерность массива должна быть положительным числом." << endl;
        return 1;
    }
    if (N == 0) {
        cout << "Пустой массив." << endl;
        return 1;
    }

    long long* arr = new long long[N];

    inputArray(arr, N);
    binarySort(arr, N);
    outputArray(arr, N); 

    delete[] arr;
    return 0;
}

