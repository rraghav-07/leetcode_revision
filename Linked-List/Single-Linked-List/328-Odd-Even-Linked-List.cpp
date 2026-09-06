/* Approach 1 — Vector
Store all odd-position nodes' values first, then all even-position values, and finally copy those values back into the original linked list.
Time: O(n)
Space: O(n)

Approach 2 — Pointers
Maintain:
odd → current odd-position node
even → current even-position node
evenhead → beginning of the even-position list
Rearrange the links so that:
1 → 2 → 3 → 4 → 5
becomes:
1 → 3 → 5 → 2 → 4
Time: O(n)
Space: O(1) */


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      
      APPROACH - 1
        vector<int> arr;
        ListNode* temp=head;
        if(head==NULL||head->next==NULL){
             return head;
         }
         while(temp != NULL) {
             arr.push_back(temp->val);
             if(temp->next==NULL)
                 break;
             temp=temp->next->next;
         }
         temp=head->next;
         while(temp != NULL) {
             arr.push_back(temp->val);
             if(temp->next==NULL)
                 break;
             temp=temp->next->next;
         }
         temp=head;
         int i=0;
         while(temp!=NULL){
             temp->val=arr[i];
             i++;
             temp=temp->next;
         }
         return head;

      NEWW APPROACH - 2
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenhead=head->next;
        while(odd!=NULL && odd->next!=NULL && even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};
