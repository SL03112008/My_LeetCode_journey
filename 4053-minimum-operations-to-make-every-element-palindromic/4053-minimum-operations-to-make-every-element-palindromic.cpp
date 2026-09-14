vector<long long int> odd;
vector<long long int> even;
bool is = false;

void preC(int len,string s){
    if(s.size()>len) return;
    if(s.size()>0 && s[0]!='0'){
        long long int num = stoll(s);
        if((s[0]-'0')%2==0) even.push_back(num);
        else odd.push_back(num);
    }
    for(char ch='0';ch<='9';ch++) preC(len,ch+s+ch); 
}

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        if(!is){
            preC(9,"");
            for(char ch='0';ch<='9';ch++) preC(9,string(1,ch));
            sort(odd.begin(),odd.end()); 
            sort(even.begin(),even.end());
            is=true; 
        }
        long long int ops=0;
        for(auto &x:nums){
            vector<long long int> &temp = (x%2==0)?even:odd;
            auto it = upper_bound(temp.begin(),temp.end(),x);
            long long int mini = 1e9+1;
            if(it!=temp.end()) mini = min(mini,abs((*it)-x));
            if(it!=temp.begin()) mini = min(mini,abs(*(it-1)-x));
            ops+=(mini/2);
        } 
        return ops;
    }
};