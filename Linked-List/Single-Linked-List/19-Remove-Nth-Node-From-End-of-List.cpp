// Problem: 19. Remove Nth Node From End of List
//
// Approach:
// First count the total number of nodes.
// The Nth node from the end is the (count - n + 1)th node from the start.
// If it is the first node, move head to head->next.
// Otherwise, find the node just before it and skip the target node.
//
// Time: O(n)
// Space: O(1)

// Direct NOTEBOOK CONVERSION

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        int k=count-n+1;
        count=0;
        ListNode* prev=NULL;
        temp=head;
        if(k==1) {
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        while(temp){
            count++;
            if(count==(k-1)){
                prev->next=prev->next->next;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};
