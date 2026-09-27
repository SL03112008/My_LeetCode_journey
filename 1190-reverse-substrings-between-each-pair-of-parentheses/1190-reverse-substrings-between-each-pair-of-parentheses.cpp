class Solution {
public:
    string reverseParentheses(string s) {
        string res1 = "",res="",res2="";
        int l=0;
        while(l<s.size() &&  s[l]!='('){
            res1+=s[l];
            l++;
        }
        int r=s.size()-1;
        while(r>l && r>=0 && s[r]!=')' ){
            res2+=s[r];
            r--;
        }  
        int prev = 0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                prev--;
                string temp = "";
                while(st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                if(st.empty()){
                    res+=temp;
                }
                else{
                    for(char ch:temp) st.push(ch);
                }
            }
            else if(s[i]== '('){
                prev++;
                st.push(s[i]);
            } 
            else{
                if(prev) st.push(s[i]);
                else res+=s[i];
            } 
        }
        return res;
    }
};