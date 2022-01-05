#include<bits/stdc++.h>
using namespace std;

bool isSubSetSumRecurse(int arr[], int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
 
    // If last element is greater than sum, then ignore it
    if (arr[n-1] > sum)
        return isSubSetSum(arr, n-1, sum);
 
    /* else, check if sum can be obtained by any of the following
    (a) including the last element
    (b) excluding the last element */
    return isSubSetSum(arr, n-1, sum) || isSubSetSum(arr, n-1, sum-arr[n-1]);
}

bool isSubSetSumDP(int arr[], int n, int sum) {
	bool t[n + 1][sum + 1]; // DP - matrix
	// initialization
  // here we are setting 1st row and 1st column 
  // i denotes the size of the array 
  // j denotes the target sum (subset sum)
	for (int i = 0; i <= n; i++) { // itereate as long it is less then length of the array
		for (int j = 0; j <= sum; j++) { 
			if (i == 0)// when array(i) is empty than there is no meaning of sum of elements so return false
				t[i][j] = false;
			if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return it as true;
				t[i][j] = true;
		}
	}
// start from 1 since 1st row and column is already considerd 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) 
        // after taking and element substract from the (sum) i.e -> in {3,8} 3 is taken then we want 11-3=8in the array 
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; // either take or(||) do not take 
			else // if sum is less than array size just leave and increment 
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum]; // at last return T/F
}
/*
Complexity Analysis: 
Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.
*/

int CountSubsets(int arr[], int n, int sum) {
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization 
  // here we are setting 1st row and 1st column 
  // i denotes the size of the array 
  // j denotes the target sum (subset sum)
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0) // when array(i) is empty than there is no meaning of sum of elements so return count of subset as 0;
				t[i][j] = 0;
			if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return count as 1;
				t[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) // when element in the list is less then target sum 
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j]; // either exclude or inxlude and add both of them to get final count 
			else
				t[i][j] = t[i - 1][j]; // exclude when element in the list is greater then the sum 
		}
	}

	return t[n][sum]; // finally return the last row and last column element 
}


int main() {
    int arr[] = { 3, 1, 5, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 11;
    cout << isSubSetSumRecurse(arr, n, sum) << endl;
    cout << isSubSetSumDP(arr, n, sum) << endl;
    return 0;
}