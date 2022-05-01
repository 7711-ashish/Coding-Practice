// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int n1 = s.length();
        int n2 = p.length();
        int freq1[127] = {0};
        int freq2[127] = {0};
        for(int i=0;i<n2;i++)
        {
            freq1[p[i]]++;
        }
        int cnt=0;
        int st=-1, en=1;
        int size = n1;
        int i=0,j=0;
        while(j<n1)
        {
            if(freq1[s[j]]!=0){
                if(freq2[s[j]]<freq1[s[j]])
                {
                    cnt++;
                }
                freq2[s[j]]++;
            }
            while(cnt==n2)
            {
                if(j-i+1<size)
                {
                    st=i;
                    size = j-i+1;
                }
                if(freq1[s[i]]!=0){
                    freq2[s[i]]--;
                    if(freq2[s[i]]<freq1[s[i]]){
                        cnt--;
                    }
                }
                i++;
            }
            j++;
        }
        if(st==-1)
            return "-1";
        else
            return (s.substr(st,size));
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends