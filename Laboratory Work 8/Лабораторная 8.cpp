#include <iostream>
#include <fstream>

using namespace std;

int sumEvenIndexes(int arr[], int size, int index = 0) {
    if (index >= size) {
        return 0;
    }
    if (index % 2 == 0) {
        return arr[index] + sumEvenIndexes(arr, size, index + 1);
    }
    else {
        return sumEvenIndexes(arr, size, index + 1);
    }
}

int productOddIndexes(int arr[], int size, int index = 1) {
    if (index >= size) return 1;
    return arr[index] * productOddIndexes(arr, size, index + 2);
}

int main() {
    setlocale(LC_ALL, "RU");

    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Не удалось открыть файл input.txt." << endl;
        return 1;
    }

    int size;
    inputFile >> size;
    if (size <= 0) {
        cout << "Некорректный размер массива." << endl;
        return 1;
    }

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        inputFile >> arr[i];
    }
    inputFile.close();

    int sumEven = sumEvenIndexes(arr, size);
    int productOdd = productOddIndexes(arr, size);

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cout << "Не удалось открыть файл для записи." << endl;
        delete[] arr;
        return 1;
    }

    outputFile << "Сумма элементов на четных местах: " << sumEven << endl;
    outputFile << "Произведение элементов на нечетных местах: " << productOdd << endl;
    outputFile.close();

    cout << "Сумма элементов на четных местах: " << sumEven << endl;
    cout << "Произведение элементов на нечетных местах: " << productOdd << endl;

    delete[] arr;

    cout << "Результаты записаны в файл output.txt" << endl;
    return 0;
}

