// C++ program for Pascal’s Triangle
// A O(n^2) time and O(1) extra space
// function for Pascal's Triangle
#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r)
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void printNthLineBRUTE(int n)
{
    for (int c = 1; c <= n; c++)
    {
        cout << nCr(n - 1, c - 1) << " ";
    }
}

void printNthLineBETTER(int n)
{
    int res = 1;
    cout << res;
    for (int i = 1; i < n; i++)
    {
        res = (int)res * (n - i);
        res = (int)res / i;
        cout << res;
    }
}

void printPascal(int n)
{

    for (int line = 1; line <= n; line++)
    {
        int C = 1; // used to represent C(line, i)
        for (int i = 1; i <= line; i++)
        {

            // The first value in a line is always 1
            cout << C << " ";
            C = C * (line - i) / i;
        }
        cout << "\n";
    }
}

// Driver code
int main()
{
    int n = 5;
    cout << nCr(5, 3);
    // cout<<printNthLineBRUTE(n);
    // cout<<printNthLineBETTER(n);
    return 0;
}

// This code is contributed by Code_Mech
