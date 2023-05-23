#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{

    fast;

    vector<int> v{2, 3, -2, 4};
    int pre = 1, suf = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;

        pre *= v[i];
        suf *= v[i];
        maxi = max(maxi, max(pre, suf));
    }
    cout << maxi;

    return 0;
}