#include <stdio.h>
#include <stdlib.h>

int main() {

 FILE *ptr=fopen("p.txt","w");

 int dizi[5];

 for (int i =0 ; i<5;i++){
 printf("%d. sayı gir:",i+1);
 scanf("%d",&dizi[i]);
 }

for(int i =0 ; i<5;i++){
    fprintf(ptr,"%d\n",dizi[i]); 
}
fclose(ptr); 
    return 0;
}