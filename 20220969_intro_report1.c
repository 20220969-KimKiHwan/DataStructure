#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENT_SCORE 10

int main() {
    int scores[STUDENT_SCORE];  
    int sum = 0;               
    double average;            

    srand(time(NULL));
   
    for (int i = 0; i < STUDENT_SCORE; i++) {
        scores[i] = rand() % 101;  
        sum += scores[i];
    }

    average = (double)sum / STUDENT_SCORE;

    printf("학생 성적 목록:\n");
    
    for (int i = 0; i < STUDENT_SCORE; i++) {
        printf("학생 %d: %d점\n", i + 1, scores[i]);
    }

    printf("\n총합: %d\n", sum);
    printf("평균: %.2f\n", average);

    return 0;
}