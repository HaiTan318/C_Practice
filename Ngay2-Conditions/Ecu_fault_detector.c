#include <stdio.h>
int main(){
    float nhiet_do = 95.0f;
    float dien_ap = 11.2f;
    int den_pha = 0;
    int coloi = 0;

    if(nhiet_do > 90){
        printf("LOI: Qua nhiet dong co\n");
        coloi = 1;
    }
    if(dien_ap < 11.5){
        printf("LOI: Ac quy yeu\n");
        coloi = 1;
    }
    if(den_pha == 0){
        printf("CANH BAO: Den pha bi hong\n");
        coloi = 1;
    }
    if(coloi == 0){
        printf("He thong binh thuong\n");
    }
    return 0;
}