// 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

// 注意：如果对空文本输入退格字符，文本继续为空。
// 示例 1：

// 输入：s = "ab#c", t = "ad#c"
// 输出：true
// 解释：s 和 t 都会变成 "ac"。
// 示例 2：

// 输入：s = "ab##", t = "c#d#"
// 输出：true
// 解释：s 和 t 都会变成 ""。
// 示例 3：

// 输入：s = "a#c", t = "b"
// 输出：false
// 解释：s 会变成 "c"，但 t 仍然是 "b"。
 

// 提示：

// 1 <= s.length, t.length <= 200
// s 和 t 只含有小写字母以及字符 '#'

int dealbackspace(char* str)
{
    int slow = 0;
    int size = strlen(str);

    for(int fast = 0; fast < size; fast++) {
        if (str[fast] == '#') {
            if (slow > 0)
                slow--;
        } else {
            str[slow++] = str[fast];
        }
    }

    return slow;
}

bool backspaceCompare(char* s, char* t) {
    int lens = dealbackspace(s);
    int lent = dealbackspace(t);

    if (lens != lent) {
        return false;
    }

    for (int i = 0; i < lens; i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }

    return true;
}