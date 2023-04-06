#include <bits/stdc++.h>
using namespace std;

class Brute
{
public:
    bool ls(vector<int> nums, int x)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == x)
            {
                return true;
            }
        }
        return false;
    }

    // about O(n^2)
    void brute(vector<int> nums)
    {
        int longest = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            int count = 1;
            while (ls(nums, x + 1) == true)
            {
                x = x + 1;
                count += 1;
            }
            longest = max(longest, count);
        }
        cout << longest;
    }

    void myBrute(vector<int> nums)
    {
        int longest = 1;
        int n = nums.size();
        int largest = 1;
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            int toFind = nums[i] + 1;

            for (int j = 0; j < n; j++)
            {
                if (nums[j] == toFind)
                {
                    toFind += 1;
                    count++;
                    j = 0;
                }
            }
            largest = max(largest, count);
        }
        cout << largest;
    }

    void better(vector<int> nums)
    {
        // tc = O(n) + O(n) + O(n) = 3N
        // sc = O(n)
        int n = nums.size();
        int longest = 1;
        unordered_set<int> check;

        // O(n)
        for (int i = 0; i < n; i++)
        {
            check.insert(nums[i]);
        }

        // O(n) + O(n) = 2(n) // (-->>  coz 7+3+4 = 14 which is equivalent to near to the 2N <--)
        for (auto &it : check)
        {
            if (check.find(it - 1) == check.end())
            {
                int cnt = 1;
                int x = it;
                while (check.find(x + 1) != check.end())
                {
                    x += 1;
                    cnt += 1;
                }
                longest = max(longest, cnt);
            }
        }
        cout << longest;
    }
};

int main()
{
    vector<int> nums = {102, 100, 101, 3, 1, 2, 1, 0};
    Brute b1;
    b1.better(nums);
    return 0;
}