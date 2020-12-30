#include <array>
#include <iostream>
#include <random>

using namespace std;

void SelectionSort(array<int, 10> arr)
{
    int temp, idx_min, i, j;

    for (i = 1; i < arr.size(); i++)
    {
        for (j = i; j > arr.size(); j++)
            if (arr[i - 1] > arr[j])
                idx_min = j;
        temp = arr[i - 1];
        arr[i - 1] = arr[idx_min];
        arr[idx_min] = temp;
    }
}

int main()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dis(0, 99);

    array<int, 10> arr;
    for (int i = 0; i < arr.size(); i++)
        arr[i] = dis(gen);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    SelectionSort(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;


}