int firstMissingPositive(int* nums, int numsSize)
{
    int target = 0;
    // 处理数组：小于1或者大于numsSize的元素统一处理成1
    bool found = false;
    for (int i = 0; i < numsSize; i++) {
        if (!found && nums[i] == 1) {
            found = true;
        }
        if (nums[i] < 1 || nums[i] > numsSize) {
            nums[i] = 1;
        }
    }
    if (!found) {
        return 1;
    }

    // 若相应元素存在，则设置对应索引下标元素为负数
    int idx;
    for (int i = 0; i < numsSize; i++) {
        idx = abs(nums[i]) - 1;
        // 这里用abs的目的是，防止一个数被多次改变符号;
        nums[idx] = abs(nums[idx]) * (-1);
    }

    int index = 0;
    for (; index < numsSize; index++) {
        if (nums[index] > 0) {
            break;
        }
    }

    return index + 1;
}

// 进一步的，如果想追求时间复杂度低，可以把小于1的处理成numsSize+1
// 这样，在标记负数的时候只需要处理元素值小于等于numsSize的元素

int firstMissingPositive2(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] <= 0) {
            nums[i] = numsSize + 1;
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        int num = abs(nums[i]);
        if (num <= numsSize) {
            nums[num - 1] = -abs(nums[num - 1]);
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    return numsSize + 1;
}