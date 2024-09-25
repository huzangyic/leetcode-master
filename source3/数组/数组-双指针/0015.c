// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

 

 

// 示例 1：

// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 注意，输出的顺序和三元组的顺序并不重要。
// 示例 2：

// 输入：nums = [0,1,1]
// 输出：[]
// 解释：唯一可能的三元组和不为 0 。
// 示例 3：

// 输入：nums = [0,0,0]
// 输出：[[0,0,0]]
// 解释：唯一可能的三元组和为 0 。
 

// 提示：

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

int num_cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}


#define RES_NUM 18000
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // 题目要求不可以重复，首先对nums排序
    qsort(nums, numsSize, sizeof(int), num_cmp);

    // 处理排序后的异常情况
    if (nums[0] > 0 || nums[numsSize - 1] < 0) {
        *returnSize = 0;
        return NULL;
    }

    // 固定首个数字，双指针找之后的两个数字
    int **result = (int **)malloc(sizeof(int *) * RES_NUM);
    int left = 0;
    int right = numsSize - 1;
    int count = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] > 0) {
            continue;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            // printf("nums[%d] is %d\n", i, nums[i]);
            continue;
        }
        left = i + 1;
        right = numsSize - 1;
        int old_left = -1, old_right = -1;
        while (left != right) {
            if (old_left > 0 && old_left != left && nums[left] == nums[old_left]) {
                left++;
                continue;
            }
            if (old_right > 0 && old_right != right && nums[right] == nums[old_right]) {
                right--;
                continue;
            }
            if (nums[i] + nums[left] + nums[right] == 0) {
                // printf("---》%d %d %d\n", i, left, right);
                old_left = left;
                old_right = right;
                // printf("count is %d\n", count);
                result[count] = (int *)malloc(sizeof(int) * 3);
                result[count][0] = nums[i];
                result[count][1] = nums[left];
                result[count][2] = nums[right];
                count++;
                left++; // 不能break；因为可能出现 -4 1 3； -4 2 2 这种情况
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            } else if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            }
        }
    }

    int *outColumnSizes = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        outColumnSizes[i] = 3;
    }
    *returnColumnSizes = outColumnSizes;
    *returnSize = count;
    return result;
}