#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

// left should be > twice of right element
// Arr[i] > 2*Arr[j]
// correct -> (9,2) // incorrect -> (9,6)

// BRUTE FORCE || TC:O(N^2)
void brute(vector<int> v)
{
    int cnt = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] > (2 * v[j]))
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

int countPairs(vector<int> &v, int start, int mid, int end)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = start; i <= mid; i++)
    {
        while (right <= end && v[i] > 2 * v[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &v, int start, int end)
{
    int c = 0;
    if (start >= end)
        return c;
    int mid = start + (end - start) / 2;
    c += mergeSort(v, start, mid);
    c += mergeSort(v, mid + 1, end);
    c += countPairs(v, start, mid, end);
    merge(v, start, mid, end);
    return c;
}
void optimal(vector<int> &skill)
{
    int n = skill.size();
    cout << mergeSort(skill, 0, n - 1);
}

int main()
{

    fast;

    vector<int> v{40, 25, 19, 12, 9, 6, 2};
    brute(v);
    optimal(v);

    return 0;
}