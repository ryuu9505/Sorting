#include <array>
#include <iostream>
#include <limits>
#include <random>

using namespace std;

array<int, 10> SelectionSort(array<int, 10> arr)
{
    int temp, min, idx_min, i, j;

    for (i = 1; i < arr.size(); i++)
    {
        min = arr[i-1];
        for (j = i; j < arr.size(); j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                idx_min = j;
            }
        }

        if (min != arr[i-1])
        {
            arr[idx_min] = arr[i - 1];
            arr[i - 1] = min;
        }
    }
    return arr;
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

    arr = SelectionSort(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;


}