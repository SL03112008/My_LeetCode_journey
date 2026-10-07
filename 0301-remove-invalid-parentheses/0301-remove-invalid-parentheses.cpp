class Solution {
private:
    void f(string s,set<string> &v,int ops,map<string,int> &dp){
        int open = 0,close=0;
        int n=s.size();
        //set<string> ms;
        if(dp[s]>1) return;
        for(int i=0;i<n;i++){
            if(s[i] == '(') open++;
            else if(s[i] == ')') close++;
            else continue;

            if(open<close){
                for(int j=0;j<=i;j++){
                    if(s[j] == ')'){
                        string res = s;
                        res.erase(j,1);
                        dp[res]++;
                        if(ops>0) f(res,v,ops-1,dp);
                    }
                }
            }
        }
        if(close==open) v.insert(s);
        else if(open>close){
            for(int i=0;i<n;i++){
                if(s[i]=='('){
                    string res = s;
                    res.erase(i,1);
                    dp[res]++;
                    if(ops>0) f(res,v,ops-1,dp);
                }
            }
        }
    }
    int isValid(string s){
        int cntr = 0;
        for(char ch:s){
            if(ch=='(') cntr++;
            else if(ch==')') cntr--;
            if(cntr<0) return 0;
        }
        return cntr==0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        int mini = 0,cntr=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') cntr++;
            else if(s[i] == ')') cntr--;
            else continue;

            if(cntr<0){
                cntr++;
                mini++;
            }
        }
        mini += abs(cntr);
        map<string,int> dp;
        f(s,ans,mini,dp);
        vector<string> v;
        for(auto str:ans){
            if(isValid(str)) v.push_back(str);
        }
        //v.push_back(to_string(mini));
        return v;
    }
};