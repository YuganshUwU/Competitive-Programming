// Link : https://codeforces.com/contest/2037/problem/B

/* 
  Question Summary : 
    The initial idea was to give you a 2d matrix such that :
      the first two elements of the input was the size of the matrix, say m and n, and the other m lines will be the elements of the matrix

    But an error occured and all elements are now in a same line.
    Given the total number of elements entered by the user, Return a possible size, m and n, entered by the user.
    If there are multiple answers, return any one of them
*/

/*
  Intuition :
      since the total number of elements entered by the user is k, we have the total size of k - 2 of the vector as the two elements removed are 
      m and n itself which are the size elements of the 2d array.
      use a hashmap to store the frequency of each of the elements present in the array of size k.
      iterate through the array, say nums, and find for the current element and the (k - 2 / current element)th element
        if both the elements are present, return the current element and the k - 2 / current element as your answer.
*/

// Time Complexity : O(t * k * k) -> worst case, avg case : O(N) -> depends on the find function of the unordered map. Use a map to get a fixed time of O(N logN)
// Space Complexity : O(k)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int k;
        cin >> k;

        vector<int> nums(k);
        unordered_map<int, int> mp;
        for(int i = 0; i < k; i++) {
            cin >> nums[i];
            mp[nums[i]]++;
        }

        int sizeOfGrid = k - 2;
        int m = 0, n = 0;

        for(int i = 0; i < k; i++) {
            int curr = nums[i];
            int toFind = sizeOfGrid / curr;
            float toFindFl = (1.0) *sizeOfGrid / curr;

            if(toFind == toFindFl && mp.find(toFind) != mp.end() && mp.find(curr) != mp.end()) {
                
                mp[curr]--;
                mp[toFind]--;

                if(mp[curr] >= 0 && mp[toFind] >= 0) {
                    m = curr;
                    n = toFind;
                    break;
                }
            }
        }

        cout << m <<" " << n << endl;
    }
    
    return 0;
}
