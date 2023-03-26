#include <bits/stdc++.h>
using namespace std;

void algo(vector<int> &v)
{
    int ele;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = v[i];
        }
        else if (ele == v[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    // this is to check is the element exists or not
    int count = 0;
    for (int &el : v)
    {
        if (el == ele)
        {
            count += 1;
        }
    }
    if (count > ((v.size() - 1) / 2))
    {
        cout << ele;
    }
}

int main()
{

    vector<int> v = {5, 5, 9, 9, 9, 9 ,5, 2, 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 2, 5, 5, 5, 5};
    algo(v);

    return 0;
}