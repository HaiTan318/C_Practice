#include<stdio.h>
#include<string.h>
#define theo_doi_size 5
typedef struct{
    int id;
    char    ten[20];
    float   dien_ap;    /*Volt*/
    float   nhiet_do;   /*do C*/
    int     trang_thai; /*0 = Off, 1 = On, 2 = Loi*/
    void (*kiem_tra)(void*self);

}Pin_t;

void khoi_tao_pin(Pin_t *p, int id, char *ten, float dien_ap, 
    float nhiet_do, int trang_thai, void (*kiem_tra)(void *self)){
        p->id;
        strcpy(p->ten, ten);
        p->dien_ap = dien_ap;
        p->nhiet_do = nhiet_do;
        p->trang_thai = trang_thai;
        p->kiem_tra = kiem_tra;
    }

void kiem_tra_pin_a(void *self){
    Pin_t *p = (Pin_t *)self;

    if(p->dien_ap < 3.0f){
        printf("CANH BAO: Dien ap thap\n");
    }else{
        printf("Dien ap binh thuong\n");
    }

    if(p->nhiet_do > 80.0f){
        printf("CANH BAO: Qua nhiet\n");
    }else{
        printf("Nhiet do binh thuong\n");
    }

    if(p->trang_thai == 2){
        printf("CANH BAO: Loi pin\n");
    }else if(p->trang_thai == 0){
        printf("Pin OFF\n");
    }else{
        printf("Pin ON\n");
    }
}
void kiem_tra_pin_b(void *self){
    Pin_t *p = (Pin_t *)self;

    if(p->dien_ap < 3.0f){
        printf("CANH BAO: Dien ap thap\n");
    }else{
        printf("Dien ap binh thuong\n");
    }

    if(p->nhiet_do > 80.0f){
        printf("CANH BAO: Qua nhiet\n");
    }else{
        printf("Nhiet do binh thuong\n");
    }

    if(p->trang_thai == 2){
        printf("CANH BAO: Loi pin\n");
    }else if(p->trang_thai == 0){
        printf("Pin OFF\n");
    }else{
        printf("Pin ON\n");
    }
}
void kiem_tra_pin_c(void *self){
    Pin_t *p = (Pin_t *)self;

    if(p->dien_ap < 3.0f){
        printf("CANH BAO: Dien ap thap\n");
    }else{
        printf("Dien ap binh thuong\n");
    }

    if(p->nhiet_do > 80.0f){
        printf("CANH BAO: Qua nhiet\n");
    }else{
        printf("Nhiet do binh thuong\n");
    }

    if(p->trang_thai == 2){
        printf("CANH BAO: Loi pin\n");
    }else if(p->trang_thai == 0){
        printf("Pin OFF\n");
    }else{
        printf("Pin ON\n");
    }
}

void kiem_tra_pin_d(void *self){
    Pin_t *p = (Pin_t *)self;

    if(p->dien_ap < 3.0f){
        printf("CANH BAO: Dien ap thap\n");
    }else{
        printf("Dien ap binh thuong\n");
    }

    if(p->nhiet_do > 80.0f){
        printf("CANH BAO: Qua nhiet\n");
    }else{
        printf("Nhiet do binh thuong\n");
    }

    if(p->trang_thai == 2){
        printf("CANH BAO: Loi pin\n");
    }else if(p->trang_thai == 0){
        printf("Pin OFF\n");
    }else{
        printf("Pin ON\n");
    }
}

void quet_he_thong(Pin_t *arr, int n){
    int i = 0;

    for(i = 0; i < n; i++){
        if(arr[i].kiem_tra != NULL){
            arr[i].kiem_tra(&arr[i]);
        }
    }
}

