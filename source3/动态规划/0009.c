// 9. 回文数
// 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

// 回文数
// 是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 例如，121 是回文，而 123 不是。
 

// 示例 1：

// 输入：x = 121
// 输出：true
// 示例 2：

// 输入：x = -121
// 输出：false
// 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 示例 3：

// 输入：x = 10
// 输出：false
// 解释：从右向左读, 为 01 。因此它不是一个回文数。
 

// 提示：

// -231 <= x <= 231 - 1

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    if (x < 9) {
        return true;
    }
    long int tmp = 0;
    int calc = x;
    while (calc) {
        int part_calc = calc % 10;
        //  这里有个坑，就是反转的数字可能会溢出
        tmp = tmp * 10 + part_calc;
        calc = calc / 10;
    }

    return tmp == x;
}