#include <stdio.h>
#include <stdlib.h>


void buble_sort(int dizi[],int n){


for(int i =0 ; i<n;i++){
    for(int j =0;j<n-1-i;j++){
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

int main (){


int dizi[5]={47,63,23,59,45};
buble_sort(dizi,5); 
dizi_yazdir(dizi,5); 






    return 0 ; 
}