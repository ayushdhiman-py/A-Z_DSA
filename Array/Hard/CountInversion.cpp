#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int merge(vector<int> &v, int low, int high)
{
    int count = 0;
    int mid = (low + high) / 2;

    int len1 = mid - low + 1;
    int len2 = high - mid;

    int *a1 = new int[len1];
    int *a2 = new int[len2];

    int mainArrayIndex = low;
    for (int i = 0; i < len1; i++)
    {
        a1[i] = v[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len1; i++)
    {
        a2[i] = v[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = low;

    while (index1 < len1 && index2 < len2)
    {
        if (a1[index1] < a2[index2])
        {
            v[mainArrayIndex++] = a1[index1++];
        }
        else
        {
            count += (mid - low + 1);
            v[mainArrayIndex++] = a2[index2++];
        }
    }

    while (index1 < len1)
    {
        v[mainArrayIndex++] = a1[index1++];
    }

    while (index2 < len2)
    {
        v[mainArrayIndex++] = a2[index2++];
    }

    delete[] a1;
    delete[] a2;
    return count;
}

int mergeSort(vector<int> &v, int low, int high)
{
    int count = 0;
    if (low >= high)
    {
        return count;
    }
    int mid = low + (high - low) / 2;
    count += mergeSort(v, low, mid);
    count += mergeSort(v, mid + 1, high);
    count += merge(v, low, high);
    return count;
}

int main()
{

    fast;

    vector<int> v = {5, 3, 2, 4, 1};
    int size = v.size();
    int res = mergeSort(v, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << res;
    return 0;
}