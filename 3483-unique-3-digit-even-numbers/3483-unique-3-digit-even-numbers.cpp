class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> v(10,0);
        map<int,int> mp;
        int n=digits.size();
        for(int i=0;i<n;i++){
            v[digits[i]]++;
            mp[digits[i]%2]++;
        }

        int res=0;
        for(int i=1;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<9;k+=2){
                    res += (v[i]>0) && (v[j]>(i==j)) && (v[k]>((i==k)+(j==k)));
                    //if(res==5) return (i*100)+(j*10)+k;
                }
            }
        }
        return res;
       

    }
};