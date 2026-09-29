class Solution {
private:
    bool f(int sum,int i,int j,vector<vector<char>>& grid,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(sum<0) return 0;
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        int q=0;
        if(grid[i][j]=='(') q=1;
        else q=-1;
        if(i==n-1 && j==m-1) return sum+q==0;
        bool right,down;right=false;down=false;
        if(j!=m-1)  right = f(sum+q, i,j+1,grid,dp);
        if(i!=n-1)  down  = f(sum+q, i+1,j,grid,dp);
        return dp[i][j][sum] = down||right;
    } 
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]!='(') return false;
        if(grid[n-1][m-1]!=')') return false;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1000,-1)));
        return f(0,0,0,grid,dp);
    }
};