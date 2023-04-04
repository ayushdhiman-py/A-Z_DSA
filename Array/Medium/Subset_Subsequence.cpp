#include <bits/stdc++.h>
using namespace std;

void subsetsSolve(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int idx)
{
    if (idx == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    // exclude
    subsetsSolve(nums, ans, temp, idx + 1);

    temp.push_back(nums[idx]);

    // include
    subsetsSolve(nums, ans, temp, idx + 1);
}

void subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int idx = 0;
    subsetsSolve(nums, ans, temp, idx);

    for (auto &a : ans)
    {
        for (auto &ele : a)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
}

void subsequenceSolve(string str, string op, int it, vector<string> &ans)
{
    if (it >= str.length())
    {
        // agar empty substring nahi chahiye to ye condition lagegi
        if (op.length() > 0)
        {
            ans.push_back(op);
        }
        return;
    }
    // exclude
    subsequenceSolve(str, op, it + 1, ans);
    // include
    char ele = str[it];
    op.push_back(ele);
    subsequenceSolve(str, op, it + 1, ans);
}

void subsequence(string str)
{
    vector<string> ans;
    string op = "";
    int it = 0;
    subsequenceSolve(str, op, it, ans);
    for (auto &a : ans)
    {
        cout << a << " ";
    }
}

int main()
{
    string s = "abc";
    subsequence(s);
    return 0;
}