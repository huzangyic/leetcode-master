double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int all = nums1Size + nums2Size;
    int target = (all + 1) / 2;    
    int count = 0;
    int left = 0, right = 0;
    int ptr1 = 0, ptr2 = 0;

    if (nums1Size < nums2Size) {
        int *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        int count = nums1Size;
        nums1Size = nums2Size;
        nums2Size = count;
    }

    /* 这个地方没处理好 */
    if (nums2Size == 0) {
        if (nums1Size % 2 == 0) {
            return (nums1[nums1Size / 2] + nums1[(nums1Size / 2) - 1]) / 2.0;
        }
        return nums1[nums1Size / 2];
    }

    while (count < target) {
        left = right;
        if (ptr2 < nums2Size && nums1[ptr1] <= nums2[ptr2]) {
            right = nums1[ptr1];
            ptr1++;
        } else if (ptr2 < nums2Size) {
            right = nums2[ptr2];
            ptr2++;
        } else {
            right = nums1[ptr1];
            ptr1++;
        }
        count++;
    }

    /* 这个地方没处理好 */
    if (all % 2 == 0) {
        left = right;
        if (ptr1 < nums1Size && ptr2 < nums2Size) {
            right = nums1[ptr1] < nums2[ptr2] ? nums1[ptr1] : nums2[ptr2];
        } else if (ptr1 < nums1Size) {
            right = nums1[ptr1];
        } else {
            right = nums2[ptr2];
        }
        return (left + right) / 2.0;
    }
    return right;
}