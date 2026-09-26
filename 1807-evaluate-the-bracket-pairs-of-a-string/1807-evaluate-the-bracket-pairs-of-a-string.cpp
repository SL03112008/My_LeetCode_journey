class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        string res= "";
        map<string,string> mp;
        for(auto x:knowledge){
            mp[x[0]]=x[1];
        }   
        for(int i=0;i<n;i++){
            if( s[i] =='(' ){
                i++;
                string temp = "";
                while(s[i]!=')'){
                    temp += s[i++];
                }
                res+=(mp.find(temp)==mp.end())?"?":mp[temp];
                continue;
            }
            else res+=s[i];
        }
        return res;
    }
};