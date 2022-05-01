// Recursively print all sentences that can be formed from list of word lists
// Difficulty Level : Medium
// Last Updated : 26 Sep, 2020
// Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion? 
// Example: 

// Input: {{"you", "we"},
//         {"have", "are"},
//         {"sleep", "eat", "drink"}}

// Output:
//   you have sleep
//   you have eat
//   you have drink
//   you are sleep
//   you are eat
//   you are drink
//   we have sleep
//   we have eat
//   we have drink
//   we are sleep
//   we are eat
//   we are drink 

#include<iostream>
#include<algorithm>
#include<string>

using namespce std;

int R=3;
int C=3;

void printUtil(stirng arr[R][C], int m, int n, string output[R][C])
{
    output[m] = arr[m][n];

    if(m==R-1){
        for(int i=0; i<R;i++)
            cout<<output[i]<<" ";
        cout<<endl;
        return;
    }

    for(int i=0; i<C;i++)
        if(arr[m+1][i]!="")
            printUtil(arr, m+1, i, output);
}
void print(string arr[R][C])
{
    string output[R];
    for(int i=0;i<C;i++)
    {
        if(arr[0][i]!="")
            printUtil(arr, 0, i, output);
    } 
}
int main()
{
    string arr[R][C] ={{"you","we"},{"have","are"},{"sleep","eat","drink"}};
    print(arr);
    return 0;
}