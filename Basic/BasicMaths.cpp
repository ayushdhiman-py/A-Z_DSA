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

int pailindrome(int n, int m)
{
    return (n == m);
}

void printDivisors(int n)
{
    // loop is running for O(sqrt(n))
    for (int i = 1; i < sqrt(n); i++) // instead of sqrt write i*i<=n
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if ((n / i) != i)
            {
                cout << (n / i) << " ";
            }
        }
    }
    // And if we store the divisors in a vector and sort it, it will take extra O(n*log(n)) where n is number of
    // factors and then printing will be taking extra O(n)

    // Hence, the overall TC will be the following:
    // O(sqrt(n)) + O(n*log(n)) + O(n)
}

void prime(int n)
{
    int count = 0;
    for(int i=1; i<sqrt(n); i++){
        if(n%i==0){
            count++;
            if((n/i)!=i){
                count++;
            }
        }
    }
    if(count==2) cout<<"true";
    else cout<<"false";
}


//GCD OR HDF

int gdc(int a, int b)
{
    // RECURSION WAY
    // if(a==0) {
    //     return b;
    // }
    // b=a%b;
    // return 0 ; 


    //------------
    // ITERATIVE WAY
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) return b;
    return a;
}

int main()
{
    int n = 40, m = 20;
    int res = gcd(n,m);
    cout<<__gcd(n,m);
    cout<<res;
    return 0;
}
