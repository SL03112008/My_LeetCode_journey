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
        vector<vector<int>> dp(nums.size()+2,vector<int>(half+2,0)); 
        // return f(0,half,nums,dp);
        int n = nums.size();
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int ind=n-1;ind>=0;ind--){
            for(int sum = 1;sum<=half;sum++){
                dp[ind][sum] = dp[ind+1][sum];
                if(dp[ind][sum]==0 && sum>=nums[ind]) dp[ind][sum] = dp[ind+1][sum-nums[ind]]; 
            }
        }
        return dp[0][half];
    }
};