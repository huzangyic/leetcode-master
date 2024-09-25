// 类似15题
// 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

// 返回这三个数的和。

// 假定每组输入只存在恰好一个解。

 

// 示例 1：

// 输入：nums = [-1,2,1,-4], target = 1
// 输出：2
// 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
// 示例 2：

// 输入：nums = [0,0,0], target = 1
// 输出：0
// 解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。

#define ABS(x) ((x) > 0 ? (x) : -(x))
static int cmp(const void *p, const void *q)
{
    int *m = (int *)p;
    int *n = (int *)q;
    return *m - *n;
}

static int threeSumClosest(int* nums, int numsSize, int target)
{
    int start;
    int end;
    int ans;
    int i;

    if (numsSize < 3) {
        return -1;
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    ans = nums[0] + nums[1] + nums[2];
    for (i = 0; i < numsSize - 1; i++) {
        int tmp;

        start = i + 1;
        end = numsSize - 1;
        while (start != end) {
            tmp = nums[i] + nums[start] + nums[end];
            if (target < tmp) {
                end--;
            } else {
                start++;
            }
            if (ABS(target - tmp) < ABS(target - ans)) {
                ans = tmp;
            }
        }
    }
    return ans;
}