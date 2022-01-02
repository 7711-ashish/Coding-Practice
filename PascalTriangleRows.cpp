//https://www.interviewbit.com/problems/pascal-triangle-rows/
/*

Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
vector<vector<int>> generate(int numRows) {
    vector<vector<int>>res;
    if(numRows==0)
    {
        return res;
    }
    vector<int>temp;
    temp.push_back(1);
    res.push_back(temp);
    for(int i=1;i<numRows;i++)
    {
        temp.clear();
        temp.push_back(1);
        for(int j=1;j<i;j++)
        {
            temp.push_back(res[i-1][j-1]+res[i-1][j]);
        }
        temp.push_back(1);
        res.push_back(temp);
    }
    return res;
}
int main()
{
    int numRows=5;
    vector<vector<int>>res=generate(numRows);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


