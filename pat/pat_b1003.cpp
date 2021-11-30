#include<stdio.h>
#include<string.h>

int main() {
    int n;
    int p = (int)('P'), a = (int)('A'), t = (int)('T'); // ascii码作为hash表的下标
    int x = 0, y = 0, z = 0; // 计数三个部分的A出现次数（P和T把字符串分开三部分）
    int hashMap[128]; // 记录某个字符是否出现过0 1
    char str[10][101]; // 存放n个字符串
    memset(str, '\0', sizeof(str));
    scanf("%d", &n);
    getchar(); // 读掉换行否则被gets带走
    for(int i = 0; i < n; i++) { // 读字符串
        gets(str[i]);
    }
    int flag = 1; // 记录结果
    for(int i = 0; i < n; i++) {
        memset(hashMap, 0, sizeof(int) * 128); // 重置计数
        x = 0, y = 0, z = 0;
        flag = 1;
        for(int j = 0; j < strlen(str[i]); j++) {
            if(str[i][j] == 'A') {
                if(hashMap[p] == 0) x++;
                if(hashMap[p] == 1 && hashMap[t]==0) {
                    hashMap[a] = 1;
                    y++;
                }
                if(hashMap[p] == 1 && hashMap[a] == 1 && hashMap[t] == 1) z++;
            } else if(str[i][j] == 'P') {
                if(hashMap[p] == 0) hashMap[p] = 1;
                else {
                    flag = 0; // P重复后面不看了
                    break;
                }
            } else if(str[i][j] == 'T' && hashMap[p] == 1 && hashMap[a] == 1) {
                if(hashMap[t] == 0) hashMap[t] = 1;
                else {
                    flag = 0; // T重复后面不看了
                    break;
                }
            } else {
                flag = 0; // 非PAT字符后面不看了
                break;
            }
        }
        // printf("%d %d %d\n%d %d %d\n", hashMap[p], hashMap[a], hashMap[t], x, y, z);
        if(flag && hashMap[p] == 1 && hashMap[a] == 1 && hashMap[t] == 1 && x * y == z) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    // printf("%d\n", __STDC__);
    // printf("%ld\n",__STDC_VERSION__);
    return 0;
}