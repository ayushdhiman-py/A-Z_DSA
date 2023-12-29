#include <bits/stdc++.h>
using namespace std;

void BRUTEforUnequal(vector<int> a)
{
    vector<int> pos, neg;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > 0)
        {
            pos.push_back(a[i]);
        }
        else
        {
            neg.push_back(a[i]);
        }
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            a[i * 2] = pos[i];
            a[i * 2 + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            a[i] = pos[i];
            i++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            a[i * 2] = pos[i];
            a[i * 2 + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            a[i] = neg[i];
            i++;
        }
    }
    for (auto &ele : a)
    {
        cout << ele << " ";
    }
}
// works for both if there are equal number of +ves and -ves or not
void BRUTEforEqual(vector<int> a)
{
    vector<int> pos, neg, res(a.size());

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            neg.push_back(a[i]);
        }
        else
        {
            pos.push_back(a[i]);
        }
    }
    for (int i = 0; i < a.size() / 2; i++)
    {
        res[i * 2] = pos[i];
        res[i * 2 + 1] = neg[i];
    }
    for (auto &ele : res)
    {
        cout << ele << " ";
    }
}

// works only if there are equal number of +ves and -ves
void OPTIMAL(vector<int> a)
{
    vector<int> res(a.size());
    int pos = 0, neg = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > 0)
        {
            res[pos] = a[i];
            pos += 2;
        }
        else
        {
            res[neg] = a[i];
            neg += 2;
        }
    }

    for (auto &ele : res)
    {
        cout << ele << " ";
    }
}

int main()
{

    vector<int> v{-1, -2, 3, 4, 5, 6};
    BRUTEforUnequal(v);

    return 0;
}
