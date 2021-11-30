#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[11];
    char id[11];
    int score;
}student;

int main () {
    int n, max = -1, min = 101, max_index = 0, min_index = 0;
    student* stu;
    scanf("%d", &n);
    stu = (student*)malloc(sizeof(student) * n);
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].score);
        if(stu[i].score > max) {
            max = stu[i].score;
            max_index = i;
        }
        if(stu[i].score < min) {
            min = stu[i].score;
            min_index = i;
        }
    }
    printf("%s %s\n", stu[max_index].name, stu[max_index].id);
    printf("%s %s", stu[min_index].name, stu[min_index].id);
    return 0;
}