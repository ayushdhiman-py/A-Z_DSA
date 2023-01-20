#include <bits/stdc++.h>
using namespace std;

void PrintSubsequences(int i, vector<char> &v, string s)
{
    if (i == s.size())
    {
        for (auto a : v)
        {
            cout << a << " ";
        }
        if (v.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    v.push_back(s[i]);
    PrintSubsequences(i + 1, v, s);
    v.pop_back();
    PrintSubsequences(i + 1, v, s);
}

void Print_K_Sum_Subsequences(int i, vector<int> &givenList, int initSum, int sum, vector<int> resArr)
{
    if (i == givenList.size())
    {
        if (initSum == sum)
        {

            for (auto a : resArr)
            {
                cout << a << " ";
            }
            cout << endl;
        }
        return;
    }
    resArr.emplace_back(givenList[i]);
    initSum += givenList[i];
    Print_K_Sum_Subsequences(i + 1, givenList, initSum, sum, resArr);
    initSum -= givenList[i];
    resArr.pop_back();
    Print_K_Sum_Subsequences(i + 1, givenList, initSum, sum, resArr);
}

// ******* MODIFIED PRINT ONLY Count of SUBSEQUENCE WHICH IS EQUAL TO SUM ******** //
int Print_K_Sum_Subsequences_count(int i, int initSum, int sum, vector<int> givenList)
{
    if (i == givenList.size())
    {
        if (initSum == sum)
            return 1;
        else
            return 0;
    }

    initSum += givenList[i];
    int l = Print_K_Sum_Subsequences_count(i + 1, initSum, sum, givenList);
    initSum -= givenList[i];
    int r = Print_K_Sum_Subsequences_count(i + 1, initSum, sum, givenList);
    return l + r;
}

// ******* MODIFIED PRINT ONLY 1 SUBSEQUENCE WHICH IS EQUAL TO SUM ******** //
bool Print_K_Sum_Subsequences_one(int i, vector<int> &givenList, int initSum, int sum, vector<int> resArr)
{
    if (i == givenList.size())
    {
        if (initSum == sum)
        {
            for (auto a : resArr)
            {
                cout << a << " ";
            }
            cout << endl;
            return true;
        }
        else
            return false;
    }
    resArr.emplace_back(givenList[i]);
    initSum += givenList[i];
    if (Print_K_Sum_Subsequences_one(i + 1, givenList, initSum, sum, resArr) == true)
        return true;
    initSum -= givenList[i];
    resArr.pop_back();
    if (Print_K_Sum_Subsequences_one(i + 1, givenList, initSum, sum, resArr) == true)
        return true;

    return false;
}

// Print => parameter
// Print 1 answer => return T/F and avoid further recursion calls if using booleans
// Count => retrun 1 return 0 and add all the function calls using left and right or using for loop and return sum of calls

// NEGATIVE SUBS //
void negativeProdSubsequences(int index, int prod, vector<int> &v, vector<int> &res)
{
    if (index == v.size())
    {
        if (prod < 0)
        {
            for (auto a : res)
            {
                cout << a << " ";
            }
            cout << "\n";
        }
        return;
    }
    res.push_back(v[index]);
    prod *= v[index];
    negativeProdSubsequences(index + 1, prod, v, res);
    prod /= v[index];
    res.pop_back();
    negativeProdSubsequences(index + 1, prod, v, res);
}
int main()
{

    // vector<char> res;
    // PrintSubsequences(0, res, "aysuh");

    int s = 2;
    vector<int> givenList = {1, 2, 1};
    vector<int> resArr;
    cout << Print_K_Sum_Subsequences_count(0, 0, s, givenList);

    // negative subs//
    //  vector<int> v = {1, -5, -6};
    //  vector<int> res;
    //  negativeProdSubsequences(0, 1, v, res);

    return 0;
}