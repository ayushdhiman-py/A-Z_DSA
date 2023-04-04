#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int ind = -1;
    int n = nums.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            cout << nums[i] << "<" << nums[i + 1] << endl;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            cout << "swapped" << nums[i] << "&" << nums[ind] << endl;
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() + ind + 1, nums.end());

    cout << "\n";
    for (int &ele : nums)
    {
        cout << ele << " ";
    }
}

int main()
{

    vector<int> v{2, 0, 8, 1, 7, 2};
    nextPermutation(v);

    return 0;
}
