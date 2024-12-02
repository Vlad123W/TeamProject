// Члени команди:
// - Дужак І.В.
// - Лобанов Д.С.
// - Максимов Д.В.
// - Конопленко В.О.
// - Мозговий А.А.
// Назва дисципліни: Алгоритми та структури даих
// Назва завдання: код\реалізація основної програми з коментарями 
// Кінцевий термін: 03.12
// Час виконання: 9 годин
// Ця робота зроблена членами команди №2
#include <iostream>
#include <iomanip>

using namespace std;

// прототип функції сортування
void countingSortAndAnalyze(int arr[], int size, int& maxElement, int*& countArray);

// головна функція
int main()
{
    // запит кількості опитуваних
    int numRespondents;
    cout << "---==== SURVEY ANALYSIS ====---" << endl;
    cout << "Enter the number of respondents: ";
    cin >> numRespondents;

    while (numRespondents <= 0)
    {
        cout << "The number of respondents must be greater than 0." << endl;
        cout << "Enter the number of respondents: ";
        cin >> numRespondents;
    }

    // створення динамічного масиву для зберігання відповідей
    int* responses = new int[numRespondents];
    cout << "Enter the responses (The value must be greater than 0):" << endl;
    for (int i = 0; i < numRespondents; i++)
    {
        cin >> responses[i];
        while (responses[i] <= 0)
        {
            cout << "The value must be greater than 0." << endl;
            cout << "Enter the value: " << endl;
            cin >> responses[i];
        }
    }

    // змінні для максимального варіанту та масиву підрахунку
    int maxElement = 0;
    int* countArray = nullptr;

    // виконання сортування та аналізу
    countingSortAndAnalyze(responses, numRespondents, maxElement, countArray);

    // вивід відсортованих результатів
    cout << "----------------------" << endl;
    cout << "Sorted responses: ";
    for (int i = 0; i < numRespondents; i++)
    {
        cout << responses[i] << " ";
    }
    cout << endl;

    // вивід кількості за варіантами
    cout << "----------------------" << endl;
    cout << "Count of responses by option:" << endl;
    for (int i = 0; i <= maxElement; i++)
    {
        if (countArray[i] > 0)
        {
            cout << "Option " << i << ": " << countArray[i] << endl;
        }
    }

    // вивід результатів у відсотках
    cout << "----------------------" << endl;
    cout << "Percentage results by option:" << endl;
    for (int i = 0; i <= maxElement; i++)
    {
        if (countArray[i] > 0)
        {
            double percentage = (static_cast<double>(countArray[i]) / numRespondents) * 100;
            cout << "Option " << i << ": " << fixed << setprecision(2) << percentage << "%" << endl;
        }
    }

    // вивід мінімального і максимального варіантів відповідей
    int maxOption = -1, minOption = -1;
    int maxCount = 0, minCount = numRespondents + 1;

    for (int i = 0; i <= maxElement; i++)
    {
        if (countArray[i] > 0)
        {
            if (countArray[i] > maxCount)
            {
                maxCount = countArray[i];
                maxOption = i;
            }
            if (countArray[i] < minCount)
            {
                minCount = countArray[i];
                minOption = i;
            }
        }
    }
    cout << "----------------------" << endl;
    cout << "Option with the highest count: Option " << maxOption << " (" << maxCount << " responses)" << endl;
    cout << "Option with the lowest count: Option " << minOption << " (" << minCount << " responses)" << endl;
    cout << "----------------------" << endl;

    // Звільнення пам'яті
    delete[] responses;
    delete[] countArray;

    return 0;
}

// функція для сортування методом підрахунку
void countingSortAndAnalyze(int arr[], int size, int& maxElement, int*& countArray)
{
    // знаходження максимального елементу
    maxElement = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    // створення динамічного масиву для підрахунку елементів
    countArray = new int[maxElement + 1]();
    int* tempCountArray = new int[maxElement + 1]();

    // підрахунок кількості кожного елемента
    for (int i = 0; i < size; i++)
    {
        countArray[arr[i]]++;
        tempCountArray[arr[i]]++;

    }

    // записуємо відсортованого елемента назад в початковий масив
    int index = 0;
    for (int i = 0; i <= maxElement; i++)
    {
        while (tempCountArray[i] > 0)
        {
            arr[index++] = i;
            tempCountArray[i]--;
        }
    }

    // звільнення пам'яті тимчасового масиву
    delete[] tempCountArray;
}