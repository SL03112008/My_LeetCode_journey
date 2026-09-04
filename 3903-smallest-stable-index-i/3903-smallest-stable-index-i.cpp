class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxv,minv(n,0);
        int maxi=nums[0],mini=nums[n-1];
        for(int i =0;i<n;i++){
            maxi = max(nums[i],maxi);
            maxv.push_back(maxi);

            mini = min(mini,nums[n-i-1]);
            minv[n-i-1] = mini;
        }
        for(int i=0;i<n;i++){
            maxv[i] -= minv[i];
            if(maxv[i] <= k ) return i;
        }
        return -1;
    }
};