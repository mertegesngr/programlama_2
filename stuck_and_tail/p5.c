#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define BOYUT 5 // Yığıtın kapasitesi

char Yigit[BOYUT+1  ];
int top = -1;

// Yığıt dolu mu kontrolü
int isFull() {
    return top == BOYUT - 1 ? 1 : 0;
}

// Yığıt boş mu kontrolü
int isEmpty() {
    return top == -1 ? 1 : 0;
}

// Eleman ekleme (Push) fonksiyonu
void Push(char x[10]) {
    if (isFull()) {
        printf("Yigit dolu, ekleme yapilamaz!\n");
        return;
    }
    int sayac=0;
   for(int i=0;i<10;i++){
    if(x[i]=='\0'){
        break;
    }
    sayac++;
   }
   if(sayac>BOYUT||(top+1)>BOYUT){
    printf("girilen kelime boyuttan büyük;\n");
    return;
   }
   int a =0;
    for(int i=top+1;i<BOYUT;i++){
        Yigit[i]=x[a++];
    }
    top=sayac;
    printf("%s yigita eklendi.\n", x);
}

// Eleman çıkarma (Pop) fonksiyonu
void Pop() {
    if (isEmpty()) {
        printf("Yigit Bos!\n");
        return;
    }
    if(Yigit[top]=='\0'){
    printf("%s cikarildi.\n", Yigit[top--]);
    }
    else{
        printf("%c cikarildi.\n", Yigit[top--]);
    }
}

// Yığıtın en üstündeki elemanı gösteren fonksiyon
int Top() {
    if (isEmpty()) {
        printf("Yigit Bos!\n");
        return -1;
    }
    return Yigit[top];
}

// Yığıttaki elemanları listeleme fonksiyonu
void Listele() {
    if (isEmpty()) {
        printf("Yigit Bos!\n");
        return;
    }
    printf("Yigit elemanlari: ");
    for (int i = top; i >=0; i--) {
        printf("%c ",Yigit[i]);
    }
    printf("\n");
}

// Yığıtı tamamen temizleme fonksiyonu
void Clear() {
    while (!isEmpty()) {
        Pop();
    }
    printf("Yigit bosaltildi.\n");
}
int main() {

   Push("berra");
   Listele();

  Pop();
   Listele();
   Pop();
  
    return 0;
}