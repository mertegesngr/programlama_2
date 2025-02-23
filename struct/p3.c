#include <stdio.h>
#include <stdlib.h>
int rt;
int vt; 
struct complex{

int virtual; 
int reel;
};

void complexToplam(struct complex t[]){
rt=t[0].reel+t[1].reel;
vt=t[1].virtual+t[0].virtual;
}
int main (){

    struct complex t[2]; 
    for(int i =0 ; i<2 ; i++){
    printf("sayı %d için sanal kısım(i nin katsayısı):",i+1);
    scanf("%d",&t[i].virtual) ;
    printf("sayı %d için reel kısım:",i+1);
    scanf("%d",&t[i].reel) ;
    }
complexToplam(t); 
printf("girilen sayıların toplamı %d+%di",rt,vt);

    return 0 ; 
}