#include <stdio.h>
int main(void){
    float nhiet_do[6] = {72.0f, 78.0f, 86.0f,
                        91.0f, 83.0f, 79.0f};
    float dien_ap[6] = {12.6f, 12.4f, 11.3f,
                        11.0f, 12.1f, 12.5f};
    int rpm[6] = {800, 1500, 3200, 
                    4500, 2800, 1200};
    float nhiet_do_tb = 0.0f;
    float dien_ap_tb = 0.0f;
    float rpm_tb = 0.0f;
    int so_canh_bao = 0;
    float nhiet_do_max = nhiet_do[0];
    float nhiet_do_min = nhiet_do[0];
    float dien_ap_max = dien_ap[0];
    float dien_ap_min = dien_ap[0];
    float rpm_max = rpm[0];
    float rpm_min = rpm[0];

    for(int i = 0; i < 6; i++){
        printf("[Chu ky %d] Nhiet do: %.2f do C | Dien ap: %.2f | RPM: %d\n ", i + 1, nhiet_do[i], dien_ap[i], rpm[i]);
            
        nhiet_do_tb += nhiet_do[i];
        dien_ap_tb += dien_ap[i];
        rpm_tb += rpm[i];

        if(nhiet_do[i] > nhiet_do_max){
            nhiet_do_max = nhiet_do[i];
        }
        if(nhiet_do[i] < nhiet_do_min ){
            nhiet_do_min = nhiet_do[i];
        }
        if(dien_ap[i] > dien_ap_max){
            dien_ap_max = dien_ap[i];
        }
        if(dien_ap[i] < dien_ap_min){
            dien_ap_min = dien_ap[i];
        }
        if(rpm[i] > rpm_max){
            rpm_max = rpm[i];
        }
        if(rpm[i] < rpm_min){
            rpm_min = rpm[i];
        }

        if(nhiet_do[i] > 85.8f){
            printf("CANH BAO: Qua nhiet!\n");
        }
        if(dien_ap[i] < 11.5f){
            printf(" >> CANH BAO: Ac quy yeu!\n");
        }
        if(rpm[i] > 4000){
            printf(" >> CANH BAO: RPM cao!\n");
        }
    }
    printf(" --- Thong ke ---\n ");
    printf("Nhiet do: TB:  %.2f do C | Max: %.2f | Min: %.2f\n", nhiet_do_tb / (float)6, nhiet_do_max, nhiet_do_min);
    printf("Dien ap: TB: %.2f | Max: %.2f | Min: %.2f\n", dien_ap_tb /(float)6, dien_ap_max, dien_ap_min);
    printf("RPM: TB: %.2f | Max: %.2f | Min: %.2f\n", rpm_tb, dien_ap_max, dien_ap_min);
    return 0;
}