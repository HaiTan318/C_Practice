#include<stdio.h>
float nhiet_do = 86.0f;
float dien_ap = 12.4f;
int rpm = 3200;

typedef struct{
    float nhiet_do;
    float dien_ap;
    int rpm;
    int co_loi; //0 = OK; 1 = loi
} ECU_Sensor_t; //_t la quy uoc automotive
void in_trang_thai(ECU_Sensor_t *s){
    printf("Nhiet do : %.1f do C\n", s->nhiet_do);
    printf("Dien ap : %.1f V\n", s->dien_ap);
    printf("RPM : %d\n", s->rpm);
    printf("Trang thai : %s\n", s->co_loi ? "LOI" : "OK");
}


int main(void){
    ECU_Sensor_t sensor;
    sensor.nhiet_do = 86.0f;
    sensor.dien_ap = 12.4f;
    sensor.rpm = 3200;
    sensor.co_loi = 0;
    
    in_trang_thai(&sensor);
    return 0;
}