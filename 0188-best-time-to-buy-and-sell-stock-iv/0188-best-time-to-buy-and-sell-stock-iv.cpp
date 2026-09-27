class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> &v = prices;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind = n-1;ind>=0;ind--){
            for(int can=0;can<=1;can++){
                for(int ct=0;ct<k;ct++){
                    if(can) dp[ind][1][ct] = max(-v[ind] + dp[ind+1][0][ct],dp[ind+1][1][ct]);
                    else dp[ind][0][ct] = max( v[ind] + dp[ind+1][1][ct+1],dp[ind+1][0][ct]);
                }
            }
        }
        return dp[0][1][0];
    }
};