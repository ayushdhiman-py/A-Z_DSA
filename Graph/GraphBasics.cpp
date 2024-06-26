#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class UnWeighted
{

    void matrixRepresentation()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u - 1][v - 1] = 1;
            adj[v - 1][u - 1] = 1;
        }

        for (auto &it : adj)
        {
            for (auto &iit : it)
            {
                cout << iit << " ";
            }
            cout << "\n";
        }
    }

    void listRepresentation()
    {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n + 1];
        for (int i = 0; i <= n; i++)
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
        
        for (auto &it : adj)
        {
            cout << i++ << "->";
            for (auto &iit : it)
            {
                cout << iit << " ";
            }
            cout << "\n";
        }
    }
};

class Weighted
{
    // same as of unweighted but
    // in case of matrix => we do not assign 1 when marking it in matrix just assign the weight thats given
    // by user

    // in case of a list => store pairs instead of just a node linked with a node
    //              node,weight  
    // eg := 4-->{ {2,1}, {3,4} } 
};

int main()
{

    fast;

    // matrixRepresentation();
    // listRepresentation();
    return 0;
}