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
        int n=nums.size();
        vector<int> dp(nums.size()+2,-1);
        dp[n]=0;dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int rob = nums[i]+dp[i+2];
            int skip = dp[i+1];
            dp[i]=max(rob,skip);
        }
        return dp[0];
    }
};