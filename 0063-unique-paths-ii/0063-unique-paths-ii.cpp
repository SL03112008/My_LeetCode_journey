class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                } 
                int left=0,up=0;
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    if(j>0) left = dp[i][j-1];
                    if(i>0) up = dp[i-1][j];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};