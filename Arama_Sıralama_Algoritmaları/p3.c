#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int dizi[],int N){

for(int i =0 ; i<N;i++){

for(int j =0 ;j<N-1-i;j++ ){

if(dizi[j]>dizi[j+1]){

int gecici=dizi[j]; 
dizi[j]=dizi[j+1]; 
dizi[j+1]=gecici; 

}
}
}
}

void dizi_yazdir(int dizi[],int n){

    for(int i =0 ; i<n;i++){
        printf("%d ",dizi[i]); 
    }    
}

int binary_search(int dizi[],int N,int W){


int sol=0;
int sag=N-1;
while(sol<=sag){
    int orta=sol+(sag-sol)/2;
    if(W>dizi[orta]){
        sol=orta+1;
    }
    else if(W<dizi[orta]){
        sag=orta-1;
    }
    if(W==dizi[orta]){
        return orta ; 
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
bubble_sort(dizi,N);
printf("dizinin sıralanmış hali:");
dizi_yazdir(dizi,N);
printf("\n"); 

int x =binary_search(dizi,N,w); 

if(x!=-1){
printf("sayının indexi = %d",x);
}
else{
    printf("sayı dizide yok !!"); 
}



    return 0 ; 
}