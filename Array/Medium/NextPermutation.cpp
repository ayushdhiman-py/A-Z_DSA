#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size(), k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
        {
            // cout << nums[k] << " < " << nums[k + 1];
            break;
        }
    }
    if (k < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }
        // cout << "\nswapping  " << nums[k] << " & " << nums[l] << endl;
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }

    cout << "\n";
    for (int &ele : nums)
    {
        cout << ele << " ";
    }
}

int main()
{

    vector<int> v{2, 1, 5, 3, 4, 0, 0};
    nextPermutation(v);

    return 0;
}