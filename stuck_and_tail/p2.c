#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define boyut 10
int top= -1;
int dizi[boyut];

int dolumu(){

if(top+1==boyut)
return 0;
return 1;
}
int bosmu(){
    if(top==-1)
    return 1;
    return 0 ;
}

void ekle (int x){

if(dolumu()){
    printf("%d yazdırıldı \n",x);
    dizi [++top]=x;
}
else{
    printf("dizi dolu ekleme yapılamaz");
}
}

void cikar(){
if(bosmu()){
    printf("dizi boş çıkarma yapılamaz!!\n");
}
else{
    printf("%d çıkarıldı!!\n",dizi[top]);
    top--;
}
}

void yazdir(){
    if(bosmu()){
        printf("dizi boş yazdırılamaz!!!\n");
    }
    else{
 for(int i =0;i<=top;i++){
    printf("%d ",dizi[i]);
 }
    }
    printf("\n");
}
void clear(){
    printf("yığıt temizlendi!!\n");
    top=-1;
}

int main(){
int a ; 
    srand(time(NULL));
    for(int i =0;i<10;i++){
    ekle(rand() % 100+1);
    }
    printf("dizinin ilk hali: ");
    yazdir();
    printf("kaç eleman çıkartmak istiyorsunuz:");
    scanf("%d",&a);
    for(int i =0;i<a;i++){
        cikar();
    }
    printf("çıkarma işlemi yapıldı dizinin son hali:\n");
  yazdir();




}