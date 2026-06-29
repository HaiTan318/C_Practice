#include <stdio.h>

int main(){
    int tuoi = 22;
    float gpa = 3.1f;
    char ten = 'T';
    float chieu_cao = 1.75f;

    printf("Ten: %c\n", ten);
    printf("Tuoi: %d\n", tuoi);
    printf("GPA: %.2f\n", gpa);
    printf("Chieu cao: %.2f\n", chieu_cao);
    printf("Ten: %c - Tuoi: %d - GPA: %.2f", ten, tuoi, gpa);

    return 0;
}