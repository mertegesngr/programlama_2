#include <stdio.h>
#include <stdlib.h>


struct saat{
int saat; 
int dakika; 
int saniye; 
};

void hesapla(struct saat s[] ,int *f_saat,int *f_dakika,int *f_saniye){

if(s[0].saat>s[1].saat){

if(s[0].saniye<s[1].saniye){
    s[0].dakika-=1;
    s[0].saniye+=60;
}
*f_saniye=s[0].saniye-s[1].saniye;

if(s[0].dakika<s[1].dakika){
    s[0].saat-=1;
    s[0].dakika+=60;
}
*f_dakika=s[0].dakika-s[1].dakika;

*f_saat=s[0].saat-s[1].saat;
}
else{
    if(s[1].saniye<s[0].saniye){
        s[1].dakika-=1;
        s[1].saniye+=60;
    }
    *f_saniye=s[1].saniye-s[0].saniye;
    
    if(s[1].dakika<s[0].dakika){
        s[1].saat-=1;
        s[1].dakika+=60;
    }
    *f_dakika=s[1].dakika-s[0].dakika;
    
    *f_saat=s[1].saat-s[0].saat;
}



}

int main (){

int f_saat,f_dakika,f_saniye; 

struct saat s[2];

for(int i =0; i<2;i++){
    printf("%d.saat:",i+1);
    scanf("%d",&s[i].saat);
    printf("%d.dakika:",i+1);
    scanf("%d",&s[i].dakika);
    printf("%d.saniye:",i+1);
    scanf("%d",&s[i].saniye);
}
hesapla(s,&f_saat,&f_dakika,&f_saniye);
printf("iki saat arasıındaki fark %d saat %d dakika %d saniye",f_saat,f_dakika,f_saniye);


    return 0 ; 
}