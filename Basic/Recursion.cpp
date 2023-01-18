#include<bits/stdc++.h>
using namespace std;

void printNnumbers(int i){
    if(i<1){
        return;
    }
    cout<<"Ayush Dhiman "<<i<<"\n";
    printNnumbers(i-1);
}

void printLinear(int i,int n){

    // Below is 1-N :-
    if(i>n){
        return;
    }
    cout<<i++<<endl;
    printLinear(i,n);

    // Below is N-1 :-
    // THIS IS BACKTRACKING
    if(i>n){
        return;
    }
    printLinear(i+1,n);
    cout<<i<<endl;

    // Below is 1-N :-
    //THIS IS BACKTRACKING
    if(i<1){
        return;
    }
    printLinear(i-1,n);
    cout<<i<<endl;
}

int sumN(int n){
    // *** HOW I DID BEFORE I SAW THE TUTORIAL *** //
    // (int initial,int n)
    // if(n<1){
    //     cout<<initial<<"\n";
    //     return;
    // }
    // initial+=n;
    // sumN(initial,n-1);

    // *** FUNCTIONAL WAY *** //
    if(n==0){
        return 0;
    }
    return n+sumN(n-1);

}

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}

int fibonacci(int n){
    if(n==1 || n==0){
        return n;
    }
    return (fibonacci(n-1)+fibonacci(n-2));
}

void reverse(int start, int end, vector<int> &v){
    if(start>=end) return;
    swap(v[start],v[end]);
    reverse(start+1,end-1,v);
}

int main(){

	printNnumbers(10);
    return 0;
}
