#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int i = s;
    int j = e;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= e - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= s + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[s], arr[j]);
    return j;
}

void quicksort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        quicksort(arr, s, p - 1);
        quicksort(arr, p + 1, e);
    }
}

int main()
{
    int arr[] = {10, 20, 7, 1, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}