// Problem Link: https://leetcode.com/problems/find-the-number-of-good-pairs-ii/description/
// Find the Number of Good Pairs II

// You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.
// A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).
// Return the total number of good pairs.

// Example 1:
// Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1
// Output: 5
// Explanation:
// The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int> mp;
        for(auto it: nums2) mp[it*k]++;
        long long ans = 0;
        for(auto it: nums1){
            int sq = sqrt(it);
            for(int i=1;i<=sq;i++){
                if(it%i!=0) continue;
                ans += mp[i];
                if(i!=it/i) ans += mp[it/i];
            }
        }
        return ans;
    }
};

int main(int argc,char **argv){
    vector<int> nums1 = {1,3,4};
    vector<int> nums2 = {1,3,4};
    int k = 1;
    Solution s;
    cout<<s.numberOfPairs(nums1,nums2,k)<<endl;
    return 0;
}