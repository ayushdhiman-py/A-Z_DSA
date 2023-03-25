#include <bits/stdc++.h>
using namespace std;

void better(vector<int> v, int t)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < v.size(); i++)
    {
        if (mpp.find(t - v[i]) != mpp.end())
        {
            auto it = mpp.find(t - v[i]);
            cout << it->second << " " << i;
        }
        mpp[v[i]] = i;
    }
}

void optimal(vector<int> v, int t)
{
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] == t)
        {
            cout << v[i] << v[j];
            return;
        }
        else if (v[i] + v[j] > t)
        {
            j--;
        }
        else if (v[i] + v[j] < t)
        {
            i++;
        }
    }
}

int main()
{

    vector<int> v = {2, 5, 6, 8, 11};
    int target = 14;

    optimal(v, target);

    return 0;
}