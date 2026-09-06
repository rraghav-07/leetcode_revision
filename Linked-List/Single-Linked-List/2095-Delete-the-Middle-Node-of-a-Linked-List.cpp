// Problem: 2095. Delete the Middle Node of a Linked List
//
// Approach:
// First count the number of nodes.
// Find the position of the middle node.
// Traverse again while keeping track of the previous node,
// then remove the middle node by changing prev->next.
//
// For an even-sized list, the problem considers the second middle node.
//
// Time: O(n)
// Space: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        count--;
        int tot = 0;
        if (count % 2 != 0) {
            tot = count / 2 + 1;
        } else {
            tot = count / 2;
        }
        ListNode* prev = NULL;
        temp = head;
        tot++;
        count = 0;
        while (temp) {
            count++;
            if (count == tot) {
                if (prev->next) {
                    prev->next = prev->next->next;
                    delete temp;
                    break;
                } else {
                    prev->next = NULL;
                    delete temp;
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
