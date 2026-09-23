class Solution {
private:
    int f(int ind,vector<int>& v,int can,vector<vector<int>>& dp){
        if(ind==v.size()){
            // if(can) return 0;
            // else return v[ind];
            return 0;
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
        //vector<vector<int>> dp(n+1,vector<int>(2,-1));
        vector<int> dp(2,0);
        vector<int> &v = prices;
        //return f(0,prices,1,dp);
        dp[0] = v[n-1];
        dp[1] = 0;
        for(int i=n-2;i>=0;i--){
            vector<int> temp(2,0);
            temp[0] = max(v[i]+dp[1], dp[0]);
            temp[1] = max(-v[i]+dp[0], dp[1]);
            dp=temp;
        }
        return (dp[1]);
    }
};