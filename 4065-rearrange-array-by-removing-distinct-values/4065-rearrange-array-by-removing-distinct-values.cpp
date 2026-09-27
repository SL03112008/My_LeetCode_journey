class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> mp;
        vector<int> res;
        for(auto x:nums) mp[x]++;
        while(!mp.empty()){
            vector<int> del;
            for(auto &[key,freq]: mp){
                res.push_back(key);
                freq--;
                if(freq==0) del.push_back(key);
            }
            for(auto x:del) mp.erase(x);
        }
        
        return res;   
    }
};