#include <bits/stdc++.h>
using namespace std;

// Brute is to run 3 loops
// Better is to run 2 loops

void Better(vector<int> v, int k)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0, j;
        for (j = i; j < v.size(); j++)
        {
            sum += v[j];

            if (sum == k)
            {
                cout << "from " << v[i] << "to" << v[j] << "\n";
                count++;
            }
        }
    }
    cout << count << "\n";
}

void Optimal(vector<int> v, int target)
{
    // Intution behind this algo is that we are adding up each value of the array in the ps(prefix sum) and we are checking constantly that can we chop off some previous value that we are able to make the ps === target.

    // TC:-
    // O(n * logN) - simple map
    // O(n * 1 for best or n for worst)

    // SC: O(n)

    unordered_map<int, int> mpp;
    int count = 0, sum = 0;
    mpp[0] = 1;

    // COUNTING REASON :-> the reason behind having a count of a prefix sum is that we could have -ve
    // values the array and there could be multiple subarrays/prefixes of the same prefix sum

    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        int toRemove = sum - target;
        // in the below line "count" of "value -> -2" is getting added to count variable and here its "0" because -2 does not even exists
        count += mpp[toRemove];
        // then here below, we are updating the count of the "current prefix sum" value in the map
        // we got here how many prefix sum are there of the value sum so that whenever we get the sum == k we know that if we check the count of value got by substraction of currSum and target we already know that these many subarrays can be formed if we remove those prefix sum subarray from the current subarray that much time
        mpp[sum] += 1;
    }
    cout << count << "\n";

    // the link below this file is real reason behind having a count of every prefix "sum". Check the image

    //https: // drive.google.com/file/d/1HiXYdSKB7vwKa-iwWn0S-BZOO6XNWze9/view?usp=sharing

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< VERY VERY IMPORTANT POINT TO REMEMBER >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // we are updating count as 2 because we found 3-3 as "0" and its count is "2" that means that there were 2 prefix subarrays the are bound to match the target                        0  1 2 3 4 5
    // we said that in the array [1,-1,1,1,1,1] we got the sum equal to target (i.e. "3") from index 0 to 4 and if we do sum-k then its equal to 0 that means we need to remove 0 sum subarray from the subarray we got (i.e. 0 to 4th index) to get that to get us to the target value

    // first "0th" count is taken as if we do not remove any of the value                                        0  1 2 3 4
    // and the second "0th" count is taken as if we remove the "0th index and the first index from the subarray [1,-1,1,1,1]"
}

int main()
{

    vector<int> v = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    // Better(v, 3);
    Optimal(v, 3);

    return 0;
}