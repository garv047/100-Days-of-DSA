
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode smallDummy = {0, NULL};
    struct ListNode largeDummy = {0, NULL};

    struct ListNode *small = &smallDummy;
    struct ListNode *large = &largeDummy;

    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }

        head = head->next;
    }

    large->next = NULL;
    small->next = largeDummy.next;

    return smallDummy.next;
}
