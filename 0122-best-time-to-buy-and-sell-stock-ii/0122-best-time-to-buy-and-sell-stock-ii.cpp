class Solution {
private:
    int f(int ind,vector<int>& v,int can,vector<vector<int>>& dp){
        if(ind==v.size()-1){
            if(can) return 0;
            else return v[ind];
        }
        if(dp[ind][can]!=-1) return dp[ind][can];
        int p1=0,p2=0;
        if(can==1){
            p1 = max( -v[ind]+f(ind+1,v,0,dp), f(ind+1,v,1,dp));
        }
        else{
            p2 = max(v[ind]+f(ind+1,v,1,dp) , f(ind+1,v,0,dp));
        }
        return dp[ind][can]=max(p1,p2);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,prices,1,dp);
    }
};