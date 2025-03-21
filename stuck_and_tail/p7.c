#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define BOYUT 10// Yığıtın kapasitesi

char Yigit[BOYUT+1];
int top = -1;
int p1=0;
int p2=0;

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
    else{
        if(Yigit[top]=='('){
         p1++;
        }
        else if(Yigit[top]==')'){
            p2++;
           }
       top--;
        
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

char c[BOYUT+1];
printf("işlem giriniz:");
gets(c);
Push(c);
int sayac=0;
for(int i =0;i<BOYUT;i++){
    if(c[i]=='\0'){
        break ; 
    }
sayac++;
}
for(int i =0;i<=sayac+1;i++){
    Pop();
}
// printf("p1=%d p2=%d\n",p1,p2);
if(p1==p2){
    printf("parantez hatası yoktur.\n");
}
else{
    printf("işlemde parantez hatası vardır!!!\n");
}
  
    return 0;
}