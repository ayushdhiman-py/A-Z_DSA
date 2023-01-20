#include <bits/stdc++.h>
using namespace std;

// provides negative product subsequence
void negativeProdSubsequences(int index, int prod, vector<int> &v, vector<int> &res)
{
    if (index == v.size())
    {
        if (prod < 0)
        {
            for (auto a : res)
            {
                cout << a << " ";
            }
            cout << "\n";
        }
        return;
    }
    res.push_back(v[index]);
    prod *= v[index];
    negativeProdSubsequences(index + 1, prod, v, res);
    prod /= v[index];
    res.pop_back();
    negativeProdSubsequences(index + 1, prod, v, res);
}

// provides negative product subsequence
class Solution
{
    void findCombinations(int index, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (index == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, ans, ds);
            ds.pop_back();
        }
        findCombinations(index + 1, target, candidates, ans, ds);
    }

public:
    void combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans; // stores all the combinations
        vector<int> ds;          // used in recursion
        findCombinations(0, target, candidates, ans, ds);
        for (auto &a : ans)
        {
            for (auto &b : a)
            {
                cout << b << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    // provides negative product subsequence
    // vector<int> v = {1, -5, -6};
    // vector<int> res;
    // negativeProdSubsequences(0, 1, v, res);
    // return 0;

    // provides combination sum which is equal to target
    Solution obj;
    vector<int> v = {3, 3, 1};
    int target = 7;
    obj.combinationSum(v, target);
}