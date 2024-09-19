// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 

// 示例 1：

// 输入：nums = [-4,-1,0,3,10]
// 输出：[0,1,9,16,100]
// 解释：平方后，数组变为 [16,1,0,9,100]
// 排序后，数组变为 [0,1,9,16,100]
// 示例 2：

// 输入：nums = [-7,-3,2,3,11]
// 输出：[4,9,9,49,121]
 

// 提示：

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums 已按 非递减顺序 排序


int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *result = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    
    if (nums[0] >= 0) {
        for (int i = 0; i < numsSize; i++) {
            result[i] = nums[i] * nums[i];
        }
    } else if (nums[numsSize - 1] < 0) {
        for (int i = 0; i < numsSize; i++) {
            result[i] = nums[numsSize - 1 - i] * nums[numsSize - 1 - i];
        }
    } else {
        int left = 0, right = 0;
        while (nums[right] < 0) {
            right++;
        }
        left = right - 1;

        int index = 0;
        while (left >= 0 && right <= numsSize - 1) {
            if (nums[right] < (0 - nums[left])) {
                result[index++] = nums[right] * nums[right];
                right++;
            } else {
                result[index++] = nums[left] * nums[left];
                left--;
            }
        }

        while (left >= 0) {result[index++] = nums[left] * nums[left]; left--;}
        while (right <= numsSize - 1) {result[index++] = nums[right] * nums[right]; right++;}
    }

    return result;
}



// 更好的做法
// 同样地，我们可以使用两个指针分别指向位置 000 和 n−1n-1n−1，每次比较两个指针对应的数，选择较大的那个逆序放入答案并移动指针。
// 这种方法无需处理某一指针移动至边界的情况，读者可以仔细思考其精髓所在。

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0, j = numsSize - 1, pos = numsSize - 1; i <= j;) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            ans[pos] = nums[i] * nums[i];
            ++i;
        } else {
            ans[pos] = nums[j] * nums[j];
            --j;
        }
        --pos;
    }
    return ans;
}