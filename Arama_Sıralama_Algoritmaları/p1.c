#include <stdio.h>
#include <stdlib.h>

int liner(int dizi[],int N,int w){

    for(int i =0 ; i<N;i++){

        if(w==dizi[i]){
            return i ; 
        }
    }

return -1 ; 
}

int main (){

int N,w; 
printf("dizi boyutu giriniz:"); 
scanf("%d",&N); 
int dizi[N];
for(int i =0 ; i<N;i++){
    printf("%d. sayıyı gir:",i+1);
    scanf("%d",&dizi[i]); 
}
printf("hangi sayıyının indexini istiyorsunuz : "); 
scanf("%d",&w); 
int x =liner(dizi,N,w); 
if(x!=-1){
printf("sayının indexi = %d",liner(dizi,N,w));
}
else{
    printf("sayı dizide yok !!"); 
}
    return 0 ; 
}
