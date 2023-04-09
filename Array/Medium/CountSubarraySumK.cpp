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
    // TC:- 
    // O(n * logN) - simple map
    // O(n * 1 for best or n for worst)
    
    // SC: O(n) 
    
    unordered_map<int, int> mpp;
    int count = 0, ps = 0;
    mpp[0] = 1;

    for (int i = 0; i < v.size(); i++)
    {
        ps += v[i];
        int remove = ps - target;
        count += mpp[remove];
        mpp[ps] += 1;
        // if (mpp.find(ps - k))
    }
    cout << count << "\n";
}

int main()
{

    vector<int> v = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    Better(v, 3);
    Optimal(v, 3);

    return 0;
}