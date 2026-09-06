// Problem: 876. Middle of the Linked List
//
// Approach:
// First count the total number of nodes.
// The middle index is count / 2.
// Traverse again until reaching that position and return that node.
//
// For an even-sized list, count / 2 gives the SECOND middle node.
//
// Time: O(n)
// Space: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        int mid=count/2;
        count=0;
        temp=head;
        while(temp){
            count++;
            if(count==(mid+1)){
                head=temp;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};
