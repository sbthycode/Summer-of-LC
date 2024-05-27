Problem link: https://leetcode.com/problems/student-attendance-record-ii/description/?envType=daily-question&envId=2024-05-26

An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 10^9 + 7.


```
// Approach: 3D DP in the number of days, count of absent so far and count of current consecutive leaves.
class Solution {
public:
    int mod = pow(10,9) + 7;
    int checker(int ind, int i, int n, int acount, int lcons,vector<vector<vector<int>>>& dp){
        if(ind == n){
            if(i==0){
                if(acount<1) return 1;
            }
            else if (i==1) return 1;
            else{
                if(lcons<2) return 1;
            }
            return 0;
        }
        if(i==0){
            lcons = 0;
            if(acount==0){
                acount+=1;
                if(dp[ind-1][acount][lcons]!=-1) return dp[ind-1][acount][lcons];
                return dp[ind-1][acount][lcons] = ((checker(ind+1,0,n,acount,lcons,dp)%mod + checker(ind+1,1,n,acount,lcons,dp)%mod)%mod + checker(ind+1,2,n,acount,lcons,dp))%mod;
            }
        }
        else if (i==1){
            lcons = 0;
            if(dp[ind-1][acount][lcons]!=-1) return dp[ind-1][acount][lcons];
            return dp[ind-1][acount][lcons] = ((checker(ind+1,0,n,acount,lcons,dp)%mod + checker(ind+1,1,n,acount,lcons,dp)%mod)%mod + checker(ind+1,2,n,acount,lcons,dp))%mod;
        }
        else{
            if(lcons<=1){
                lcons++;
                if(dp[ind-1][acount][lcons]!=-1) return dp[ind-1][acount][lcons];
                return dp[ind-1][acount][lcons] = ((checker(ind+1,0,n,acount,lcons,dp)%mod + checker(ind+1,1,n,acount,lcons,dp)%mod)%mod + checker(ind+1,2,n,acount,lcons,dp))%mod;
            }
        }
        return  0; 
    }
    int checkRecord(int n) {
        // For i:
        // 0 -> A
        // 1 -> P
        // 2 -> L
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return ((checker(1,0,n,0,0,dp)%mod + checker(1,1,n,0,0,dp)%mod)%mod + checker(1,2,n,0,0,dp))%mod;
        
    }
};

```

