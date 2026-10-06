class Solution {
public:
    int minAddToMakeValid(string s) {
        int cntr=0,ans=0;
        for(char ch:s){
            if(ch=='(') cntr++;
            else cntr--;
            if(cntr<0){
                cntr++;
                ans++;
            }
        }
        return  abs(cntr) + ans;
    }
};