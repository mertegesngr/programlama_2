#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define boyut 2

int top=-1;
struct kitap{
char ad[20];
int yil;
char yazar[25];
};
typedef struct kitap kitap;
kitap a[boyut];

int dolumu(){
    if(top+1==boyut)
    return 1;
    return 0;
    }
    int bosmu(){
        if(top==-1)
        return 1;
        return 0 ;
    }

void ekle(kitap c){
if(dolumu()){
    printf("yığıt dolu ekleme yapılamaz!!\n");
}
else{
    top++;
   strcpy(c.ad,a[top].ad);
   strcpy(c.yazar,a[top].yazar);
   a[top].yil=c.yil;
}

}
void yazdir(){
    if(bosmu()){
        printf("Yığıt boş, yazdırma yapılamaz!\n");
    }
    else{
        printf("\nYığıttaki kitaplar:\n");
        for(int i = 0; i <= top; i++){
            printf("Kitap Adı: %s\n", a[i].ad);
            printf("Yazar: %s\n", a[i].yazar);
            printf("Yıl: %d\n", a[i].yil);
            printf("--------------------\n");
        }
    }
}
void clear(){
    printf("yığıt temizlendi!!\n");
    top=-1;
}
void cikar(){
    if(bosmu()){
        printf("dizi boş çıkarma yapılamaz!!\n");
    }
    else{
        printf("kitap çıkarıldı!!\n");
        top--;
    }
    }

int main() {


for(int i =0;i<boyut;i++){
    printf("%d. kitap adı:",i+1);
    gets(a[i].ad);
    printf("%d. yazar adı:",i+1);
    gets(a[i].yazar);
    printf("%d. kitap yılı:",i+1);
    scanf("%d",&a[i].yil);
    ekle(a[i]);
    getchar();

}
    yazdir();
    cikar();
    yazdir();
    cikar();
    yazdir();
    cikar();
    return 0;
}