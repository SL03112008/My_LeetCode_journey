class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=speed.size();
        int next = speed[n-1];
        int ans=n;
        for(int i=n-2;i>=0;i--){
            if(next<speed[i] || position[i+1]-position[i] <= distance) ans--;
            else next=speed[i];
        }
        return ans;
    }
};