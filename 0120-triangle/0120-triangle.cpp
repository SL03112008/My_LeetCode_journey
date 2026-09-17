class Solution {
private:
    int f(int i,int j,vector<vector<int>>& a,vector<vector<int>> &dp){
        if( i == a.size()-1 ) return a[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = a[i][j] + f(i+1,j,a,dp);  
        int right = a[i][j] + f(i+1,j+1,a,dp);
        return dp[i][j]=min(down,right);  
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(n+2,-1);
        for(int i=0;i<n;i++) dp[i]=triangle[n-1][i];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down = triangle[i][j]+dp[j];
                int right = triangle[i][j]+dp[j+1];
                dp[j] = min(down,right);
            }
        }
        return dp[0];
    }
};