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
        vector<int> after(half+2,0); 
        vector<int> cur(half+2,0); 
        // return f(0,half,nums,dp);
        int n = nums.size();
        for(int i=0;i<n;i++) after[0]=1;
        for(int ind=n-1;ind>=0;ind--){
            for(int sum = 1;sum<=half;sum++){
                cur[sum] = after[sum];
                if(cur[sum]==0 && sum>=nums[ind]) cur[sum] = after[sum-nums[ind]]; 
            }
            after = cur;
        }
        return cur[half];
    }
};