#include <bits/stdc++.h>
using namespace std;

void zeroOneTwo(vector<int> &v)
{
    int l = 0, mid = 0, h = v.size() - 1;
    while (mid <= h)
    {
        if (v[mid] == 0)
        {
            swap(v[l], v[mid]);
            l++;
            mid++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else if (v[mid] == 2)
        {
            swap(v[mid], v[h]);
            h--;
        }
    }
}

int main()
{
    vector<int> v = {1, 0, 2, 0, 1, 0, 0, 0, 2, 2, 1, 2, 0, 1, 0};
    zeroOneTwo(v);
    for (auto &a : v)
    {
        cout << a << " ";
    }
    return 0;
}