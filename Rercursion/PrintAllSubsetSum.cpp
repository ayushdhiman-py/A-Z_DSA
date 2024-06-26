#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void printAll(vector<int> &v, int sum, int i)
{
    if (i == v.size())
    {
        cout << sum << "\n";
        return;
    }
    printAll(v, sum + v[i], i + 1);
    printAll(v, sum, i + 1);
}

int main()
{

    fast;
    vector<int> v = {3, 4, 6};
    printAll(v, 0, 0);

    return 0;
}