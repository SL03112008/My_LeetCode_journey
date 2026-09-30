class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n,0);
        stack<char> A,B;
        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                if(A.size()>B.size()){
                    B.push(seq[i]);
                    ans[i]=1;
                }
                else{
                    A.push(seq[i]);
                    ans[i]=0;
                }
            }
            else{
                if(A.size()>0){
                    A.pop();
                    ans[i]=0;
                }
                else{
                    B.pop();
                    ans[i]=1;
                }
            }
        }
        return ans;
    }
};