#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp;
    int low = left;
    int high = mid + 1;

    while (low <= mid && high <= right)
    {
        if (arr[low] <= arr[high])
        {
            temp.push_back(arr[low]);
            low++;
        }
        else
        {
            temp.push_back(arr[high]);
            high++;
        }
    }
    while (low <= mid)
    {
        temp.push_back(arr[low]);
        low++;
    }
    while (high <= right)
    {
        temp.push_back(arr[high]);
        high++;
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left == right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{

    vector<int> v{0, 1, 9, 6, 7, 3, 98, 37, 2, 4};
    mergeSort(v, 0, v.size() - 1);
    for (auto a : v)
    {
        cout << a << " ";
    }
    return 0;
}