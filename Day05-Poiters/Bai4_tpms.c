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
void tim_banh_thap_nhat(float *arr, char **ten, int n,
                             float *ap_suat_min, int *vi_tri)
{
    int i = 0;
    *ap_suat_min = arr[i];
    *vi_tri = 0;
    for(i = 0; i < n; i++){
        if(*(arr + i) < *ap_suat_min){
            *ap_suat_min = *(arr + i);
            *vi_tri = i;
        }
    }
}


int main(void){
    float ap_suat_min = 0.0f;
    int vi_tri = 0;
    
    float ap_suat[4] = {32.5f, 28.0f, 35.2f, 22.3f}; /*PSI*/
    char *ten_banh[4] = {"Truoc trai", "Truoc phai",
                             "Sau trai", "Sau phai"};
    in_trang_thai(ap_suat, ten_banh, 4);

        tim_banh_thap_nhat(ap_suat, ten_banh, 4, &ap_suat_min, &vi_tri);
        printf("Ap suat thap nhat: %s - %.1f PSI\n", ten_banh[vi_tri], ap_suat_min);

    return 0;
}