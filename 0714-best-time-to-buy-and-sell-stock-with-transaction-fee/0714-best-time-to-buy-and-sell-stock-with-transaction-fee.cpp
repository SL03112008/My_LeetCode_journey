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
        vector<int> cur(2,0);
        vector<int> after(2,0);
        vector<int> &v = prices;
        // return f(0,1,prices,fee,dp);
        int n = prices.size();
        for(int i=n-1;i>=0;i--){
            cur[1] = max(-fee-v[i]+after[0] , after[1]);
            cur[0] = max(v[i]+after[1] , after[0]);
            after=cur;
        }
        return cur[1];
    }
};