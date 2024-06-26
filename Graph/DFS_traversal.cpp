#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);
        // traverse all its neighbours
        for (auto it : adj[node])
        {
            // if the neighbour is not visited
            if (!vis[it])
            {
                dfs(it, adj, vis, ls);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int start = adj[1][0];
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[9];

    addEdge(adj, 1, 2);
    addEdge(adj, 3, 1);
    addEdge(adj, 5, 2);
    addEdge(adj, 6, 2);
    addEdge(adj, 7, 3);
    addEdge(adj, 4, 3);
    addEdge(adj, 8, 4);
    addEdge(adj, 7, 8);

    cout << adj[2][0];

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(9, adj);
    printAns(ans);

    return 0;
}