#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 1, 2, 3, 1, 3, 2, 12};
    vector<int> q = {1, 2, 3, 4, 12};

    map<int, int> mpp;
    for (auto a : arr)
    {
        mpp[a]++;
    }

    pair<int, int> min(INT_MAX, INT_MAX);
    pair<int, int> max(INT_MIN, INT_MIN);

    for (auto &it : mpp)
    {
        if (it.second < min.second)
        {
            min.first = it.first;
            min.second = it.second;
        }
        if (it.second > max.second)
        {
            max.first = it.first;
            max.second = it.second;
        }
        cout << it.first << "->" << it.second << "\n";
    }
    cout << "\n";

    cout << "Min frequency element is => " << min.first << " with frequency " << min.second << "\n";
    cout << "Max frequency element is => " << max.first << " with frequency " << max.second << "\n";

    int i = 0;
    while (i < q.size())
    {
        cout << mpp[q[i]] << " ";
        i++;
    }

    return 0;
}