#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *ptr =fopen("p22.txt","w");

for(int i =0 ;i<8;i++){
    fprintf(ptr,"%d\t%d\t%d\n",i+1,i+2,i+3);
}

fclose(ptr);



return 0;
}