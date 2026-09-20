class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        map<char,int> mp;
        char ch='a';
        for(int i=26;i>=0;i--,ch++){
            mp[ch]=i;
        }
        int ct=1;
        for(char &ch:s){
            sum+=(ct*mp[ch]);ct++;
        }
        return sum;
    }
};