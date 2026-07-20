#include<stdio.h>
#include<string.h>

typedef void(*Handler_t)(float data);

typedef struct 

{
    int ma_lenh; /*CAN messenger ID*/       
    char ten[20];
    Handler_t xu_ly;    /*Funtion poiter toi ham xu ly*/
}Lenh_t;

void xu_ly_nhiet_do(float data){
    float nguong = 200.0f;

    if(data > nguong){
        printf("Nhiet do Vuot nguong\n");
    }else{
        printf("Nhiet do Binh thuong\n");
    }
}
void xu_ly_toc_do(float data){
    float nguong = 60.0f;

    if(data > nguong){
        printf("Toc do vuot qua\n");
    }else{
        printf("Toc do Binh thuong\n");
    }
}
void xu_ly_dien_ap(float data){
    float nguong = 500.0f;

    if(data > nguong){
        printf("Dien ap vuot nguong\n");
    }else{
        printf("Dien ap Binh thuong\n");
    }
}
void xu_ly_lenh(Lenh_t *bang, int n, int ma, float data){
    int i = 0;
    for(i = 0; i < n; i++){
        if(ma == bang[i].ma_lenh){
            if(bang[i].xu_ly != NULL){
                bang[i].xu_ly(data);
            }
            return;
        }
    }printf("Khong tim thay ma\n");
}
int main(void){
    Lenh_t cam_bien_nhiet;
    strcpy(cam_bien_nhiet.ten, "cb_nhiet");
    cam_bien_nhiet.ma_lenh = 100;
    cam_bien_nhiet.xu_ly = xu_ly_nhiet_do;

    if(cam_bien_nhiet.xu_ly != NULL){
            cam_bien_nhiet.xu_ly(150.0f);
    }

    Lenh_t cam_bien_toc_do;
    strcpy(cam_bien_toc_do.ten, "cb_toc_do");
    cam_bien_toc_do.ma_lenh = 200;
    cam_bien_toc_do.xu_ly = xu_ly_toc_do;

    if(cam_bien_toc_do.xu_ly != NULL){
        cam_bien_toc_do.xu_ly(90.0f);
    }

    Lenh_t cam_bien_dien_ap;
    strcpy(cam_bien_dien_ap.ten, "cb_dien_ap");
    cam_bien_dien_ap.ma_lenh = 300;
    cam_bien_dien_ap.xu_ly = xu_ly_dien_ap;   

    if(cam_bien_dien_ap.xu_ly != NULL){
        cam_bien_dien_ap.xu_ly(220.0);
    }

    Lenh_t bang_lenh[3] = {
        {100, "cb_nhiet", xu_ly_nhiet_do},
        {200, "cb_toc_do", xu_ly_toc_do},
        {300, "cb_dien_ap", xu_ly_dien_ap}
    };

    xu_ly_lenh(bang_lenh, 3, 100, 500.0f);
     xu_ly_lenh(bang_lenh, 3, 200, 70.0f);
      xu_ly_lenh(bang_lenh, 3, 300, 600.0f); 
      xu_ly_lenh(bang_lenh, 3, 400, 200.0f);

    return 0;
}