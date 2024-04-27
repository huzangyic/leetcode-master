#include "test.h"

int main(int argc, void *argv)
{
    int *nums = malloc(sizeof(int) * 5);
    nums[0] = 1;
    nums[1] = 0;
    nums[2] = 3;
    nums[3] = 2;
    nums[4] = 0;
    moveZeroes(nums, 5);
    return 0;
}