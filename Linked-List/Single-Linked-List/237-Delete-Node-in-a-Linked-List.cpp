/*Approach
You are not actually deleting the given node directly, because you don't have access to the previous node.
Instead:
Copy the value of the next node into the current node.
Make the current node skip the next node.
Free the old next node.
Example:
1 → 2 → 3 → 4
    ↑
   node
Copy 3 into 2:
1 → 3 → 3 → 4
Skip the duplicate:
1 → 3 → 4
Complexity
Time: O(1)
Space: O(1)*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        ListNode* temp=node->next;
        node->next=node->next->next;
        delete temp;
    }
};
