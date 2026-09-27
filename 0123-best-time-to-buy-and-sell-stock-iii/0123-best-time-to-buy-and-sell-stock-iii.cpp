class Solution {
private:
    int f(vector<int> &v,int ind,int can,int ct,vector<vector<vector<int>>> dp){
        if(ct==2) return 0;
        if(ind == v.size()) return 0;
        if(dp[ind][can][ct] != -1) return dp[ind][can][ct];
        if(can) return dp[ind][can][ct]  = max( -v[ind] + f(v,ind+1,0,ct,dp) , f(v,ind+1,1,ct,dp));
        else return dp[ind][can][ct] = max( v[ind] + f(v,ind+1,1,ct+1,dp) , f(v,ind+1,0,ct,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> &v = prices;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //return f(prices,0,1,0,dp);
        for(int ind=n-1;ind>=0;ind--){
            for(int can=0;can<=1;can++){
                for(int ct=0;ct<2;ct++){
                    if(can==1) dp[ind][1][ct]  = max( -v[ind] + dp[ind+1][0][ct] , dp[ind+1][1][ct]);
                    else  dp[ind][0][ct] = max( v[ind] + dp[ind+1][1][ct+1] , dp[ind+1][0][ct]);
                }
            }
        }
        return dp[0][1][0];


    }
};