// Choose and Swap 
// Easy Accuracy: 46.69% Submissions: 24956 Points: 2
// You are given a string s of lower case english alphabets.
// You can choose any two characters in the string and replace
// all the occurences of the first character with the second 
// character and replace all the occurences of the second character 
// with the first character. Your aim is to find the lexicographically 
// smallest string that can be obtained by doing this operation at most once.

// Example 1:

// Input:
// A = "ccad"
// Output: "aacd"
// Explanation:
// In ccad, we choose a and c and after 
// doing the replacement operation once we get, 
// aacd and this is the lexicographically
// smallest string possible.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        int arr[26];
        int md = INT_MAX - 1;
        for(int i  = 0 ; i <26 ; i++){
            arr[i] = md;
        }
        
        //saving first oocurace of character in string 
        for(int i =  0 ; i < a.length() ; i ++){
            if(arr[a[i] - 'a'] == md){
                arr[a[i] - 'a'] = i;
            }
            
        }
        
        
        //The in order to find the lexicographically smaller string,
        //the leftmost character must be replaced with some character
        //which is smaller than it. This will only happen if the smaller
        //character appears after it in the array.
        int swap1 = -1;
        int swap2 = -1;
        for(int  i = 0; i < 26 ; i ++){
            if(arr[i] == md) continue;
            for(int j = i + 1; j < 26 ; j ++){
                if(arr[j] < arr[i]){
                    if(swap1 == -1){
                        swap1 = arr[i]; swap2 = arr[j];
                    }
                    else{
                          if(swap2 > arr[j]){
                              swap2  = arr[j];
                          }  
                    }
                }
            }
            if(swap1 != -1){
                break;
            }
        }
        if(swap1 == INT_MAX){
            return a;
        }
        char c1 = a[swap1];
        char c2 = a[swap2];
        for(int i = 0 ; i < a.length() ; i ++){
            if(a[i] == c1){
                a[i] = c2;
            }
            else if(a[i] == c2){
                a[i] = c1;
            }
        }
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends