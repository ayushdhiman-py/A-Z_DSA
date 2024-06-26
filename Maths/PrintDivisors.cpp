#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int main()
{

    fast;

    int n = 36;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
            {
                cout << n / i << " ";
            }
            cout << i << " ";
        }
    }

    return 0;
}