void thong_ke(Pin_t *arr, int n, int *so_pin_on, int *so_pin_loi,
                float *dien_ap_tb, float *nhiet_do_tb){

    *so_pin_on = 0;
    *so_pin_loi = 0;
    *dien_ap_tb = 0.0f;
    *nhiet_do_tb = 0.0f;
    float   tong_nhiet_do = 0.0f;
    float   tong_dien_ap = 0.0f;
    
    int i = 0;
    for(i = 0; i < n; i++){
        if(arr[i].trang_thai == 1){
            (*so_pin_on)++;
        }else if(arr[i].trang_thai == 2){
            (*so_pin_loi)++;
        }
        tong_dien_ap = tong_dien_ap + arr[i].dien_ap;
        tong_nhiet_do = tong_nhiet_do + arr[i].nhiet_do;
    }
    *dien_ap_tb = tong_dien_ap / (float)n;
    *nhiet_do_tb = tong_nhiet_do / (float)n;
}
Pin_t *tim_pin_nong_nhat(Pin_t *arr, int n){

    int i = 0;
    Pin_t *max = &arr[0];

    for(i = 0; i < n; i++){
        if(arr[i].nhiet_do > max->nhiet_do){
            max = &arr[i];
        }
    }
    return max;
}

int main(void){

    float theo_doi_nhiet[theo_doi_size] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    float theo_doi_dien[theo_doi_size] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    int lan_theo_doi = 0;

    int i = 0;
    int pin_on = 0;
    int pin_loi = 0;
    float dien_tb = 0.0f;
    float nhiet_tb = 0.0f;


    Pin_t data_pin[4];

    khoi_tao_pin(&data_pin[0], 1, "Pin_A", 3.7f, 35.0f, 1, kiem_tra_pin_a);
    khoi_tao_pin(&data_pin[1], 2, "Pin_B", 2.8f, 82.0f, 1, kiem_tra_pin_b);
    khoi_tao_pin(&data_pin[2], 3, "Pin_C", 3.9f, 45.0f, 1, kiem_tra_pin_c);
    khoi_tao_pin(&data_pin[3], 4, "Pin_D", 3.5f, 91.0f, 1, kiem_tra_pin_d);

    /*Lan 1*/
    quet_he_thong(data_pin, 4);
    thong_ke(data_pin, 4, &pin_on, &pin_loi, &dien_tb, &nhiet_tb);

    printf("So pin ON: %d\n", pin_on);
    printf("So pin LOI: %d\n", pin_loi);
    printf("Dien ap trung binh: %.1f V\n", dien_tb);
    printf("Nhiet do trung binh: %.1f do C\n", nhiet_tb);

    Pin_t *pin_nong = tim_pin_nong_nhat(data_pin, 4);
    printf("Pin nong nhat: pin %s - Nhiet do: %.1f\n", pin_nong->ten, pin_nong->nhiet_do);

    /*Cap nhat gia tri lan 1*/
    theo_doi_dien[theo_doi_size] = dien_tb;
    theo_doi_nhiet[theo_doi_size] = nhiet_tb;
    lan_theo_doi = (lan_theo_doi + 1) % theo_doi_size;

    /*Lan 2*/
    /*Nap du lieu*/
    data_pin[1].nhiet_do = 95.0f;
    data_pin[3].dien_ap = 2.5f;

    /*Quet lan 2*/
    printf("\n=== Quet lan 2 ===\n");
    quet_he_thong(data_pin, 4);
    thong_ke(data_pin, 4, &pin_on, &pin_loi, &dien_tb, &nhiet_tb);

    /*In lan 2*/
    printf("So pin ON: %d\n", pin_on);
    printf("So pin LOI: %d\n", pin_loi);
    printf("Dien ap trung binh: %.1f V\n", dien_tb);
    printf("Nhiet do trung binh: %.1f do C\n", nhiet_tb);

    /*Cap nhat gia tri lan 2*/
    theo_doi_dien[theo_doi_size] = dien_tb;
    theo_doi_nhiet[theo_doi_size] = nhiet_tb;
    lan_theo_doi = (lan_theo_doi + 1) % theo_doi_size;

    /*In theo doi nhiet*/
    printf("\n=== LOG NHIET DO TB ===\n");
    for ( i = 0; i < theo_doi_size; i++) {
        if (theo_doi_nhiet[i] < 0.0f) {
            printf("[%d]: %.2f do C\n", i, theo_doi_nhiet[i]);
            } else {
                printf("[%d]: ---\n", i);
            }
    }

    Pin_t *pin_nong_2 = tim_pin_nong_nhat(data_pin, 4);
    printf("Pin nong nhat: pin %s - Nhiet do: %.1f\n", pin_nong_2->ten, pin_nong_2->nhiet_do);





    return 0;
}