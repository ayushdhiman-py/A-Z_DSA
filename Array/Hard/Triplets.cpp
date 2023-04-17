#include <bits/stdc++.h>
using namespace std;

void brute(vector<int> &v)
{
    // TC: O(n^3) * log(no of unique triplets)
    // SC: 2* O(no of unique triplets)

    set<vector<int>> st;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (v[i] + v[j] + v[k] == 0)
                {
                    // cout << v[i] << " " << v[j] << " " << v[k] << "\n";
                    vector<int> temp = {v[i], v[j], v[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp); // log(no of unique triplets)
                }
            }
        }
    }
    for (auto &it : st)
    {
        for (auto &i : it)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

void better(vector<int> &v)
{
    // TC: O(N^2)* log(size of temp set) // constant if unordered_set
    // SC: O(N) + O(no of unique tripletes) * 2 // because its list of list using an external DS to get all unique triplets

    int n = v.size();
    set<vector<int>> st;
    // O(N^2 --> 2 nested loops)
    for (int i = 0; i < n; i++)
    {
        set<int> check;
        for (int j = i + 1; j < n; j++)
        {
            int ele = -(v[i] + v[j]);
            if (check.find(ele) != check.end())
            {
                // cout << v[i] << " " << v[j] << " " << ele << "\n";
                vector<int> temp = {v[i], v[j], ele};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            check.insert(v[j]);
        }
    }
    for (auto &it : st)
    {
        for (auto &i : it)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

void optimal(vector<int> &v)
{
    
}

int main()
{

    vector<int> v{-1, 0, 1, 2, -1, -4};
    brute(v);
    cout << endl;
    better(v);
    cout << endl;
    optimal(v);

    return 0;
}