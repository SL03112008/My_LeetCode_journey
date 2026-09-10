class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp1(3,0),dp2(3,0);
        dp1[1]=nums[0];dp1[2]=nums[0];
        dp2[1]=nums[1];dp2[2]=nums[1];
        for(int i=1;i<nums.size()-1;i++){
            int rob = nums[i];
            if(i!=1) rob+=dp1[0];
            int skip = dp1[1];
            dp1[2] = max(rob,skip);
            dp1[0]=dp1[1];dp1[1]=dp1[2];

            rob = nums[i+1];
            if((i+1) != 2) rob+=dp2[0];
            skip = dp2[1];
            dp2[2]=max(rob,skip);
            dp2[0]=dp2[1];dp2[1]=dp2[2];
        }
        return max(dp1[2],dp2[2]);

        
    }
};