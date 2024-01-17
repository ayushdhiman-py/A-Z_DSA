#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void generateSet(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < (1 << n); i++)
    {
        string sub = "";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sub += to_string(v[j]);
            }
        }
        cout << sub << '\n';
    }
}

int main()
{

    fast;

    vector<int> v = {1, 2, 3};
    generateSet(v);

    return 0;
}