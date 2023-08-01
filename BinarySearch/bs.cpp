#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int iterative(vector<int> v, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == target)
        {
            return mid + 1;
        }
        else if (v[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int recursive(vector<int> v, int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (v[mid] == target)
    {
        return mid + 1;
    }
    else if (v[mid] < target)
    {
        return recursive(v, mid + 1, high, target);
    }
    return recursive(v, low, mid - 1, target);
}



int lowerBound(vector<int> arr, int n, int target)
{
    int start = 0, end = n - 1;
    int ans = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}


int upperBound(vector<int> &arr, int target, int n)
{
    int start = 0, end = n - 1;
    int ans = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{

    fast;

    int target = 5;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 10};
    int n = v.size();

    cout << iterative(v, 0, n - 1, target) << "\n";
    cout << recursive(v, 0, n - 1, target);

    return 0;
}