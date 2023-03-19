#include <bits/stdc++.h>
using namespace std;

void missingNumber(vector<int> &a)
{
    int N = a.size() - 1;
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N;
    cout << (xor1 ^ xor2);
}

void maxConsecutive(vector<int> &a)
{
    int maxi = 0;
    int count = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] == 1)
        {
            count += 1;
        }
        else
        {
            maxi = max(maxi, count);
            count = 0;
        }
    }
    cout << maxi;
}

void seenOnce(vector<int> &a)
{
    int res = 0;

    for (auto &ele : a)
    {
        res ^= ele;
    }
    cout << res;
}

int main()
{
    vector<int> v{1, 2, 3, 1, 2};
    seenOnce(v);
    return 0;
}