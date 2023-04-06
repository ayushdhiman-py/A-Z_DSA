#include <bits/stdc++.h>
using namespace std;

void myOwnMethod(vector<int> nums)
{
    vector<int> leaders;
    leaders.push_back(nums[nums.size() - 1]);
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] > nums[i + 1])
        {
            leaders.push_back(nums[i]);
        }
        else
        {
            nums[i] = nums[i + 1];
        }
    }

    for (auto &a : leaders)
    {
        cout << a << " ";
    }
}

void Leaders(vector<int> nums)
{
    // O(n)
    vector<int> leaders;
    int maxi = INT_MIN;
    int n = nums.size();

    // to collect O(n)
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > maxi)
        {
            leaders.push_back(nums[i]);
        }
        // keeps track of right maximun
        maxi = max(maxi, nums[i]);
    }

    // if sorting is done then O(nlogn) will be added to tc

    for (auto &a : leaders)
    {
        cout << a << " ";
    }
}

int main()
{
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    Leaders(nums);

    return 0;
}