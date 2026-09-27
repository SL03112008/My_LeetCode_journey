class Solution {
private:
    int f(int ind,int sum,vector<int> &v,vector<vector<int>> &dp){
        if(ind == v.size()) return sum==0;
        if(sum==0) return 1;
        if(sum<0) return 0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int pick = f(ind+1,sum-v[ind],v,dp);
        int notPick = f(ind+1,sum,v,dp);
        return dp[ind][sum] = (pick || notPick);
    }
public:
    bool canPartition(vector<int>& nums) {
        int half = accumulate(nums.begin(),nums.end(),0);
        if(half%2) return 0;
        half/=2;
        vector<vector<int>> dp(nums.size()+2,vector<int>(half+2,-1)); 
        return f(0,half,nums,dp);
    }
};