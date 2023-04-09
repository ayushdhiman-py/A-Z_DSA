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
        mpp[sum] += 1;
    }
    cout << count << "\n";

    // the file below this file is real reason behind having a count of every prefix "sum" go back in the list of questions and check the image
    file:///home/ayush/Pictures/Screenshots/Screenshot%20from%202023-04-09%2022-37-15.png
    
}

int main()
{

    vector<int> v = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    // Better(v, 3);
    Optimal(v, 3);

    return 0;
}