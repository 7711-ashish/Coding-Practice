// Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.

// Examples: 

// Input:  A = "ABD", B = "BAD"
// Output: 1
// Explanation: Pick B and insert it at front.

// Input:  A = "EACBD", B = "EABCD"
// Output: 3
// Explanation: Pick B and insert at front, EACBD => BEACD
//              Pick A and insert at front, BEACD => ABECD
//              Pick E and insert at front, ABECD => EABCD

#include<iostream>
#include<algorithm>
#include<string> 
#include<vector>

using namespace std;

int transform(string A, string B)
{
    int n= A.length();
    int count[n];
    for(int i=0;i<n;i++)
    {
        count[B[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        count[A[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        if(count[i]==0)
           return -1;
    }
    int res=0;
    for(int i=n-1, j=n-1;i>=0; )
    {
        while(A[i]!=B[j]&&i>=0)
        {
            i--;res++;

        }
        if(i>0)
        {
            i--;
            j--;
        }
    }
    return res;
}

int main()
{
    string A,B;
    cin>>A>>b;
    int res = transform(A,B)
    cout<<res<<endl;
}