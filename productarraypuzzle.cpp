#include<iostream>
#include<bits/stdc++.h>

int main()
{
    long long int n;
    cin>>n;
    vector<long long int> p(n);
    for(long long int i=0;i<n;i++)
        cin>>p[i];
    p = productExceptSelf(p,n);
    for(int i=0;i<n;i++) {
        cout<<p[i];
    }
    return 0;
}

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {  
       vector<long long int> pdt(n,1);
       if(n==1)
        return pdt;
       long long int suf[n];
       suf[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--)
           suf[i]=nums[i]*suf[i+1];
       pdt[0]=suf[1];
       long long int lPdt=nums[0];
       for(int i=1;i<n-1;i++)
       {
           pdt[i]=lPdt*suf[i+1];
           lPdt*=nums[i];
       }
       pdt[n-1]=lPdt;
       return pdt;      
}