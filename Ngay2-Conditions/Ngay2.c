#include <stdio.h>
int main(void) {
    float diem = 8.0f;
    if (diem >= 8.0f){
        printf("Gioi\n");
    }
    else if (diem >= 6.5f){
        printf("Kha\n");
    }
    else if (diem >= 5.0f){
        printf("Trung binh\n");
    }
    else if (diem >= 4.0f){
        printf("Yeu\n");
    }
    else{
        printf ("Hoc lai\n");
    }
    return 0;
}