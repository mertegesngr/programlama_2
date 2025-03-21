#include <stdio.h>
#include <stdlib.h>
#define boyut 5 
int top=-1;
int dizi[5];
int bosMu(){
    if(top+1==boyut)
    return 0 ; 
    return 1;
}
void yerlestir(int x){
    if(bosMu()){
   dizi[top+1]=x;
   top++;
    }
    else{
        printf("dizi boş değil!!!");
    }
}
void sil() {
    if (top == -1) {
        printf("Yığıt boş, silme işlemi yapılamaz!!\n");
    } else {
        printf("%d silindi\n", dizi[top]);
        top--;
    }
}

void yazdir() {
    if (top == -1) {
        printf("Dizi boş!!\n");
    } else {
        printf("Dizi elemanları: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", dizi[i]);
        }
        printf("\n");
    }
}

void clear() {
    top = -1;
}



int main() {
    yerlestir(10);
    yazdir();
    yerlestir(20);
    yerlestir(30);
    yazdir();
    sil();
    yazdir();
    clear();
    yazdir();

    return 0;
}