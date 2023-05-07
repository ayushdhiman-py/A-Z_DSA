#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void mathsApproach(vector<int> a, int size)
{
    // TC : O(n)
    // SC : O(1)
    long long n = a.size();
    // S-Sn
    // S2-S2n

    // first n natural numbers
    long long sn = (n * (n + 1) / 2);
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;

    // given array sum of elements + squares
    long long s = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        s2 += (long long)a[i] * (long long)a[i];
    }

    // for first equation => ( x-y )
    long long val1 = s - sn;
    // for second equation
    // => (x^2-y^2)
    //    (x+y) (x-y)
    //
    //    x+y = val2 /
    //             x-y -> val1
    long long val2 = s2 - s2n;
    // below is x+y above is x-y
    val2 = val2 / val1; // this gives x+1 which is val2

    // so what will be x lets see
    // if x-y = val1
    // & if x+y = val2
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    cout << (int)x << " is repetition & missing is " << (int)y;
}

void better(vector<int> a, int size)
{
    // TC: O(2n)
    // SC: O(n)
    // Extra space is a barrier to impress
    vector<int> hasharr(size + 1);
    int rep = -1, miss = -1;
    for (int i = 0; i < size; i++)
    {
        hasharr[a[i]]++;
    }
    for (int i = 1; i < size + 1; i++)
    {
        if (hasharr[i] > 1)
        {
            rep = i;
        }
        else if (hasharr[i] < 1)
        {
            miss = i;
        }
    }
    cout << rep << "\n";
    cout << miss;
}

int main()
{

    fast;

    vector<int> v = {4, 3, 6, 2, 1, 1};
    int size = v.size();
    // better(v, size);
    mathsApproach(v, size);

    return 0;
}