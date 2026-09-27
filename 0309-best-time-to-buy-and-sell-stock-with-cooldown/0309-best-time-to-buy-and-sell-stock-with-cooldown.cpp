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
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
        vector<int> &v= prices;
        int n= v.size();
        //return f(0,1,prices,dp);
        for(int ind=n-1;ind>=0;ind--){
            dp[ind][1] = max(-v[ind]+dp[ind+1][0],dp[ind+1][1]);
            dp[ind][0] = max(v[ind]+dp[ind+2][1],dp[ind+1][0]);
        }
        return dp[0][1];
    }
};