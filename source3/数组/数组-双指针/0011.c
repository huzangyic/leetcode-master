// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 返回容器可以储存的最大水量。

// 说明：你不能倾斜容器。

#define MINN(a,b) (a <= b ? a : b)
#define MAXX(a,b) (a >= b ? a : b)

int maxArea(int* height, int heightSize)
{
    int p = 0;
    int q = heightSize - 1;
    int S = 0;

    while (p != q) {
        S = MAXX(S, (q - p) * MINN(height[p], height[q]));
        if (height[p] <= height[q]) {
            p++;
        } else {
            q--;
        }
    }

    return S;
}