#include <bits/stdc++.h>
using namespace std;

// time complexity is O(n^2)
void selection_sort(vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i < size - 1; i++)
    {
        int mini = i;
        for (int j = i; j < size; j++)
        {
            if (v[mini] > v[j])
            {
                mini = j;
            }
        }
        swap(v[mini], v[i]);
    }
}

void bubble_sort(vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (v[i] < v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }

    for (int i = size - 1; i >= 1; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (v[j + 1] < v[j])
            {
                swap(v[j + 1], v[j]);
            }
        }
    }
    // OPTIMIZED (will not print as upper for loop already sorted the array !)
    for (int i = size - 1; i >= 1; i--)
    {
        int swapped = 0;
        for (int j = 0; j < i - 1; j++)
        {
            if (v[j + 1] < v[j])
            {
                swap(v[j + 1], v[j]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
        cout << "runs\n";
    }
}

void insertion_sort(vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            swap(v[j - 1], v[j]);
            j--;
        }
    }
}

int main()
{

    vector<int> v1 = {13, 46, 24, 52, 20, 9};
    selection_sort(v1);
    for (auto &e : v1)
    {
        cout << e << " ";
    }

    cout << "\n";

    vector<int> v2 = {13, 46, 24, 52, 20, 9};
    bubble_sort(v2);
    for (auto &e : v2)
    {
        cout << e << " ";
    }

    cout << "\n";

    vector<int> v3 = {13, 46, 24, 52, 20, 9};
    insertion_sort(v3);
    for (auto &e : v3)
    {
        cout << e << " ";
    }
    return 0;
}