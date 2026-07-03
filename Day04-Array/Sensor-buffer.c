#include <stdio.h>
int main(void){
    int i = 0;
    float nhiet_do[8] = {60.f, 70.f, 75.f, 80.f, 85.f, 90.f, 95.f, 100.f};
    float tong = 0.0f;
    float nhiet_do_max = nhiet_do[0];
    float nhiet_do_min = nhiet_do[0];
    int canh_bao_nhietdo = 0;

    for(i = 0; i < 8; i++){
        printf("Chu ky %d: %.1f do C\n", i + 1, nhiet_do[i]);
        tong += nhiet_do[i];
        if(nhiet_do[i] > nhiet_do_max){
            nhiet_do_max = nhiet_do[i];
        }
        if (nhiet_do[i] < nhiet_do_min){
            nhiet_do_min = nhiet_do[i];
        }
        if(nhiet_do[i] > 85.0f){
            printf("CANH BAO: Chu ky %d: %.1f do C\n", i + 1, nhiet_do[i]);
            canh_bao_nhietdo++;
        }
    }
    printf("Nhiet do trung binh: %.1f do C\n", tong/(float)8);
    printf("Nhiet do cao nhat: %.1f do C\n", nhiet_do_max);
    printf("Nhiet do thap nhat: %.1f do C\n", nhiet_do_min);
    printf("So lan vuot nguong 85 do C: %d lan\n", canh_bao_nhietdo);
    return 0;

}