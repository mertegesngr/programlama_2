#include <stdio.h>
#include <stdlib.h>

struct student
{
    int no ; 
    int vize ; 
    int final ; 
    
};

float hesapla (struct student k[]){
float ort =0 ; 

for (int i =0 ; i<3 ; i++){

ort+=((float)k[i].final*0.6)+((float)k[i].vize*0.4);

}
ort=ort/3;
return ort; 
}

int main(){

struct student sd [3]; 

for(int i =0 ; i<3;i++){ 
      
    printf("öğrenci no:"); 
    scanf("%d",&sd[i].no);
    printf("öğrenci vize notu:"); 
    scanf("%d",&sd[i].vize);
    printf("öğrenci final notu:"); 
    scanf("%d",&sd[i].final);

}
printf("ortalama = %f",hesapla(sd)); 

FILE *ptr =fopen("p2.txt","w"); 
if(ptr==NULL){
 printf("dosya oluşturma başarısız!!"); 
    return -1;
}

fprintf(ptr,"%-7s %5s %5s","ogr no","vize notu","final notu\n"); 

for(int i =0 ;i<3;i++){
    fprintf(ptr,"%-10d %-10d %-10d",sd[i].no,sd[i].vize,sd[i].final); 
    fprintf(ptr,"%s","\n");
}
fclose(ptr); 
    return 0 ; 
}