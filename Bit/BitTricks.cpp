#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void swapNums()
{
    int a = 100, b = 200;

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    cout << a << " " << b << '\n';
}

void CheckithBit()
{
    int n = 13, i = 2, flag = 0;

    if (n & (1 << i) != 0)
        cout << "yes\n";

    if ((n >> i) & 1 != 0)
        cout << "yes\n";
}

void printBinary(int num)
{
    int size = sizeof(int) * 8;

    for (int i = size - 1; i >= 0; i--)
    {
        if (num & (1 << i))
            cout << "1";
        else
            cout << "0";
    }
    cout << "\n\n";
}

void setithbit()
{
    int n = 9, i = 1;
    printBinary(n);

    n |= (1 << i);
    // if ((n & (1 << i)) == 0)
    // {
    // }
    printBinary(n);
}

void clearithbit()
{
    int n = 9, i = 0;
    printBinary(n);

    n = n & (~(1 << i));
    // if ((n & (1 << i)) != 0)
    // {
    // }
    printBinary(n);
}

void toggleBit()
{
    int n = 9, i = 0;
    printBinary(n);
    n = n ^ (1 << i);
    printBinary(n);
}

void removeLeftSetBit()
{
    int n = 84;
    printBinary(n);
    n = n & (n - 1);
    printBinary(n);
}

void checkPowerOf2()
{
    // brute - one set bit only

    int n = 3;
    if ((n & (n - 1)) == 0)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
}

void countSetBits()
{
    // option 1 : better one
    int n = 15, count = 0;
    while (n > 0)
    {
        if ((n & 1) == 1)
        {
            count++;
        }
        n = n >> 1;
    }
    cout << count << "\n";

    // option 2
    int m = 16, c = 0;
    while (m != 0)
    {
        m = m & (m - 1);
        c++;
    }
    cout << c << "\n";
}

void evenOrOdd()
{
    int number = 5;
    if ((number & 1) == 1)
    {
        cout << number << " is odd." << endl;
    }
    else
    {
        cout << number << " is even." << endl;
    }
}

int main()
{
    fast;

    countSetBits();

    // dividing by 2
    //  int n = 40;
    //  n = n >> 1;
    //  cout << n;
    return 0;
}