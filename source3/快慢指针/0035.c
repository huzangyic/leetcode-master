#include "test.h"

int searchInsert(int *nums, int size, int target)
{
    // 在遍历的过程中，就通过 “<=” 的条件来筛选结果，事半功倍
    for (int i = 0; i < size; i++) {
        if (target <= nums[i]) {
            return i;
        }
    }

    return size;
}

// 这个二分写得应该还有瑕疵
// 什么时候 >,< 什么时候 >=,<= ， 取决于要实现左闭右开还是左闭右闭
int searchInsert(int *nums, int size, int target)
{
    int head = 0; // 闭
    int tail = size; // 开
    int mid;

    // 左闭右开
    while (head < tail) {
        mid = (head + tail) / 2;
        if (nums[mid] == target) {
            return mid; // 闭
        } else if (nums[mid] > target) {
            tail = mid; // 开
        } else {
            head = mid + 1; // 闭
        }
    }

    return tail ;
}