#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void brute(vector<pair<int, int>> &v)
{
    // TC :  O(nlogn) + O(2n)
    // SC :  O(n)
    sort(v.begin(), v.end());
    vector<pair<int, int>> res;

    for (int i = 0; i < v.size(); i++)
    {
        pair<int, int> p;
        p.first = v[i].first;
        p.second = v[i].second;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (p.second > v[j].first)
            {
                p.second = max(v[i].second, v[j].second);
                i++;
            }
            else
            {
                break;
            }
        }
        res.push_back({p});
    }

    for (auto &a : res)
    {
        cout << a.first << " " << a.second << "\n";
    }
}

void optimal(vector<vector<int>> &v2)
{
    // TC : O(nlogn) + O(n)
    // TC : O(n)
    int n = v2.size();
    vector<vector<int>> ans;
    sort(v2.begin(), v2.end());

    for (int i = 0; i < n; i++)
    {
        // ans.empty() because if there is no element in there then we dont have anything to compare with
        // ans.back()[1] means value "6" of {1,6} which is the recent pair of ans vector

        // if not a part of a interval
        if (ans.empty() || v2[i][0] > ans.back()[1])
        {
            ans.push_back(v2[i]);
            // Pushed a new pair or interval (eg. {1,3} or {8,9} )
        }

        // if it's a part of a interval
        else
        {
            ans.back()[1] = max(ans.back()[1], v2[i][1]);
        }
    }
    for (auto &a : ans)
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

    fast;

    vector<pair<int, int>> v = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    vector<vector<int>> v2 = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    // brute(v);
    optimal(v2);

    return 0;
}