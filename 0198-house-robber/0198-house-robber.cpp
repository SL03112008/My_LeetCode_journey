class Solution {
public:
    //space optimization:-
    int rob(vector<int>& nums) {
        vector<int> dp(3,0);
        dp[1]=nums[0];dp[2]=nums[0];
        for(int i=1;i<nums.size();i++){
            int rob = nums[i];
            if(i!=1) rob+=dp[0];
            int skip = dp[1];
            dp[2] = max(rob,skip);
            dp[0]=dp[1];
            dp[1]=dp[2];
        }
        return dp[2];
    }
};