#include <bits/stdc++.h>
using namespace std;

void rotateByOne(vector<int> &arr)
{
    int firstEle = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = firstEle;
}

void rotateByK(vector<int> &arr, int k)
{
    int arrSize = arr.size();
    int i = 0, j = k - 1;
    while (i <= j)
    {
        swap(arr[i++], arr[j--]);
    }
    int a = k, b = arrSize - 1;
    while (a <= b)
    {
        swap(arr[a++], arr[b--]);
    }
    int x = 0, y = arrSize - 1;
    while (x <= y)
    {
        swap(arr[x++], arr[y--]);
    }
}

void moveZeroes(vector<int> &arr)
{
    int n = arr.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;

    for (int i = j; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j++]);
        }
    }
    return;
}

vector<int> unionn(vector<int> &arr1, vector<int> arr2)
{
    //TC :  n1+n2 
    //SC :  n1+n2 
    int i = 0, j = 0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> unionarr;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionarr.size() == 0 || unionarr.back() != arr1[i])
            {
                unionarr.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (unionarr.size() == 0 || unionarr.back() != arr2[j])
            {
                unionarr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (unionarr.size() == 0 || unionarr.back() != arr1[i])
        {
            unionarr.push_back(arr1[i]);    
        }
        i++;
    }
    while (j < n2)
    {
        if (unionarr.size() == 0 || unionarr.back() != arr1[j])
        {
            unionarr.push_back(arr1[j]);
        }
        j++;
    }
    return unionarr;
}

int main()
{
    vector<int> arr1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> arr2{1, 2, 3, 4, 5, 6};
    vector<int> result = unionn(arr1, arr2);
    for (auto &a : result)
    {
        cout << a << " ";
    }

    return 0;
}