#include <stdio.h>
#include <stdlib.h>

void selection_sort(int dizi[],int n){

for(int i =0 ;i<n;i++){

int min_index=i;
for(int j=i+1;j<n;j++){
    if(dizi[j]<dizi[min_index]){
    min_index =j ; 
    }
}
 if(min_index != i)
    {
        int temp = dizi[i];
        dizi[i] = dizi[min_index];
       dizi[min_index] = temp;
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
selection_sort(dizi,5); 
dizi_yazdir(dizi,5); 






    return 0 ; 
}