// Problem Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27
// Special Array With X Elements Greater Than or Equal X
// You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
// Notice that x does not have to be an element in nums.
// Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

// Example 3:

// Input: nums = [0,4,3,0,4]
// Output: 3
// Explanation: There are 3 values that are greater than or equal to 3.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i =0;i<=nums.size();i++){
          // We can either use the lower_bound function or implement the lower bound algo ourselves.
            int ans1 = nums.end()-lower_bound(nums.begin(),nums.end(),i);
            // int low = 0;
            // int high = nums.size()-1;
            // while(low <= high){
            //     int mid = low + (high - low) / 2;
            //     if(nums[mid] >=i){
            //         high = mid-1;
            //     }
            //     else{
            //         low = mid+1;
            //     }
            // }
            if(ans1 == i) return i;
            // if((nums.size() - (low))==i) return i;
        }
        return -1;
    }
};
