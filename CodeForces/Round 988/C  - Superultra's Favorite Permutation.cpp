// Link : https://codeforces.com/contest/2037/problem/C

/*
  Question Summary :
    You have been given with an array of size n such that it only contains a permutation of elements from 1 to n.
    sort the array such that the sum of ith and (i + 1)th term is a composite number.
    if you can sort it in such a fashion, return the array, else -1
*/

/*
  Intuition :
    Store the elements in the array such that all the odd elements are together and all the even elements are together like :(1, 3, 5 ,7, 2, 4, 6, 8) because :
      odd + odd = even(will always be composite as it will be divisible by 2)
      even + even = even(will be divisible by 2)

    to avoid the centre case where you have to merge the odd and even elements, it will give quite a trouble as:
      odd + even = odd(can be prime for ex : 3 + 4)
    to avoid this, fix the ending odd and starting even as 5 and 4 respectively

    but why 5 and 4? you could use 7 and 3 but for cases 5 and 6, you have to write separate conditions, so it will be easy to use 5 and 4 combination to give 9
    and the number below 5 will always return -1 (check for yourself)
*/

// Time Complexity : O(t * n)
// Space Complexity : O(n + n / 2 + n / 2) -> O(2 * n) -> O(n)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;

        if(n <= 4){
            cout << -1 << endl;
            continue;
        }

        vector<int> odd, even, arr;
        for(int i = 1; i <= n; i++) {
            if(i % 2)
                odd.push_back(i);
            else
                even.push_back(i);
        }

        reverse(odd.begin(), odd.end());
        reverse(even.begin(), even.end());

        for(int& curr : odd){
            if(curr != 5)
                arr.push_back(curr);
        }

        arr.push_back(5);
        arr.push_back(4);

        for(int &curr: even) {
            if(curr != 4)
                arr.push_back(curr);
        }

        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        
        cout << endl;

    }
    
    return 0;
}
