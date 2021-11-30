#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main() {
    int k;
    int a[101];
    int hashMap[310]; // 3n+1
    int temp;
    memset(hashMap, 0, sizeof(hashMap));
    scanf("%d", k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
        temp = a[i];
        hashMap[temp]++;
        while (temp > 1) {
            if(temp % 2 == 0) {
                temp = temp / 2;
                hashMap[temp]++;
            } else {
                temp = (3 * temp + 1) / 2;
                hashMap[temp]++;
            }
        }
    }
    int result[310];
    for(int i = 0; i < 310; i++) {
        if(hashMap[i]==1) {
            
        }
    }
    sort(hashMap, hashMap + 310);
    return 0;
}