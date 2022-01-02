#include<bits/stdc.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int knapsack0_1Recursion(vector<int> &weight, vector<int> &value, int W, int n)
{
    if(n==0 || W==0) return 0;
    if(weight[n-1]>W) return knapsack0_1Recursion(weight, value, W, n-1);
    else return max(value[n-1]+knapsack0_1Recursion(weight, value, W-weight[n-1], n-1), knapsack0_1Recursion(weight, value, W, n-1));
}
int main()
{
    int n;
     cin>>n;
    vector<int> weight(n);
    vector<int> value(n);
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    int W;
    cin>>W;
    cout<<knapsack0_1Recursion(weight, value, W, n);  
    return 0;
}
