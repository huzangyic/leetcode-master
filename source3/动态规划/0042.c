// https://leetcode.cn/problems/trapping-rain-water/description/

#define MINN(a,b) (a <= b ? a : b)
#define MAXX(a,b) (a >= b ? a : b)

int trap(int* height, int heightSize)
{
    // 对于第i个“台阶”，记录其左边最高的“台阶”
    int *aux_left_max = (int *)malloc(sizeof(int) * heightSize);
    // 对于第i个“台阶”，记录其右边最高的“台阶”
    int *aux_right_max = (int *)malloc(sizeof(int) * heightSize);

    // 开头和末尾的两侧都是0
    aux_left_max[0] = 0;
    aux_right_max[heightSize - 1] = 0;

    // 构造备忘录
    for (int i = 1; i < heightSize; i++) {
        aux_left_max[i] = MAXX(aux_left_max[i - 1], height[i - 1]);
    }

    for (int i = heightSize - 2; i >= 0; i--) {
        aux_right_max[i] = MAXX(aux_right_max[i + 1], height[i + 1]);
    }

    // for (int i = 0; i < heightSize; i++) {
    //     printf("aux_right_max[%d] is %d\n", i, aux_right_max[i]);
    // }

    // 对于第i个“台阶”。所能接住的雨水量为 min(left_max, right_max) - height(i)
    int ans = 0;
    for (int i = 0; i < heightSize; i++) {
        if (height[i] < aux_left_max[i] && height[i] < aux_right_max[i]) {
            // printf("i is %d, add is %d\n", i, (MINN(aux_left_max[i], aux_right_max[i]) - height[i]));
            ans += (MINN(aux_left_max[i], aux_right_max[i]) - height[i]);
        }
    }

    free(aux_left_max);
    free(aux_right_max);

    return ans;
}