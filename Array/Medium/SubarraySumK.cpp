#include <bits/stdc++.h>
using namespace std;

void bruteSumK(vector<int> &v, int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            if (sum == k)
            {
                cnt = max(cnt, j - i + 1);
                break;
            }
        }
    }
    cout << cnt << " ";
}

void optimalLongestSubarrayWithSumK(vector<int> a, int size, int k)
{
    unordered_map<long long, int> mpp;
    long long sum = 0;
    int maxlength = 0;

    for (int i = 0; i < size; i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxlength = max(maxlength, i + 1);
        }
        long long rem = sum - k;
        if (mpp.find(rem) != mpp.end())
        {
            auto ele = mpp.find(rem);
            int len = i - mpp[rem];
            maxlength = max(maxlength, len);
        }
        // follwing line will work for the integers > than 0;
        // mpp[sum] = i;

        // but for all the integers -ve and +ves then we have to check that it should not get updated
        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }
    cout << maxlength;
}

// FOR +ves and zeroes only //
void twoPointers(vector<int> a, int size, int k)
{
    int i = 0, j = 0;
    int currSum = a[0];
    int maxLen = 0;
    while (j < size)
    {
        cout << currSum << "->abhi ka sum" << i << "\n";

        while (i <= j && currSum > k)
        {
            currSum -= a[i];
            i++;
        }

        if (currSum == k)
        {
            maxLen = max(maxLen, j - i + 1);
        }

        j++;
        if (j < size)
        {
            currSum += a[j];
        }
    }
    cout << maxLen;
}

int main()
{

    vector<int> v = {1, 0, 2, 3, 1, 1, 1, 1, 4, 2, 3, 1, 0, 1, 1, 1, 1, 2, 3, 3, 1, 1, 2, 1, 1, 1};
    int n = v.size();
    int k = 5;
    twoPointers(v, n, k);
}