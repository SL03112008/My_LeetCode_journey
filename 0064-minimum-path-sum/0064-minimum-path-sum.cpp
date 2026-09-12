class Solution {
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = f(i-1,j,grid,dp);
        int left = f(i,j-1,grid,dp);
        return dp[i][j]=grid[i][j]+min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[j]=grid[i][j];
                else{
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up = prev[j];
                    if(j>0) left = temp[j-1];
                    temp[j] =  grid[i][j] + min(up,left);
                }
                
            }
            prev = temp;
        }
        return prev[n-1];
    }
};