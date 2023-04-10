#include <bits/stdc++.h>
using namespace std;

// my shit method
bool isValid(string s)
{
    if (s.length() <= 1)
    {
        return false;
    }
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if ((!st.empty() && (s[i] == ')' && st.top() == '(')) || (!st.empty() && (s[i] == ']' && st.top() == '[')) || !st.empty() && (s[i] == '}' && st.top() == '{'))
        {
            st.pop();
        }
        else if ((!st.empty() && (s[i] == ')' && st.top() != '(')) || (!st.empty() && (s[i] == ']' && st.top() != '[')) || !st.empty() && (s[i] == '}' && st.top() != '{'))
        {
            return false;
        }
        else if (st.empty() && s[i] == '}' || st.empty() && s[i] == ')' || st.empty() && s[i] == ']')
        {
            return false;
        }
    }
    return true;
}

bool StackisValid(string s)
{
    stack<char> st;

    for (auto i : s)
    {
        if (i == '[' || i == '(' || i == '{')
            st.push(i);
        else
        {
            if (st.empty() || (st.top() == '(' and i != ')') or (st.top() == '{' and i != '}') or (st.top() == '[' and i != ']'))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{

    cout << (StackisValid("(])") ? "true" : "false");

    return 0;
}