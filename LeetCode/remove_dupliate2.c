
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        // Check if duplicates exist
        if (curr->next != NULL &&
            curr->val == curr->next->val) {

            // Skip all nodes with the same value
            while (curr->next != NULL &&
                   curr->val == curr->next->val) {
                curr = curr->next;
            }

            prev->next = curr->next;
        }
        else {
            prev = prev->next;
        }

        curr = curr->next;
    }

    return dummy.next;
}
