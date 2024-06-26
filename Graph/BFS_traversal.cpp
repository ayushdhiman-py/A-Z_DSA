#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void listRepresentation(int n, int m, vector<int> *adj)
{
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "\n";
    cout << "\n";
    cout << "\n";
    int i = 0;

    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (auto &iit : adj[i])
        {
            cout << iit << " ";
        }
        cout << "\n";
    }
}

vector<int> bfs(int n, int m, vector<int> *adj)
{
    // vector<int> v = {n, 0};
    // int v[n + 1] = {0};
    vector<int> v(n + 1, 0);
    v[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> res;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (auto &it : adj[node])
        {
            if (!v[it])
            {
                v[it] = 1;
                q.push(it);
            }
        }
        cout << "indeix\n";
    }
   
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    listRepresentation(n, m, adj);
    vector<int> bfstrav = bfs(n, m, adj);
    cout << "printing bfs\n";

    for (auto &i : bfstrav)
    {
        cout << i << "\n";
    }
    fast;

    return 0;
}