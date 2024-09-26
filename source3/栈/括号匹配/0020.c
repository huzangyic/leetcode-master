// (([])[{}])

#define LENGTH 7001

char left_sym[3] = {'(', '{', '['};
char right_sym[3] = {')', '}', ']'};

bool ele_in_syms(char c, char *syms)
{
    return (c == syms[0]) || (c == syms[1]) || (c == syms[2]);
}

bool isValid(char* s)
{
    int len = strlen(s);
    char stack[LENGTH] = {'\0'};
    int top = -1;
    int index = 0;

    if (ele_in_syms(s[0], right_sym)) {
        return false;
    }

    while (index < len) {
        if (top == -1 && ele_in_syms(s[index], right_sym)) {
            return false;
        }

        if (ele_in_syms(s[index], left_sym)) {
            stack[++top] = s[index];
        } else {
            if ((stack[top] == left_sym[0] && s[index] != right_sym[0]) ||
                (stack[top] == left_sym[1] && s[index] != right_sym[1]) ||
                (stack[top] == left_sym[2] && s[index] != right_sym[2])) {
                return false;
            } else {
                top--;
            }
        }

        index++;
    }

    return top == -1 ? true : false;
}