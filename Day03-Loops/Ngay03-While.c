#include <stdio.h>
int main(void){
    int dem = 10;

    printf("ECU dang khoi dong...\n");
    while (dem >= 0){
        printf("T-%d\n", dem);
        dem-- ;
    }
    printf("ECU san sang!\n");
    return 0;
}