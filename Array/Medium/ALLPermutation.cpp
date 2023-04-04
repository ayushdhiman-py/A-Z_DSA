#include <bits/stdc++.h>
using namespace std;

void permute(vector<int> &nums, vector<int> ds, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            permute(nums, ds, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
    return;
}

void permuteWithSwapBetter(vector<int> &nums, vector<vector<int>> &ans, int idx)
{
    if (idx == nums.size() - 1)
    {
        ans.push_back(nums);
        return;
    }
    else
    {
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            permuteWithSwapBetter(nums, ans, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
}

void allPermutations(vector<int> &v)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int n = v.size();
    int freq[n] = {0};
    int idx = 0;
    permuteWithSwapBetter(v, ans, idx);

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

    vector<int> v = {1, 2, 3};
    allPermutations(v);

    return 0;
}