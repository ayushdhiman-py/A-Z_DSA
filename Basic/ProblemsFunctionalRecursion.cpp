#include <bits/stdc++.h>
using namespace std;

void reverseArray(int start, int end, vector<int> &v)
{
    if (start >= end)
    {
        return;
    }
    swap(v[start], v[end]);
    reverseArray(start + 1, end - 1, v);
}

bool pailindromicString(int i, string s)
{
    if (i >= s.size() / 2)
    {
        return true;
    }
    if (s[i] != s[s.size() - i - 1])
    {
        return false;
    }
    return pailindromicString(i + 1, s);
}

int main()
{

    // vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // reverseArray(0, v.size()-1, v);
    // for (auto a : v)
    // {
    //     cout << a << " ";
    // }

    cout << (pailindromicString(0, "ayushhsuya") ? "True" : "False");
    return 0;
}