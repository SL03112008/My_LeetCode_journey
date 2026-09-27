class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> &v = prices;
        int n = prices.size();
        vector<vector<int>> cur(2,vector<int>(k+1,0));
        vector<vector<int>> after(2,vector<int>(k+1,0));
        for(int ind = n-1;ind>=0;ind--){
            for(int can=0;can<=1;can++){
                for(int ct=0;ct<k;ct++){
                    if(can) cur[1][ct] = max(-v[ind] + after[0][ct],after[1][ct]);
                    else cur[0][ct] = max( v[ind] + after[1][ct+1],after[0][ct]);
                }
            }
            after = cur;
        }
        return after[1][0];
    }
};