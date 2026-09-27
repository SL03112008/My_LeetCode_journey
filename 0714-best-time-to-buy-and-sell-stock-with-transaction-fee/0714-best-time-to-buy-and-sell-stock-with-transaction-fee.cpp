class Solution {
private:
    int f(int ind,int can ,vector<int> &v, int fee,vector<vector<int>> &dp){
        if(ind == v.size()) return 0;
        if(dp[ind][can]!=-1) return dp[ind][can];
        if(can) return dp[ind][can] = max( -fee-v[ind] + f(ind+1,0,v,fee,dp) , f(ind+1,1,v,fee,dp));
        else return dp[ind][can] = max( v[ind] + f(ind+1,1,v,fee,dp) , f(ind+1,0,v,fee,dp));
        
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return f(0,1,prices,fee,dp);
    }
};