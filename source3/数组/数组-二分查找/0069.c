// 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

// 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

// 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

// 示例 1：

// 输入：x = 4
// 输出：2
// 示例 2：

// 输入：x = 8
// 输出：2
// 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。 

// 提示：

// 0 <= x <= 231 - 1

// 牛顿迭代


// 理解平方的数学思想
int mySqrt(int x) {
    long int i = 0;
    for(i=0;;i++){
        long int a = i*i;
        long int b = (i+1)*(i+1);
        if(a <= x&&b > x){
            break;
        }
    }
        return i;
}

// 二分法-自己写
int mySqrt(int x)
{
    int left = 0, right = x;
    int mid = 0; /* if x == 0 */
    while (left < right) {
        printf("left: %d, right: %d, mid: %d", left, right, mid);
        mid = (left + right) / 2;
        if (mid * mid > x) {
            right = mid -1;
        } else if (mid * mid < x) {
            if ((mid + 1) * (mid + 1) > x)
                break;
            else
                left = mid + 1;
        } else if (mid * mid == x) {
            break;
        }
    }

    return mid;
}

//  二分法--网友写，更优
int mySqrt(int x){
    long long left,right;
    left=1;right=x/2;
    long long mid;
    if(x==1){
        return 1;
    }
    while(left<=right){
        mid=(left+right)/2;
        if(mid*mid==x){
            return mid;
        }
        else if(mid*mid<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return left-1;
}
