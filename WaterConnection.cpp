/*

There are n houses and p water pipes in Geek Colony. Every house has at most one pipe going into it and at most one pipe going out of it. Geek needs to install pairs of tanks and taps in the colony according to the following guidelines.  
1. Every house with one outgoing pipe but no incoming pipe gets a tank on its roof.
2. Every house with only one incoming and no outgoing pipe gets a tap.
The Geek council has proposed a network of pipes where connections are denoted by three input values: ai, bi, di denoting the pipe of diameter di from house ai to house bi.
Find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes wherever possible.
Note: The generated output will have the following format. The first line will contain t, denoting the total number of pairs of tanks and taps installed. The next t lines contain three integers each: house number of tank, house number of tap, and the minimum diameter of pipe between them.


Example 1:

Input:
n = 9, p = 6
a[] = {7,5,4,2,9,3}
b[] = {4,9,6,8,7,1}
d[] = {98,72,10,22,17,66} 
Output: 
3
2 8 22
3 1 66
5 6 10
Explanation:
Connected components are 
3->1, 5->9->7->4->6 and 2->8.
Therefore, our answer is 3 
followed by 2 8 22, 3 1 66, 5 6 10.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes an integer n(the number of houses), p(the number of pipes),the array a[] , b[] and d[] (where d[i] denoting the diameter of the ith pipe from the house a[i] to house b[i]) as input parameter and returns the array of pairs of tanks and taps installed i.e ith element of the array contains three integers: house number of tank, house number of tap and the minimum diameter of pipe between them.  

 

Expected Time Complexity: O(n+p)
Expected Auxiliary Space: O(n+p)

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int hn1, hn2;
    int outdegree[30]={0};
    int indegree[30]={0};
    int mind = INT_MAX;
    void dfs(int node, vector<pair<int,int> > adj[], vector<int> &vis)
    {
        vis[node] =1;
        if(indegree[node]==1 && outdegree[node]==0)
        {
            hn1= node;
        }
        if(indegree[node]==0&&outdegree[node]==1)
        {
           hn2=node;
        }
        for(auto it: adj[node])
        {
            mind=min(mind,it.second);
            if(vis[it.first]==0)
            { 
               dfs(it.first,adj,vis);
            }
        }
    }


    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        hn1=0;
        hn2=0;
        mind = INT_MAX;
        vector<pair<int,int> > adj[n+1];
        int i=0;
        for(i=0;i<30;i++)
        {
            indegree[i]=0;
            outdegree[i]=0;
        }
        for(i=0;i<n;i++)
        {
            adj[a[i]].push_back(make_pair(b[i],d[i]));
            indegree[b[i]]++;
            outdegree[a[i]]++;
        }
        vector<int> vis(n+1,0);
        vector<vector<int>>v1;
        vector<int> v;
        for(i=0;i<n;i++)
        {
            if(outdegree[i]==1 && indegree[i]==0)
            {
                dfs(i,adj,vis);
                v.push_back(hn2);
                v.push_back(hn1);
                v.push_back(mind);
                mind = INT_MAX;
                hn1 = 0;
                hn2=0;
                v1.push_back(v);
                v.clear();
            }
        }
        return v1;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends