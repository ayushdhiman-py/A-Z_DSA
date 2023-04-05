#include <bits/stdc++.h>
using namespace std;

void minimizeArrayValue(vector<int> &nums)
{
    long long int answer = nums[0], computed = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        computed += nums[i];
        long long int temp = (long long int)ceil((double)computed / (i + 1));
        answer = max(answer, temp);
    }

    cout << answer;
}

int main()
{
    // your code goes here
    vector<int> nums{13, 13, 20, 0, 8, 9, 9};
    minimizeArrayValue(nums);

    return 0;
}
