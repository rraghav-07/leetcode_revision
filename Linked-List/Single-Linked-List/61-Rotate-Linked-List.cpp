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
    ListNode* rotateRight(ListNode* head, int k) {
        // if(head==NULL||head->next==NULL){
        //     return head;
        // }
        // vector<int> arr(501);
        // ListNode* temp=head;
        // int i=0;
        // while(temp){
        //     arr[i]=temp->val;
        //     i++;
        //     temp=temp->next;
        // }
        // k=k%i;
        // while(k>0){
        //     int last=arr[i-1];
        //     for(int j=i-1;j>0;j--){
        //         arr[j]=arr[j-1];
        //     }
        //     arr[0]=last;
        //     k--;
        // }
        // ListNode* temp1=head;
        // int n=0;
        // while(temp1){
        //     temp1->val=arr[n];
        //     temp1=temp1->next;
        //     n++;
        // }
        // return head;
        if(head==NULL||head->next==NULL||k==0){
            return head;
        }
        ListNode* temp=head;
        int count=1;
        while(temp->next){
            count++;
            temp=temp->next;
        }
        if(k%count==0){
            return head;
        }
        temp->next=head;
        int a=k%count;
        int n=count-a;
        int tot=1;
        temp=head;
        while(temp){
            if(tot==n){
                break;
            }
            temp=temp->next;
            tot++;
        }
        ListNode* prev=temp->next;
        temp->next=NULL;
        return prev;
    }
};
