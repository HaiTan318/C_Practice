#include<stdio.h>
#include<string.h>

typedef struct {
    char ten[20];
    float nguong;
    int (*kiem_tra)(float gia_tri, float nguong);
} CanhBao_t;

int kiem_tra_qua_nong(float gia_tri, float nguong){
    if(gia_tri > nguong){
        printf("Canh bao qua nguong\n");
        return 1;
    }else{
        printf("He thong binh thuong\n");
        return 0;
    }
}

int kiem_tra_qua_thap(float gia_tri, float nguong){
    if(gia_tri < nguong){
        printf("Canh bao qua thap\n");
        return 1;
    }else{
        printf("He thong binh thuong\n");
        return 0;
    }
}

int main(void){
    CanhBao_t cam_bien_nhiet;
    strcpy(cam_bien_nhiet.ten, "cb_nhiet");
    cam_bien_nhiet.nguong = 120.0f;
    cam_bien_nhiet.kiem_tra = kiem_tra_qua_nong; //Dang goi ham kiem tra qua nong

    if(cam_bien_nhiet.kiem_tra != NULL){ //NULL: 0x0000: Dia chi bat dau cua thanh ram
//Neu bang NULL thi khong the hoat dong chuong trinh
    
    cam_bien_nhiet.kiem_tra(80.0f, cam_bien_nhiet.nguong);
    }

    return 0;
}