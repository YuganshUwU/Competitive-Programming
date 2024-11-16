// Link : https://codeforces.com/contest/2031/problem/B

/* Question Summary:
    Given an array of length n containing all permutations from 1 to n. 
    Return YES if we can sort the array in ascending order by performing the following operation :
      -> select an index i (1 <= i <= n) such that |arr[i] - arr[i - 1]| = 1
      -> swap these two elements 
*/

/* Intuition:
    We iterate through the entire array and we swap the two elements if and only if the (i - 1)th element is
    1 more than the ith element, so that it can be sorted in ascending order

    if the array, after a full iteration is sorted, we return Yes else No
*/

// Time Complexity : O(t * n)
// Space Complexity : O(1) ignoring input array

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        
        
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] == -1)
                swap(nums[i], nums[i - 1]);
        }

        cout <<(is_sorted(nums.begin(), nums.end()) ? "YES\n" : "NO\n");

    }
    
    return 0;
}
