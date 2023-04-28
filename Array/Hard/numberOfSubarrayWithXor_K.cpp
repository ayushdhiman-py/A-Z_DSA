#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void subarrayXorK(vector<int> v, int k)
{
    int xr = 0;
    unordered_map<int, int> mpp;
    mpp[xr]++;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        xr = xr ^ v[i];
        int x = xr ^ k;
        count += mpp[x];
        mpp[xr]++;
    }
    cout << count;
}

void subarrayXorK_Mine(vector<int> v, int k)
{
    int count = 0;
    unordered_map<int, int> mpp;
    int xorr = 0;
    mpp[xorr]++;
    for (int i = 0; i < v.size(); i++)
    {
        xorr = xorr ^ v[i];
        int x = xorr ^ k;
        if (mpp.find(x) != mpp.end())
        {
            auto temp = mpp.find(x);
            count += temp->second;
        }
        mpp[xorr]++;
    }
    cout << count;
}

int main()
{
    fast;

    vector<int> v = {4, 2, 2, 6, 4};
    int k = 6;
    subarrayXorK(v, k);
    subarrayXorK_Mine(v, k);
    return 0;
}
