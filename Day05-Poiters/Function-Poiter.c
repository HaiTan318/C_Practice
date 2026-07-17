#include<stdio.h>

int cong(int a, int b) {return a + b;}
int tru(int a, int b) {return a - b;}
int nhan(int a, int b) {return a * b;}


void thuc_thi_tinh_toan(int x, int y, int (*p_thuat_toan)(int, int)){
    printf("Chuan bi chay phep tinh...\n");

    int kq = p_thuat_toan(x,y);

    printf("Ket qua cuoi cung la: %d\n", kq);
}
int main(void){
    int lua_chon_nguoi_dung;
    printf("Nhap lua chon cua ban (1: Cong, 2: Tru, 3: Nhan): ");
    scanf("%d", &lua_chon_nguoi_dung);

    if(lua_chon_nguoi_dung == 1){
        thuc_thi_tinh_toan(10, 3, cong); //Truyen ham cong vao
    }else if(lua_chon_nguoi_dung == 2){
        thuc_thi_tinh_toan(10, 3, tru); //Truyen ham tru vao
    }else{
        thuc_thi_tinh_toan(10, 3, nhan); //Truyen ham nhan vao
    }
}