class Solution {
private:
    int f(string s,int l,int r){
        int score = 0,cntr = 0;
        for(int i=l;i<=r;i++){
            if(s[i]=='(') cntr++;
            else cntr--;
            if(cntr==0){
                if(i-l == 1) score++;
                else score += 2*f(s,l+1,i-1); 
                l = i+1;
            }
        }
        return score;
    }
public:
    int scoreOfParentheses(string s) {
        return f(s,0,s.size()-1);
    }
};