#include <stdio.h>
int main(){
    int i = 0;
    float a[3] = {1000.0f, 3000.0f, 5000.0f};
    float tong = 0.0f;
    float rpm_max = a[0];
    int canhbao3000 = 0;
    for(i = 0; i < 3; i++){
        printf("Chu ky %d: %.2f RPM\n", i + 1, a[i]);
        tong += a[i];
        if(a[i] > rpm_max){
            rpm_max = a[i];
        }
        if(a[i] > 3000){
            canhbao3000++;
        }
        if(a[i] > 4000){
            printf("Canh bao; RPM qua cao\n");
        }
    }
    printf("Toc do trung binh la %.2f RPM\n", tong/(float)3);
    printf("RPM cao nhat la %.2f RPM\n", rpm_max);
    printf("So lan vuot qua 3000 rpm la %d\n", canhbao3000);
}