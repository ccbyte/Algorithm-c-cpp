#include<stdio.h>
#include<string.h>

int main() {
    int num = 0;
    char numString[100];
    char chineseNum[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    scanf("%s", &numString);
    for(int i = 0; i < strlen(numString); i++) {
        num += (int)(numString[i] - '0'); // 字符转数字（为了累加计数）
    }
    char result[100];
    sprintf(result, "%d", num); // 数字转字符 (为了从高位到低位输出int)
    for(int i = 0; i < strlen(result); i++) {
        int a = (int)(result[i] - '0'); // 字符转数字（为了数字作为下标找到拼音）
        printf("%s", chineseNum[a]);
        if(i != strlen(result) - 1) printf(" ");
    }
    return 0;
}