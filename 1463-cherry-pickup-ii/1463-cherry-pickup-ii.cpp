class Solution {
private:
    int f(int r,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(c1<0 || c2<0 || c1>grid[0].size()-1 || c2>grid[0].size()-1) return -1;
        if(grid.size()-1 == r){
            if(c1==c2) return grid[r][c1];
            else return grid[r][c1]+grid[r][c2];
        }
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2]; 
        
        int maxi = 0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int val = grid[r][c1];
                if(c1!=c2) val+=grid[r][c2];
                val += f(r+1,c1+i,c2+j,grid,dp);
                maxi = max(maxi , val);
            }
        }
        return dp[r][c1][c2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,grid[0].size()-1,grid,dp);
    }
};