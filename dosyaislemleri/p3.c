#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *ptr=fopen("p2.txt","r"); 

int dizi[10][5];

for(int i =0 ;i<10;i++){   // iç dngü sütun dış döngü satır 
    for(int j =0;j<5;j++){
        fscanf(ptr,"%d",&dizi[i][j]);
    }
}
int enB[10]={0};

for(int i =0 ;i<10;i++){
    for(int j =0;j<5;j++){
       if(enB[i]<dizi[i][j]){
        enB[i]=dizi[i][j];
       }
    }
}
fclose(ptr);
FILE *pc=fopen("p2.txt","w");
for(int i =0 ;i<10;i++){
    for(int j =0;j<5;j++){
       fprintf(pc,"%d ",dizi[i][j]);
    }
    fprintf(pc,"%s %d \n","--->satırdaki en büyük sayı:",enB[i]);
}

fclose(pc);
    return 0;
}