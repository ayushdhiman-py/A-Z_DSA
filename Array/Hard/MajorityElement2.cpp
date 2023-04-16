#include <bits/stdc++.h>
using namespace std;

void Brute(vector<int> v)
{
    // TC = O(n^2);
    // SC = O(1); // coz only 2 numbers in res

    vector<int> res;

    // O(n)
    for (int i = 0; i < v.size(); i++)
    {
        if (res.empty() || res[0] != v[i])
        {
            int count = 0;
            int mini = v.size() / 3;

            // O(n)
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] == v[i])
                {
                    count++;
                }
            }
            if (count > mini)
            {
                res.push_back(v[i]);
            }
        }
        if (res.size() == 2)
            break;
    }
    for (auto &it : res)
    {
        cout << it << " ";
    }
}

void Better(vector<int> v)
{
    // {
    //     // 2 iterations

    //     // TC = O(n);
    //     // SC = O(n);

    //     unordered_map<int, int> mpp;

    //     // O(n)
    //     for (int i = 0; i < v.size(); i++)
    //     {
    //         mpp[v[i]]++;
    //     }

    //     // O(n)
    //     for (auto &it : mpp)
    //     {
    //         if (it.second > v.size() / 3)
    //         {
    //             cout << it.first << " ";
    //         }
    //     }
    // }

    // ----------------------------------------------

    {
        // 1 iteration
        // TC = O(n);
        // SC = O(n);
        unordered_map<int, int> mpp;

        // O(n)
        for (int i = 0; i < v.size(); i++)
        {
            mpp[v[i]]++;                  // O(1) in case of unordered <----> ELSE in case of ordered map its LOG(N)
            if (mpp[v[i]] > v.size() / 3) // OR// if (mpp[v[i]] == (v.size() / 3) + 1)
            {
                cout << v[i] << " ";
            }
        }
    }
}

void Optimal(vector<int> v)
{
    // TC = O ( 2n )
    // SC = O ( 1 )
    int c1 = 0, c2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        if (c1 == 0 && ele2 != v[i])
        {
            c1 = 1;
            ele1 = v[i];
        }
        else if (c2 == 0 && ele1 != v[i])
        {
            c2 = 1;
            ele2 = v[i];
        }
        else if (v[i] == ele1)
            c1++;
        else if (v[i] == ele2)
            c2++;
        else
        {
            c1--;
            c2--;
        }
    }

    vector<int> ls;
    c1 = 0, c2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (ele1 == v[i])
            c1++;
        if (ele2 == v[i])
            c2++;
    }
    int mini = (int)(v.size() / 3) + 1;
    if (c1 >= mini)
        cout << ele1 << " ";
    if (c2 >= mini)
        cout << ele2 << " ";
}

int main()
{
    vector<int> v = {1, 1, 1, 3, 3, 3, 2, 2};
    Optimal(v);
    return 0;
}