class Solution {
private:
    int f(int ind ,int can ,vector<int> &v,vector<vector<int>> &dp){
        if(ind >= v.size()) return 0;
        if(dp[ind][can] !=-1) return dp[ind][can];
        if(can) return dp[ind][can] = max(-v[ind]+f(ind+1,0,v,dp),f(ind+1,1,v,dp));
        else  return dp[ind][can] = max( v[ind]+f(ind+2,1,v,dp),f(ind+1,0,v,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};