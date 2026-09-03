class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size() == 1) return true;
        
        int flag=0,odd=0;
        sort(nums1.begin(), nums1.end());
        int even = 0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] %2 == 0){
                even++;
            }
            else odd++;
            if(even == 1 && odd == 0){
                flag = 1;
            }
            if(flag == 1 && odd == 1) return false;
        }
        
        if(odd == 0 || even == 0) return true;
        return true;

    }
};