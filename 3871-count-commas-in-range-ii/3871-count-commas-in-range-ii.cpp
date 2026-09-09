class Solution {
public:
    long long countCommas(long long n) {
        int res=0;
        if(n<1000) return 0;
        if(n==1e15) return 3998998998999005;
        else if(n>=1000 && n<1000000) return (n-1000+1);
        else if(n>=1000000 && n<1000000000){
          return (n - 1000000+1)*2 + (1e6-1e3);  
        } 
        else if(n>=1e9 && n<1e12) return (n-1e9+1)*3 + (1e9 - 1e6)*2 + (1e6-1e3);
        else return (n-1e12+1)*4 + (1e12-1e9)*3 + (1e9 - 1e6)*2 + (1e6-1e3);
    }
};