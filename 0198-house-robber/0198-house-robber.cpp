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
        if(n==1){
            return nums[0];
        }
        vector<int> dp(3,0);
        dp[0]=0;dp[1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int rob = nums[i]+dp[0];
            int skip = dp[1];
            dp[2]=max(rob,skip);
            dp[0]=dp[1];
            dp[1]=dp[2];
        }

        return dp[2];
    }
};