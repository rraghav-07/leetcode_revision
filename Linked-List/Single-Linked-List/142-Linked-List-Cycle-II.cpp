/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // if(head==NULL){
        //     return head;
        // }
        // unordered_map<ListNode*,int> mpp;
        // ListNode* temp=head;
        // while(temp){
        //     if(mpp.find(temp)!=mpp.end()){
        //         return temp;
        //     }
        //     mpp[temp]++;
        //     temp=temp->next;
        // }
        // return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        bool ans=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ans=true;
                break;
            }
        }
        if(ans){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }else{
            return NULL;
        }
    }
};
