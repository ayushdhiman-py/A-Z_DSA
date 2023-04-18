#include <bits/stdc++.h>
using namespace std;

void better(vector<int> v, int target)
{
    // TC: O(n^3)*log(n)

    // SC: O(n) (internally used which stores all the array elements)
    //     + O(quads)*2 (for the unique and returning the answer)

    // total sc: O(n) + O(quads)*2

    set<vector<int>> st;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            unordered_set<int> check;
            // we don't put the entire array in this check set because the numbers needs to be distinct
            // so we only go on the elemtnts between the iterators i,j,k
            // eg :
            //
            //    -1 is only in set as of now
            //    1, 0, -1, -2, 2, 0
            //    ^  ^       ^
            //    |  |       |
            //    i  j       k
            //

            for (int k = j + 1; k < n; k++)
            {
                int toFind = target - (v[i] + v[j] + v[k]);
                if (check.find(toFind) != check.end())
                {
                    vector<int> temp = {v[i], v[j], v[k], toFind};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                check.insert(v[k]);
            }
        }
    }
    for (auto &it : st)
    {
        for (auto &i : it)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    // vector<vector<int>> v(st.begin(),st.end());
}

void optimal(vector<int> v, int target)
{
    int n = v.size();
    vector<vector<int>> res;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != (i + 1) && v[j] == v[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = v[i] + v[j] + v[k] + v[l];
                if (sum == target)
                {
                    vector<int> temp = {v[i], v[j], v[k], v[l]};
                    res.push_back(temp);
                    cout << v[i] << v[j] << v[k] << v[l] << "\n";
                    k++;
                    l--;
                    while (v[k] == v[k + 1])
                        k++;
                    while (v[l] == v[l + 1])
                        l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
}

int main()
{

    vector<int> v = {1, 0, -1, -2, 2, 0};
    int target = 0;
    better(v, target);
    // Problem with the better approach is that extra hashset for lookup
    // ans to store unique set DS is used AND TO ELEMINATE THIS WE GO FOR OPTIMAL

    optimal(v, target);
    // instead of using set DS to make sure to have unique qads
    // sort the array provided
    return 0;
}