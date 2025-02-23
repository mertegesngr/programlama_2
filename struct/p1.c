#include <stdio.h>
#include <stdlib.h>

struct kenar{
int uzun ;
int kısa;
};

int hesapla(struct kenar k)
{
    return k.kısa*k.uzun;
}

int main(){


struct kenar k ; 

printf("kısa kenar gir : "); 
scanf("%d",&k.kısa);
printf("uzun kenar gir : "); 
scanf("%d",&k.uzun);

printf("alan = %d",hesapla(k));
    return 0 ; 
}