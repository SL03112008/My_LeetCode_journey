class Solution {
private:
    void f(string s,int n,int arith,vector<string> &v){
        if(n==0){
            s+=string(arith,')');
            v.push_back(s);
            return;
        }
        if(arith) f(s+string(1,')') ,n,arith-1,v);
        f(s+'(',n-1,arith+1,v);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        f("(",n-1,1,res);
        return res;
    }
};