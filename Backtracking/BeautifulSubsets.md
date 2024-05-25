Problem Link: https://leetcode.com/problems/the-number-of-beautiful-subsets/?envType=daily-question&envId=2024-05-23

You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].


```
Approach 1:
using namespace std;
class Solution {
public:
    int getans(int i, int k, vector<int>& nums, unordered_map<int,int>& mp){
        if (i==nums.size()){
            return 1;
        }
        int ans = getans(i+1,k,nums,mp);
        if(mp[nums[i]-k]==0 && mp[nums[i]+k]==0 ){
            mp[nums[i]]++;
            ans += getans(i+1,k,nums,mp);
            mp[nums[i]]--;
        }
        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        return getans(0,k,nums,mp)-1;
    } 
};
```