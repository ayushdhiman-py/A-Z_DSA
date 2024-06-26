#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

// number of subsets will be (2^n) or can say (1<<n) its same thing
// Here’s the detailed breakdown:
// i = 0 (000 in binary): No bits are set, so the subset is {} (the empty set).
// i = 1 (001 in binary): The last bit is set, so the subset is {3}.
// i = 2 (010 in binary): The second bit is set, so the subset is {2}.
// i = 3 (011 in binary): The last two bits are set, so the subset is {2, 3}.
// i = 4 (100 in binary): The first bit is set, so the subset is {1}.
// i = 5 (101 in binary): The first and last bits are set, so the subset is {1, 3}.
// i = 6 (110 in binary): The first two bits are set, so the subset is {1, 2}.
// i = 7 (111 in binary): All bits are set, so the subset is {1, 2, 3}.

// The for loop with the variable i iterates over these binary numbers. For each i, the nested for loop with the variable j checks each bit of i (from 0 to n-1). If the bit at position j is set (i & (1 << j) is true), it means that the element at index j of the vector v is included in the current subset.

// The res vector stores all the subsets, and after the loops finish, we print out each subset.

// Here’s the output for the input vector v = [1, 2, 3]:

void generate(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> res;

    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> subset;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                subset.push_back(v[j]);
            }
        }
        res.push_back(subset);
    }


    // Printing the subsets
    for (auto &subset : res)
    {
        for (int num : subset)
        {
            cout << num << ' ';
        }
        cout << endl;
    }
}

int main()
{

    fast;
    vector<int> v = {1, 2, 3};
    generate(v);
    return 0;
}