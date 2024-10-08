// 大佬的做法，强就强在  block = i / 3 * 3 + j / 3;  这句话得出了矩阵的i,j和3*3块的规律
// i/3 相当于行归一，×3就相当于对应的行下标，j/3就是列归一。 相加就是最终的块位置。
// 看博客里的这张图
https://blog.csdn.net/qq_34269988/article/details/90698946#:~:text=%E5%81%9A%E9%A2%98%E9%81%87%E5%88%B0%E7%9A%84%EF%BC%9A%20L

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    /*配置一个空的哈希表,一共三层，一层用来检测行，一层用来检测列，一层用来检测块*/
    int hashTable[3][9][9] = {0}; // ？ 这样能初始化成0？？
    int block , i , j , num;
    for(i = 0;i < 9;i++){
        for(j = 0;j < 9;j++){
            if(board[i][j] == '.')
                continue;
            else{
                /*为了匹配hash的数组坐标为0-8，数独里的字符为1-9，此处-1*/
                num = (int)(board[i][j] - '1');
                /*判断是在哪儿一块*/
                block = i / 3 * 3 + j / 3;
                /*判断该数字是否在同一行一列或者一个块中出现过，如果出现过则数独无效*/
                if(hashTable[0][i][num] == 1 || hashTable[1][j][num] == 1 || hashTable[2][block][num] == 1)
                    return false;

                /*如果上述数字没有在行列以及块中出现过，则标记为1，意思出现了1次*/
                hashTable[0][i][num] = 1;
                hashTable[1][j][num] = 1;
                hashTable[2][block][num] = 1;   
            }         
        }
    }
    return true;
}


// 我的做法
int hash_row[9][9];
int hash_col[9][9];
int hash_3x3[9][9];

bool judge_row(int row, int col, int target)
{
    if (hash_row[row][target - 1] == 0) {
        hash_row[row][target - 1] = 1;
        return false;
    }

    return true;
}

bool judge_col(int row, int col, int target)
{
    if (hash_col[col][target - 1] == 0) {
        hash_col[col][target - 1] = 1;
        return false;
    }

    return true;
}

bool judge_3x3(int row, int col, int target)
{
    int index = -1;
    if (row <=2 && col <= 2) {
        index = 0;
    } else if (row <=2 && col <= 5) {
        index = 1;
    } else if (row <=2 && col <= 8) {
        index = 2;
    } else if (row <=5 && col <= 2) {
        index = 3;
    } else if (row <=5 && col <= 5) {
        index = 4;
    } else if (row <=5 && col <= 8) {
        index = 5;
    } else if (row <=8 && col <= 2) {
        index = 6;
    } else if (row <=8 && col <= 5) {
        index = 7;
    } else if (row <=8 && col <= 8) {
        index = 8;
    }

    if (hash_3x3[index][target - 1] == 0) {
        hash_3x3[index][target - 1] = 1;
        return false;
    }

    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    memset(hash_row, 0, sizeof(int) * 9 * 9);
    memset(hash_col, 0, sizeof(int) * 9 * 9);
    memset(hash_3x3, 0, sizeof(int) * 9 * 9);

    for (int row = 0; row <= 8; row++) {
        for (int col = 0; col <= 8; col++) {
            int val = board[row][col] - '0';

            if (val >= 1 && val <= 9) {
                if (judge_row(row, col, val) || judge_col(row, col, val) || judge_3x3(row, col, val)) {
                    return false;
                }
            }
        }
    }

    return true;
}