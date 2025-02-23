#include <stdio.h>
#include <stdlib.h>

int main() {
FILE *ptr=fopen("teksayilar.txt","w");
FILE *p=fopen("ciftsayilar.txt","w");
FILE *pr=fopen("p2.txt","r");
int sayilar[50];

for(int i =0;i<50;i++){
    fscanf(pr,"%d",&sayilar[i]);
}

for(int i =0;i<50;i++){
    if(sayilar[i]%2==0)
    fprintf(p,"%d ",sayilar[i]);
    else{
        fprintf(ptr,"%d ",sayilar[i]);
    }
}
fclose(ptr);
fclose(pr);
fclose(p);
printf("işlem başarılı!!");

    return 0;
}