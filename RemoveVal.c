/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *curr = head;
    while (head != NULL && head->val == val) {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }
    curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode *temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}
