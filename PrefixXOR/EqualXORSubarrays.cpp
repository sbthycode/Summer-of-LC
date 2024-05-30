// Problem Link: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30
// Count Triplets That Can Form Two Arrays of Equal XOR

// Given an array of integers arr.We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
// Let's define a and b as follows:
// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
// Note that ^ denotes the bitwise-xor operation.
// Return the number of triplets (i, j and k) Where a == b.

// Example 1:
// Input: arr = [2,3,1,6,7]
// Output: 4
// Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        vector<int> pre(n+1);
        pre[0] = 0;
        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1] ^ arr[i-1];
        }
        for(int i=0;i<n-1;i++){
            for(int k =i+1;k<n;k++){
                int cur = pre[i] ^ pre[k+1];
                if(cur == 0) count += (k-i);
            }
        }
        return count;
    }
};

int main(int argc,char **argv){
    vector<int> arr = {2,3,1,6,7};
    Solution s;
    cout<<s.countTriplets(arr)<<endl;
    return 0;
}