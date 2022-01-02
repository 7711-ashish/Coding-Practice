// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// You need to do this in place.

// Note that if you end up using an additional array, you will only receive partial score.

// Example:

// If the array is

// [
//     [1, 2],
//     [3, 4]
// ]
// Then the rotated array becomes:

// [
//     [3, 1],
//     [4, 2]
// ]
#include <iostream>
#include <vector>
using namespace std;
void rotatedMtrix(vector<vector<int>>&A)
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=i;j<A.size();i++)
         {
             int temp=A[i][j];
             A[i][j]=A[j][i];
             A[j][i]=temp;
         }
    }
    int i=0;j=A.size()-1;
    int t;
    while(i<j)
    {
        t=0;
        while(t<A.size())
        {
            int temp=A[t][i];
            A[t][i]=A[t][j];
            A[t][j]=temp;
            t++;
        }
        i++;
        j--;
    }
}
int main()
{
    vector<vector<int>>A={{1,2},{3,4}};
    rotatedMtrix(A);
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}