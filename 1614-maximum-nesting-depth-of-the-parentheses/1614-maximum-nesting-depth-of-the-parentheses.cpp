class Solution {
public:
    int maxDepth(string s) {
        int ct=0,cp=0,maxi=0;
        for(char ch:s){
            if(ch=='(') ct++;
            else if(ch==')') ct--;
            //if(ct==cp) ct=cp=0;
            maxi = max(maxi,ct);
        }
        return maxi;
    }
};