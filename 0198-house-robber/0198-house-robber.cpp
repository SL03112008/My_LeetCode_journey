class Solution {
private:
    int f(vector<int> nums,int i,vector<int> &dp){
        if(i==nums.size()) return 0;
        if(i==nums.size()-1) return nums[i]; 
        if(dp[i]!=-1) return dp[i];
        int rob = nums[i] + f(nums,i+2,dp);
        int skip = f(nums,i+1,dp);
        return dp[i]=max(rob,skip);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2,-1);
        return f(nums,0,dp);
    }
};