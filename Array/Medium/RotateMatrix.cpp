#include <bits/stdc++.h>
using namespace std;

void brute(vector<vector<int>> &v)
{
    int n = v.size();
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            matrix[j][n - i - 1] = v[i][j];
        }
    }

    for (auto &a : matrix)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << "\n";
    }
}

void optimal(vector<vector<int>> &v)
{
    // tc -> O(N) * O(N/2) + O(N) * O(N/2)
    // sc -> inplace
    int n = v.size();
    // for transpose
    // with j from i=1+1 to v.size()
    //
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }

    // USE REVERSE
    for (int i = 0; i < v.size(); i++)
    {
        reverse(v[i].begin(), v[i].end());
    }

    // or with j from 0 to i or
    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         swap(v[i][j], v[j][i]);
    //     }
    // }

    // AND DO SWAP after transpose
    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size() / 2; j++)
    //     {
    //         swap(v[i][v.size() - j - 1], v[i][j]);
    //     }
    // }

    for (auto &a : v)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};
    optimal(v);

    return 0;
}