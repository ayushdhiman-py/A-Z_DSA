#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> a = {7, 1, 5, 3, 6, 4};

    // NORMAL CODE TO GET THE MAX PROFIT

    // int mini = a[0], profit = 0;
    // for (int i = 1; i < a.size(); i++)
    // {
    //     int cost = a[i] - mini;
    //     profit = max(profit, cost);
    //     mini = min(mini, a[i]);
    // }

    // PRINT OUTS that on which day to buy and which day to sell
    int mini = a[0], profit = 0, start;
    for (int i = 1; i < a.size(); i++)
    {
        int cost = a[i] - mini;

        if (cost > profit)
        {
            start = i;
            profit = cost;
        }
        mini = min(mini, a[i]);
    }
    cout << "Buy at"
         << " " << mini << " and sell at " << a[start] << " the profit will be = ";
    cout << profit << "\n";
    return 0;
}