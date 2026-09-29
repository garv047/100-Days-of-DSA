struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    // Find length and last node
    int length = 1;
    struct ListNode* last = head;

    while (last->next != NULL)
    {
        last = last->next;
        length++;
    }

    // Avoid unnecessary rotations
    k = k % length;

    if (k == 0)
        return head;

    // Make the list circular
    last->next = head;

    // Find the new last node
    int steps = length - k;
    struct ListNode* newLast = head;

    for (int i = 1; i < steps; i++)
        newLast = newLast->next;

    // New head
    struct ListNode* newHead = newLast->next;

    // Break the circle
    newLast->next = NULL;

    return newHead;
}
