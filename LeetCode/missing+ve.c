int firstMissingPositive(int* nums, int numsSize)
{
    // Put every number x in position x-1
    for (int i = 0; i < numsSize; i++)
    {
        while (nums[i] >= 1 &&
               nums[i] <= numsSize &&
               nums[nums[i] - 1] != nums[i])
        {
            int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }

    // Find the first position where the number is incorrect
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return numsSize + 1;
}
