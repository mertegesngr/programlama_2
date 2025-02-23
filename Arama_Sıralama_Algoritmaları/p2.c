#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int dizi[],int N){

for(int i =0 ; i<N;i++){

for(int j =i ;j<N-1;j++ ){

if(dizi[j]>dizi[j+1]){

int gecici=dizi[j]; 
dizi[j]=dizi[j+1]; 
dizi[j+1]=gecici; 

}
}
}

}

void selection_sort(int dizi[],int N){

    
    for(int i =0 ; i<N;i++){
int min_index=i;
for(int j =i+1;j<N;j++){

    if(dizi[j]<dizi[min_index]){
        min_index=j;
    }
}
if(min_index!=i){
int gecici=dizi[i];
dizi[i]=dizi[min_index];
dizi[min_index]=gecici; 
}

}
}
void dizi_yazdir(int dizi[],int n){

    for(int i =0 ; i<n;i++){
        printf("%d ",dizi[i]); 
    }
    
    
    
    }
int main(){


        int N,w; 
        printf("dizi boyutu giriniz:"); 
        scanf("%d",&N); 
        int dizi[N];
        for(int i =0 ; i<N;i++){
            printf("%d. sayıyı gir:",i+1);
            scanf("%d",&dizi[i]); 
        }
        printf("seçmeli için 1 kabarcık için 2 : "); 
        scanf("%d",&w); 
        if(w==2){
            bubble_sort(dizi,N);
            dizi_yazdir(dizi,N);
        }
        else if(w==1){
            selection_sort(dizi,N);
            dizi_yazdir(dizi,N);
        }
      





    return 0 ; 
}