#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void solve(string s)
{
    for (int i = 0; i < (1 << s.length()); i++)
    {
        string sub = "";
        for (int j = 0; j < s.length(); j++)
        {
            if (i & (1 << j))
            {
                sub += s[j];
            }
        }
        cout << sub << "\n";
    }
}
// Time Complexity: O(2^n * n)
// Reason: O(2^n) for the outer for loop and O(n) for the inner for loop.

void solve(int i, string s, string &f)
{
    if (i == s.length())
    {
        cout << f << " ";
        return;
    }
    // picking
    f = f + s[i];
    solve(i + 1, s, f);
    // poping out while backtracking
    f.pop_back();
    solve(i + 1, s, f);
}
// Time Complexity: O(2^n)


int main()
{

    fast;

    string s = "abc";
    solve(s);
    string f = "";
    solve(0, s, f);

    return 0;
}