#include <iostream>
using namespace std;

void countingSort(int arr[], int size) {
    // Знаходимо максимальний елемент
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Створюємо динамічний масив для підрахунку елементів
    int* count = new int[maxElement + 1]();  // Ініціалізуємо масив з нулями

    // Підраховуємо кількість кожного елемента
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Записуємо відсортовані елементи назад в початковий масив
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    // Звільняємо пам'ять
    delete[] count;
}

int main() {
    int arr[] = { 4, 2, 2, 8, 3, 3, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);  // Розмір масиву

    cout << "Початковий масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr, size);  // Викликаємо функцію сортування

    cout << "Відсортований масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
