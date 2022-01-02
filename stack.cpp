#include<iostream>
#include<bitts/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n][5];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                cin>>arr[i][j];
            }
        }
        map<int,int>mp;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[j][i])
                    mp[i]++;
            }
        }
        int flg=0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                int tmp =0;
                if(i!=j){
                    for(int k=0;k<n;k++)
                    {
                        if(arr[k][i]==1 || arr[k][j]==1)
                            tmp++;
                    
                    }
                    if(tmp==n&&(mp[i]>=n/2)&&(mp[j]>=n/2))
                    {
                        flg =1;
                        break;
                    }
                }
            }
            if(flg)
                break;
        }
        if(flg)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}