#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
srand(time(NULL)); 
int dizi[10][5];
for(int i=0; i<10;i++){
for(int j =0 ;j<5;j++){
    dizi[i][j]=rand()%101; 
}
}
FILE *ptr=fopen("p2.txt","w");


for(int i=0; i<10;i++){
    for(int j =0 ;j<5;j++){
       fprintf(ptr,"%d ",dizi[i][j]);
    }
    fprintf(ptr,"\n");
    }


    return 0;
}