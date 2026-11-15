/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode *head) {
    struct ListNode *curr;
    curr=head;
    while(curr->next!=NULL){
        if(curr->val==curr->next->val){
            struct ListNode *temp=curr->next;
            curr->next=temp->next;
            free(temp);
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}
