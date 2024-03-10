#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int bin2dec(string s)
{
    int pow = 1;
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            res += pow;
        }
        pow *= 2;
    }
    return res;
}

string dec2bin(int n)
{
    string res = "";

    while (n > 0)
    {
        if (n % 2 == 1)
            res += '1';
        else
            res += '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    fast;
    string s = "1011";
    cout << bin2dec(s);
    cout << "\n";
    cout << dec2bin(11);

    return 0;
}