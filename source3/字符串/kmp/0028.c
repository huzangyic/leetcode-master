// 朴素做法，KMP做法不会
int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);

    if (len2 > len1) {
        return -1;
    }

    for (int i = 0; i < len1 - len2 + 1; i++) {
        if (haystack[i] != needle[0]) {
            continue;
        }
        int j = i;
        for (; j < i + len2; j++) {
            if (haystack[j] != needle[j - i]) {
                break;
            }
        }
        if (j == (i + len2)) {
            return i;
        }
    }
    return -1;
}