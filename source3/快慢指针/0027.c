// 示例 1:
// 给定 nums = [3,2,2,3], val = 3,
// 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
// 你不需要考虑数组中超出新长度后面的元素。

// 示例 2:
// 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
// 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

// 暴力+交换剪枝， 是暴力+后移的加强版

#include "test.h"
int removeElement(int *nums, int size, int val)
{
    if (size == 0) {
      return 0;
    }

    int right = size - 1;
    int left = 0;
    int tmp;

    while (left < right) {
        if (nums[left] == val) {
            while (left < right && nums[right] == val) {
                right--
            }
            if (left != right) {
                tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            } else {
                break;
            }
        }
        left++;
    }
    return nums[left] == val ? left : left + 1;
}

// 快慢指针。慢的不动，等快值的走到满足条件的覆盖慢值
int removeElement2(int *nums, int size, int val)
{
    int slow = 0;

    for (int fast = 0; fast < size; fast++) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
    }

    return slow + 1;
}


// 补充26题
// 补充283题
