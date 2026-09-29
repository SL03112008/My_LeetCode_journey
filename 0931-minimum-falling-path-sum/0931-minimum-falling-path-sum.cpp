class Solution {
private:
    int f(vector<vector<int>>& m,int n, int i, int j, vector<vector<int>>&dp){
        if(j<0||j>n-1) return 1e5;
        if(i==n-1) return m[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int a=0, b=0,c=0;
        a= m[i][j] + f(m,n,i+1,j-1,dp);
        b= m[i][j]+ f(m,n,i+1,j,dp);
        c= m[i][j]+ f(m,n,i+1,j+1,dp);

        return dp[i][j]= min(a, min(b,c));
    }
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n= m.size();
        //vector<vector<int>>dp(n, vector<int>(n,-1));
        vector<int> after(n,0);
        vector<int> cur(n,0);
        after = m[n-1];
        int ans=1e5;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int a,b,c;a=b=c=1e5;
                if(j>0) a= m[i][j] + after[j-1];
                b= m[i][j]+ after[j];
                if(j<n-1) c= m[i][j]+ after[j+1];
                cur[j]= min(a,min(b,c));
                //if(i==0)ans = min(ans,dp[i][j]);
            }
            after = cur;
        }   
        for(int i=0;i<n;i++) ans= min(ans, after[i]);
        return ans;
    }
};