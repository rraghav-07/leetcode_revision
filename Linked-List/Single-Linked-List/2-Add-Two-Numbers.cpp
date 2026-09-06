// Problem: 2. Add Two Numbers
//
// Approach:
// Traverse both linked lists together and add their digits.
// Keep track of carry just like normal addition.
// A dummy node is used to easily build the result list.
//
// Time: O(max(n, m))
// Space: O(max(n, m))  // for the result linked list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        ListNode* dummy=new ListNode(-5);
        ListNode* curr=dummy;
        while(temp1!=NULL||temp2!=NULL){
            int sum=carry;
            if(temp1){
                sum+=temp1->val;
            }
            if(temp2){
                sum+=temp2->val;
            }
            ListNode* x=new ListNode((sum)%10);
            curr->next=x;
            curr=curr->next;
            carry=(sum)/10;
            if(temp1){
                temp1=temp1->next;
            }
            if(temp2){
                temp2=temp2->next;
            }
        }
        if(carry){
            ListNode* y=new ListNode(carry);
            curr->next=y;
        }
        return dummy->next;
    }
};
