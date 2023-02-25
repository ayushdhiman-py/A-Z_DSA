#include <bits/stdc++.h>
using namespace std;

void reverseInGroups(vector<int> &arr, int n, int k)
{
    for (int i = 0; i < n; i = i + k)
    {
        int low = i;

        int high = min(i + k - 1, n - 1);

        while (low < high)
        {

            swap(arr[low++], arr[high--]);
        }
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    reverseInGroups(v, v.size(), 3);
    cout << " \n\n";
    for (auto &a : v)
    {
        cout << a << " ";
    }

    return 0;
}