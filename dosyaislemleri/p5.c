#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main (){

FILE *ptr=fopen("p4.txt","r"); 

char adlar[5][20];

for(int i =0; i<5;i++){
    fscanf(ptr,"%s",&adlar[i]);
}
int leng[5]={0};
for(int i =0 ; i<5;i++){
    for (int j =0 ; j<20;j++){
    if(adlar[i][j]=='\0'){
        break;
    }
     leng[i]++;
    }
}
fclose(ptr);
FILE *pc=fopen("p4.txt","w"); 
for(int i=0 ;i<5;i++){
fprintf(pc,"%s -> %d\n",adlar[i],leng[i]);
}

fclose(pc); 


    return 0 ; 
}