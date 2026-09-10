struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prevGroup = &dummy;

    while (1)
    {
        // Find the kth node
        struct ListNode* kth = prevGroup;

        for (int i = 0; i < k && kth != NULL; i++)
            kth = kth->next;

        // Less than k nodes remaining
        if (kth == NULL)
            break;

        struct ListNode* groupStart = prevGroup->next;
        struct ListNode* nextGroup = kth->next;

        // Reverse the current group
        struct ListNode* prev = nextGroup;
        struct ListNode* current = groupStart;

        while (current != nextGroup)
        {
            struct ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Connect previous part to reversed group
        prevGroup->next = kth;

        // Move to the next group
        prevGroup = groupStart;
    }

    return dummy.next;
}
