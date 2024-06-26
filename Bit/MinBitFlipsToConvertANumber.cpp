#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void printBinary(int n)
{
    string s = "";
    for (int i = 0; i <= 31; i++)
    {
        if (n & (1 << i))
        {
            s += '1';
        }
        else
        {
            s += '0';
        }
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

int main()
{

    fast;

    int n = 128, goal = 17;

    int ans = n ^ goal;
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {
        if (ans & (1 << i))
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
    cout << "\n";
    printBinary(n);
    cout << "\n";
    printBinary(goal);
    cout << "\n";

    return 0;
}
