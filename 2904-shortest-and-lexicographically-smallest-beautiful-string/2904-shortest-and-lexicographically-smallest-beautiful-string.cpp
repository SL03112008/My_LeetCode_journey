class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> v;
        string res="";
        for(int i=0;i<s.size();i++) if(s[i]=='1') v.push_back(i);
        int l=0,r=k-1;
        if(v.size()<k) return res;
        int left;
        for(int i=r;i<v.size();i++){
            string temp="";
            for(int k=v[l];k<=v[i];k++) temp+=s[k];
            //if(i==7) return temp;
            if(res=="" ) res=temp;
            else if(res.size()>temp.size()) res=temp;
            else if(res.size()==temp.size()) res=min(res,temp);

            
            l++;
        }
        return res;
    }
};