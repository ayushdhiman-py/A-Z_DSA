#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void Optimal1(vector<int> n, vector<int> m)
{
    // TC : O(min(n,m)) + O(nlogn) + O(mlogm)
    // SC : O(1) apart from given array
    int i = n.size() - 1, j = 0;
    while (n[i] >= m[j])
    {
        swap(n[i--], m[j++]);
    }
    sort(n.begin(), n.end());
    sort(m.begin(), m.end());
    for (auto &a : n)
    {
        cout << a << " ";
    }

    for (auto &a : m)
    {
        cout << a << " ";
    }
}

int main()
{

    fast;

    // BRUTE IS TO USE 2 PTR AND USE A NEW ARRAY

    vector<int> a1 = {1, 3, 5, 7};
    vector<int> a2 = {0, 2, 6, 8, 9};
    Optimal1(a1, a2);
    // Used shell sort in the optimal 2
    Optimal2(a1, a2);

    return 0;
}