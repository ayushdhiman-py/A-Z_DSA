#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int idx)
{
    if (idx == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    // exclude
    solve(nums, ans, temp, idx + 1);

    temp.push_back(nums[idx]);

    // include
    solve(nums, ans, temp, idx + 1);
}

void subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int idx = 0;
    solve(nums, ans, temp, idx);
    
    for (auto &a : ans)
    {
        for (auto &ele : a)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<int> nums{1, 2, 3};
    subsets(nums);
    return 0;
}