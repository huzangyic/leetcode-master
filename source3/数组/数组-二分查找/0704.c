// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

// 示例 1:

// 输入: nums = [-1,0,3,5,9,12], target = 9     
// 输出: 4       
// 解释: 9 出现在 nums 中并且下标为 4     
// 示例 2:

// 输入: nums = [-1,0,3,5,9,12], target = 2     
// 输出: -1        
// 解释: 2 不存在 nums 中因此返回 -1  

// 左闭右闭写法
int search(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    if (target < nums[left] || target > nums[right])
        return -1;

    int mid;
    while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1; // target 在右区间，所以[middle + 1, right]
        } else {
            right = mid - 1; // target 在左区间，所以[left, middle - 1]
        }
    }

    return -1;
}

// 左闭右开写法
int search2(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    if (target < nums[left] || target > nums[right])
        return -1;

    int mid;
    while (left < right) { // 当left==right，区间[left, right)是没有意义的，所以用 <
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1; // target 在右区间，所以[middle + 1, right)
        } else {
            right = mid; // target 在左区间，所以[left, middle)
        }
    }

    return -1;
}