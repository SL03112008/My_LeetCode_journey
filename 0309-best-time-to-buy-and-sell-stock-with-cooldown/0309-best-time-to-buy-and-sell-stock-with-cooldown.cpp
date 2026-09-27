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
        vector<int> after2(2,0);
        vector<int> after1(2,0);
        vector<int> cur(2,0);
        vector<int> &v= prices;
        int n= v.size();
        //[0,0] after2
        //[4,0] after1
        //[2,2] cur
        //return f(0,1,prices,dp);
        for(int ind=n-1;ind>=0;ind--){
            cur[1] = max(-v[ind]+after1[0],after1[1]);
            cur[0] = max(v[ind]+after2[1],after1[0]);
            after2=after1;
            after1=cur;
        }
        return cur[1];
    }
};