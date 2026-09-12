class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int> temp(n,1);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    temp[j]=0;
                    continue;
                } 
                int left=0,up=0;
                if(i==0 && j==0) temp[j]=1;
                else{
                    if(j>0) left = temp[j-1];
                    if(i>0) up = prev[j];
                    temp[j] = up+left;
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};