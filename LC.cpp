#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int maxKSubarraySum(vector<int> &a, int k)
{
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }

    int maxi = sum;

    for (int i = k; i < n; i++)
    {
        sum = sum + a[i] - a[i - k];
        maxi = max(maxi, sum);
    }

    return maxi;
}

int main()
{

    fast;
    int k = 3;
    vector<int> a = {3, 5, 6, 2, 4, 7, 8};
    cout << maxKSubarraySum(a, k);

    return 0;
}