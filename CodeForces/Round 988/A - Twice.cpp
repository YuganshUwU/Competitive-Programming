// Link : https://codeforces.com/contest/2037/problem/A

/* 
    Question Summary :
      Given an array of size n. Our player has an initial score of 0.
      Increment the score by 1, if there exists two indices such that i != j and arr[i] == arr[j]
*/
  
/*
  Intuition :
    Store the elements of array in a hashmap and maintain each element's count.
    If the frequency of the current element is greater than 1, then increment the result by 1 and reduce the mp[curr] by 2
*/

// Time Complexity : O(N)
// Space Complexity : O(N)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            mp[nums[i]]++;
        }
        
        int result = 0;

        for(int& curr : nums) {
            if(mp[curr] > 1) {
                result++;
                mp[curr] -= 2;
            }
        }        
        

        cout << result << endl;
    }
    
    return 0;
}
