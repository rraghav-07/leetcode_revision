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
    ListNode* mergeNodes(ListNode* head) {
      //APPROACH 1- Make new nodes and equate sum
        // ListNode* temp=head;
        // int sum=0;
        // temp=temp->next;
        // ListNode* result=NULL;
        // ListNode* tail=NULL;
        // while(temp){
        //     if(temp->val==0){
        //         ListNode* neww= new ListNode(sum);
        //         if (result==NULL) {
        //             result=neww;
        //             tail=neww;
        //         }else{
        //             tail->next=neww;
        //             tail=neww;
        //         }
        //         sum=0;
        //     }else{
        //         sum+=temp->val;
        //     }
        //     temp=temp->next;
        // }
        // return result;

      //INPLACE APPROACH 2

    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        temp=temp->next;
        ListNode* res=head;
        ListNode* ans=res;
        int sum=0;
        while(temp){
            if(temp->val==0){
                res->val=sum;
                if(temp->next!=NULL){
                    res=res->next;
                }
                sum=0;
            }else{
                sum+=temp->val;
            }
            temp=temp->next;
        }
        res->next=NULL;
        return ans;
    }
};
