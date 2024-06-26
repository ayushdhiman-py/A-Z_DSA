#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void bfs(vector<vector<int>> &vis, vector<vector<char>> &grid, int n, int m)
{
    vis[n][m] = 1;
    queue<pair<int, int>> q;
    q.push({n, m});
    int nsize = grid.size();
    int msize = grid[0].size();

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse neighbours //
        for (int nrow = -1; nrow <= 1; nrow++)
        {
            for (int ncol = -1; ncol <= 1; ncol++)
            {
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int numberOfIsland(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && grid[row][col] == '1')
            {
                cnt++;
                bfs(vis, grid, n, m);
            }
        }
    }
    return cnt;
}

int main()
{

    fast;

    return 0;
}