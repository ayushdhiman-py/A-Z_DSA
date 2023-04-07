#include <bits/stdc++.h>
using namespace std;

void brute(vector<vector<int>> &v)
{
    // tc = O(n) * O(m) + O(n+m) + O(n) * O(m)
    //    = somewhere around O(n^3)
    int n = v.size();
    for (int i = 0; i < n; i++) // O(n)
    {
        for (int j = 0; j < v[i].size(); j++) // O(m)
        {
            if (v[i][j] == 0)
            {
                for (int k = 0; k < v[i].size(); k++) // O(n)
                {
                    if (v[i][k] != 0)
                    {
                        v[i][k] = -1;
                    }
                }
                for (int k = 0; k < n; k++) // O(m)
                {
                    if (v[k][j] != 0)
                    {
                        v[k][j] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) // O(n)
    {
        for (int j = 0; j < v[i].size(); j++) // O(m)
        {
            if (v[i][j] == -1)
            {
                v[i][j] = 0;
            }
        }
    }
    for (auto &i : v)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void better(vector<vector<int>> &v)
{

    // TC - O ( 2 * m * n )
    // SC - O ( n ) + O( m )

    vector<int> col(v.size(), 0), row(v[0].size(), 0);

    for (int i = 0; i < v.size(); i++) // O(n)
    {
        for (int j = 0; j < v[i].size(); j++) // O(m)
        {
            if (v[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < v.size(); i++) // O(n)
    {
        for (int j = 0; j < v[i].size(); j++) // O(m)
        {
            if (row[i] || col[j])
            {
                v[i][j] = 0;
            }
        }
    }
    for (auto &i : v)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void optimal(vector<vector<int>> &matrix, int n, int m)
{

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
    for (auto &i : matrix)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{

    vector<vector<int>> v = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 0, 0, 1}};
    optimal(v, v.size(), v[0].size());

    return 0;
}