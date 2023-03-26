#include <bits/stdc++.h>
using namespace std;

// MAX SUBARRAY SUM
void kadaneAlgo(vector<int> v)
{
    int n = v.size();
    int maxSum = 0;
    int sum = 0;
    int astart = -1, aend = -1, start = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += v[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            astart = start;
            aend = i;
        }
        if (sum < 1)
        {
            sum = 0;
        }
    }
    cout << endl
         << maxSum;
    cout << endl;

    for (int i = astart; i <= aend; i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3};
    kadaneAlgo(v);

    return 0;
}