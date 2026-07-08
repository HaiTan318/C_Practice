#include<stdio.h>

void in_trang_thai(float *arr, char **ten, int n){
    float nguong = 25.0f;
    int i = 0;

    for(i = 0; i < n; i++){
        if(*(arr + i) < nguong){
            printf("[%s] %.1f PSI CANH BAO: ap suat lop thap\n", *(ten + i), *(arr + i) );
        }else{
            printf("[%s] %.1f PSI - Ap suat lop on dinh\n", *(ten + i), *(arr + i));
        }
    }
}



int main(void){
    float ap_suat[4] = {32.5f, 28.0f, 35.2f, 22.3f}; /*PSI*/
    char *ten_banh[4] = {"Truoc trai", "Truoc phai",
                             "Sau trai", "Sau phai"};
    in_trang_thai(ap_suat, ten_banh, 4);



    return 0;
}