/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,0);
        ans[0]=INT_MAX;
        if(head->next->next == nullptr) return {-1,-1};
        int ct=1,flag=0,last=0;
        ListNode *cur=head->next,*nxt=head->next->next,*prev=head;
        while(nxt){
            if(cur->val>prev->val && cur->val>nxt->val){
                if(flag>=1){
                    ans[0]=min(ans[0],(ct-last));
                    // ans[1]=max(ans[1],(ct-last));
                    
                }
                last=ct;
                if(flag==0) ans[1]=(-ct);
                flag+=1;
            }
            if(cur->val<prev->val && cur->val<nxt->val){
                if(flag>=1){
                    ans[0]=min(ans[0],(ct-last));
                    //ans[1]=max(ans[1],(ct-last));
                    
                }
                last=ct;
                if(flag==0) ans[1]=(-ct);
                flag+=1;
            }
            ct++;
            prev=cur;
            cur=nxt;
            nxt=nxt->next;
            
        }
        ans[1]+=last;
        //return {};
        if(flag>1) return ans;
        else return {-1,-1};
    }
};