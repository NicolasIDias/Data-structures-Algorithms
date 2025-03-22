#include <stdio.h>

int main()
{
    int nums[] = {0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int expectedNums[size];
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (i == size - 1 || nums[i] != nums[i + 1])
        {
            expectedNums[counter] = nums[i];
            counter++;
        }
    }

    for (int i = 0; i < counter; i++)
    {
        printf("%d ", expectedNums[i]);
    }

    return 0;
}