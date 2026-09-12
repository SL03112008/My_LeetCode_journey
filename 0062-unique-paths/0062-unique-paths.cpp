class Solution {
private:
    int f(int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]= f(i-1,j,dp) + f(i,j-1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++){
            vector<int> temp(n,1);
            for(int j=1;j<n;j++){
                int up=0,left=0;
                if(i>0) up = dp[j];
                if(j>0) left = temp[j-1];
                temp[j] = up+left; 
            }
            dp = temp;
        }
        return dp[n-1];
    }
};