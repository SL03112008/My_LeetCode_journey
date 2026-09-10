class Solution {
public:
    //tabulation:-
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2,-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int rob = nums[i];
            if(i!=1) rob+=dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(rob,skip); 
        }
        return dp[nums.size()-1];
    }
};