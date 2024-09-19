// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

// 示例 1：

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]
// 示例 2：

// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]
// 示例 3：

// 输入：nums = [], target = 0
// 输出：[-1,-1]
 

// 提示：

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums 是一个非递减数组
// -109 <= target <= 109

// 边界太难处理了

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *result = malloc(sizeof(int) * 2);
    *returnSize = 2;
    if (numsSize == 0) {
        result[0] = -1;
        result[1] = -1;
        return result;
    }

    int left = 0;
    int right = numsSize - 1;
    // 找左边
    result[0] = findLeft(nums, numsSize, target, 0, numsSize - 1);
    // 找右边
    result[1] = findLeft(nums, numsSize, target, result[0], numsSize - 1);

    return result;
}