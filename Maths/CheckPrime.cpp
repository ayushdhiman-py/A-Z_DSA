#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{

    fast;
    int cnt = 0;
    int n = 4;
    for (int i = 2; i<n; i++)
    {
        if (n % i == 0)
        {
            cout << "Not Prime";
            return 0;
        }
    }
    cout << "prime";

    return 0;
}