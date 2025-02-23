#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
FILE *ptr=fopen("p6_notlar.txt","r");
 int vize[5];
 int final[5];

for(int i =0 ;i<5;i++){
    fscanf(ptr,"%d %d",&vize[i],&final[i]);
}
for(int i =0 ;i<5;i++){
    printf("%d %d\n",vize[i],final[i]);
}
 
fclose(ptr);

FILE *pr=fopen("p6_adlar.txt","r");
char adlar[5][35];
for(int i=0;i<5;i++){

}
for (int i = 0; i < 5; i++) {
        fgets(adlar[i], sizeof(adlar[i]), pr);
        adlar[i][strcspn(adlar[i], "\n")] = '\0';  // Satır sonu karakterini kaldır
    }
fclose(pr);
 float ort[5] = {0};
for (int i = 0; i < 5; i++) {
    ort[i] = (final[i]* 0.6) + (vize[i]* 0.4);
}


FILE *p=fopen("p33.txt","w");
fprintf(p, "Ad-Soyad             Vize  Final       Ortalama         Sonuç\n");
    fprintf(p, "------------------------------------------------------------\n");

char harfNot[5][3];
    for(int i=0;i<5;i++){
       if(ort[i]<44){
        
     strcpy(harfNot[i],"FF");
       }
       if(ort[i]>=45&&ort[i]<55){
        
        strcpy(harfNot[i],"DD");
          }
          if(ort[i]>55&&ort[i]<70){
        
            strcpy(harfNot[i],"CC");
              }
              if(ort[i]>=70&&ort[i]<=84){
        
                strcpy(harfNot[i],"BB");
                  }
                  if(ort[i]>=85&&ort[i]<=100){
        
                    strcpy(harfNot[i],"AA");
                      }
    }
    
for(int i=0;i<5;i++){
fprintf(p,"%s \t\t\t%d \t\t%d \t%f   %s\n",adlar[i],vize[i],final[i],ort[i],harfNot[i]);
}

    return 0;
}