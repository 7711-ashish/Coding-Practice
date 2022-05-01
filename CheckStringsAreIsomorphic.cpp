// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
// Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

// Example 1:

// Input:
// str1 = aab
// str2 = xxy
// Output: 1
// Explanation: There are two different
// charactersin aab and xxy, i.e a and b
// with frequency 2and 1 respectively.

#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool check(string str1, string str2)
{
     int n = str1.length(),m = str2.length();
        if(n!=m)return false;
        
        int hash1[26],hash2[26];
        for(int i = 0; i<26; i++){
            hash1[i] = -1;
            hash2[i] = -1;
        }
        
        // checking str1 to str2 mapping
        for(int i = 0; i<n; i++){
            if(hash1[str1[i]-'a'] != -1 && hash1[str1[i]-'a'] != str2[i]-'a'){
                return false;
            }
            else{
                hash1[str1[i]-'a'] = str2[i]-'a';
            }
        }
        
        // checking str2 to str1 mapping
        for(int i = 0; i<m; i++){
            if(hash2[str2[i]-'a'] != -1 && hash2[str2[i]-'a'] != str1[i]-'a'){
                return false;
            }
            else{
                hash2[str2[i]-'a'] = str1[i]-'a';
            }
        }
        
        return true;
        
}

int main()
{
    string str1, str2;
    cin>>str1>>str2;
    check(str1,str2);
}