//  Link : https://codeforces.com/contest/2031/problem/A

/*  Question Summary : 
      The problem provides an array representing the heights of pillars, currently arranged in non-increasing order. 
      The goal is to modify the array so that it becomes non-decreasing by changing the height of any pillar to any positive integer.
      Each change counts as one operation. The task is to calculate the minimum number of operations needed to achieve this for multiple test cases.
*/

/* Intuition : 
    Used a map/unordered_map to store the frequency of the elements present in the array, as the minimum number of operations will be to replace each 
    entries of other elements with some elements, say x for values lesser than the element having the maximum frequency and y for values higher than the 
    elements having the max freq.

    returning total number of elements - maximum frequence present in the map
*/

// Time Complexity : O(t * nlogn)
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
 
        vector<int> height(n);
        for(int i = 0; i < n; i++)
            cin >> height[i];
        
        map<int, int> mp;
        for(int& curr : height) {
            mp[curr]++;
        }
 
        int ans = 0;
        for(auto it : mp) {
            ans = max(ans, it.second);
        }
 
        cout << n - ans << endl;
    }
    
    return 0;
}
