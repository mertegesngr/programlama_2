#include <stdio.h>
#include <stdlib.h>
#define boyut 5

int top =-1;
int dizi[5];

int bosmu(){
    if(top==-1)
    return 1;
    return 0 ;
}
int dolumu(){
    if(top+1==boyut)
    return 1;
    return 0 ; 
}
void topla_enbuyuk(){
int toplam=0;
int eb=dizi[top];
for(int i =0 ;i<boyut;i++){
    if(eb<dizi[top]){
        eb=dizi[top];
    }
    toplam+=dizi[top];
    top--;
}
printf("yığıttaki sayıların toplamı =%d\n",toplam);
printf("yığıttaki en büyük sayı=%d",eb);



}
void ekle(int x){
    if(dolumu()){
        printf("yığıt dolu ekleme yapılamaz!!\n");
    }
    else{
        printf("%d yığıta eklendi!!\n",x);
        dizi[++top]=x;
    }
}
void cikar(){
    if(bosmu()){
        printf("yığıt boş çıkarma işlemi yapılamaz\n");
    }
    else{
        printf("%d çıkarıldı\n",dizi[top]);
        top--;
    }
}

void yazdir(){
    if(bosmu()){
  printf("yığıt boş yazdırma işlemi yapılamaz!!!\n");
    }
    else{
        for(int i =0;i<=top;i++){
            printf("%d ",dizi[i]);
        }
        printf("\n");
    }
}
void clear(){
    top=-1;
    printf("yığıt temizlendi!!!\n");
}

int main() {
    int c;
    printf("5 tane sayı giriniz:\n");
   for(int i =0;i<boyut;i++){
   printf("%d. sayi:",i+1);
   scanf("%d",&c);
   ekle(c);
   }
 topla_enbuyuk();
    return 0;
}