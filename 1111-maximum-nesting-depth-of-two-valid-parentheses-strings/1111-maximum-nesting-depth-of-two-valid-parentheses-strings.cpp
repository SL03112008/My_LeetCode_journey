class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n,0);
        int A=0,B=0;
        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                if(A>B){
                    B++;
                    ans[i]=1;
                }
                else{
                    A++;
                    ans[i]=0;
                }
            }
            else{
                if(A>0){
                    A--;
                    ans[i]=0;
                }
                else{
                    B--;
                    ans[i]=1;
                }
            }
        }
        return ans;
    }
};