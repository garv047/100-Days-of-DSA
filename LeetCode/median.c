#include <stdio.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n)
{
    // Always binary search on the smaller array
    if (m > n)
        return findMedianSortedArrays(nums2, n, nums1, m);

    int low = 0;
    int high = m;

    while (low <= high)
    {
        int partition1 = (low + high) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        int left1, right1, left2, right2;

        if (partition1 == 0)
            left1 = -2147483647;
        else
            left1 = nums1[partition1 - 1];

        if (partition1 == m)
            right1 = 2147483647;
        else
            right1 = nums1[partition1];

        if (partition2 == 0)
            left2 = -2147483647;
        else
            left2 = nums2[partition2 - 1];

        if (partition2 == n)
            right2 = 2147483647;
        else
            right2 = nums2[partition2];

        if (left1 <= right2 && left2 <= right1)
        {
            // Odd number of elements
            if ((m + n) % 2 == 1)
            {
                return (left1 > left2) ? left1 : left2;
            }

            // Even number of elements
            int maxLeft = (left1 > left2) ? left1 : left2;
            int minRight = (right1 < right2) ? right1 : right2;

            return (maxLeft + minRight) / 2.0;
        }
        else if (left1 > right2)
        {
            high = partition1 - 1;
        }
        else
        {
            low = partition1 + 1;
        }
    }

    return 0.0;
}
