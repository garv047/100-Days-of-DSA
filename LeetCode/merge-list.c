#include <stdlib.h>

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;

    struct ListNode** heap =
        (struct ListNode**)malloc(listsSize * sizeof(struct ListNode*));

    int heapSize = 0;

    // Put the first node of each list into the heap
    for (int i = 0; i < listsSize; i++)
    {
        if (lists[i] != NULL)
            heap[heapSize++] = lists[i];
    }

    // Build min heap
    for (int i = heapSize / 2 - 1; i >= 0; i--)
    {
        int p = i;

        while (1)
        {
            int smallest = p;
            int left = 2 * p + 1;
            int right = 2 * p + 2;

            if (left < heapSize &&
                heap[left]->val < heap[smallest]->val)
                smallest = left;

            if (right < heapSize &&
                heap[right]->val < heap[smallest]->val)
                smallest = right;

            if (smallest == p)
                break;

            struct ListNode* temp = heap[p];
            heap[p] = heap[smallest];
            heap[smallest] = temp;

            p = smallest;
        }
    }

    struct ListNode dummy;
    struct ListNode* current = &dummy;
    dummy.next = NULL;

    while (heapSize > 0)
    {
        // Take smallest node
        struct ListNode* node = heap[0];

        current->next = node;
        current = current->next;

        // Replace root with next node
        if (node->next != NULL)
        {
            heap[0] = node->next;
        }
        else
        {
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }

        // Restore min heap
        int p = 0;

        while (heapSize > 0)
        {
            int smallest = p;
            int left = 2 * p + 1;
            int right = 2 * p + 2;

            if (left < heapSize &&
                heap[left]->val < heap[smallest]->val)
                smallest = left;

            if (right < heapSize &&
                heap[right]->val < heap[smallest]->val)
                smallest = right;

            if (smallest == p)
                break;

            struct ListNode* temp = heap[p];
            heap[p] = heap[smallest];
            heap[smallest] = temp;

            p = smallest;
        }
    }

    current->next = NULL;

    free(heap);

    return dummy.next;
}
