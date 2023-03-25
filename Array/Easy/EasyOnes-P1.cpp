#include <bits/stdc++.h>
using namespace std;

void largest(vector<int> arr)
{
    int largest = arr[0];

    for (auto ele : arr)
    {
        largest = max(largest, ele);
    }

    cout << largest;
}

int secondLargest(vector<int> &a, int n)
{
    int largest = a[0];
    int slargest = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] != largest && a[i] > slargest)
        {
            slargest = a[i];
        }
    }
    return slargest;
}

int secondSmallest(vector<int> a, int n)
{
    int smallest = a[0];
    int sSmallest = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < smallest)
        {
            sSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] != smallest && a[i] < sSmallest)
        {
            sSmallest = a[i];
        }
    }
    return sSmallest;
}

void secondLargestAndSmallest(vector<int> arr)
{
    int size = arr.size();
    int sLargest = secondLargest(arr, size);
    int sSmallest = secondSmallest(arr, size);
    cout << sLargest << " " << sSmallest;
}

bool arraySorted(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int removeDuplicates(vector<int> &arr)
{
    int i = 0;
    int j = 1;
    while (j < arr.size())
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
        j++;
    }
    return (i + 1);
}

int main()
{

    vector<int> arr{2, 3, 4, 5, 6};
    secondLargestAndSmallest(arr);

    return 0;
}