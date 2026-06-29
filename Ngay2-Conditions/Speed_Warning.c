#include <stdio.h>

int main(){
    float speed = 95.0f;
    int troi_mua = 1;
    if (speed <= 60){
        printf("An toan\n");
    }
    else if (speed >= 60 && speed <= 90){
        printf("Canh Bao: Giam toc");
    }

    else{
        printf("NGUY HIEM: vuot qua toc do\n");

    if (troi_mua){
        printf("Nguy co truot banh\n");
    }}
    return 0;
}