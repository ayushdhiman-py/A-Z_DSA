#include <bits/stdc++.h>
using namespace std;
int count(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        // for extraction of digit
        // int lastdigit = n%10;
        cnt++;
        n = n / 10;
    }
    return cnt;
    // another method would be
    // return log10(n)+1;
}

int reverse(int n)
{
    int reversedNum = 0;
    while (n > 0)
    {
        int ld = n % 10;
        reversedNum = (reversedNum * 10) + ld;
        n /= 10;
    }
    return reversedNum;
}

int pailindrome(int n,int m){
    return (n==m);
}



int main()
{
    int n = 121;
    int reversed = reverse(n);
    bool isPailindrome = pailindrome(n,reversed);
    cout << (isPailindrome?"True\n":"False\n") << endl;

    return 0;
}
