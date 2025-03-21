#include <stdio.h>
#include <stdlib.h>
#define boyut 5 

int kuyruk[boyut];
int yigit[boyut];
int top=-1;
int front=-1;
int tail=-1;

int Ybosmu(){
    if(top==-1)
    return 1;
    return 0 ; 
}
int Kbosmu(){
    if(front==-1)
    return 1 ;
    return 0 ;
}
int Ydolumu(){
    if(top==boyut-1)
    return 1;
    return 0 ; 
}
int Kdolumu(){
    if(tail==boyut-1)
    return 1;
    return 0 ; 
}

void ekle(int x){
    if(Ydolumu()){
        printf("yığıt dolu!!\n");
    }
    else{
        printf("%d eklendi!!\n",x);
        yigit[++top]=x;
    }
}
void cikar(){
    if(Ybosmu()){
        printf("yığıt boş çıkarma işlemi yapılamaz!!!\n");
    }
    else{
        printf("çıkarma işlemi yapıldı!!\n");
        top--;
    }
}
void Yyazdir(){
    if(Ybosmu()){
        printf("Boş yığıt yazdırılamaz!!\n");
    }
    else{
       for(int i=0; i<=top; i++){
            printf("%d ", yigit[i]);
       }
       printf("\n");
    }
}

void Yclear(){
    top=-1;
    printf("yığıt temizlendi!!\n");
}


void Kekle(int a){
if(Kdolumu()){
    printf("kuyruk dolu ekleme yapılamaz!!\n");
}
else{
    if(front==-1){
        front=0;
    }
    printf("%d kuyruğa eklendi!!\n",a);
    kuyruk[++tail]=a;

}

}
void Ksil(){
    if(Kbosmu()){
        printf("kuyruk boş çıkarma işlemi yapılamaz!!\n");
    }
    else{
        printf("%d çıkarıldı!!\n",kuyruk[front]);
        front++;
    }
}
void Kyazdir(){
    if(Kbosmu()){
        printf("Boş kuyruk yazdırılamaz!!\n");
    }
    else{
        for(int i =front;i<=tail;i++){
            printf("%d ",kuyruk[i]);
        }
    }
}
void Kclear(){
    front=-1;
    tail=-1;
}
void aktar(){

if(Kdolumu()){
    printf("yığıt dolu aktarım yapılamadı!!\n");
}
else if (Ybosmu()) {
    printf("Yığıt boş, aktarım yapılamadı!!\n");
}
else{
    Kekle(yigit[top]);
    cikar();
}
}
int main() {
    int a;

  printf("yığıta 5 adet sayı ekle:\n");
  for(int i =0;i<5;i++){
    printf("sayı %d:",i+1);
    scanf("%d",&a);
    ekle(a);
  }
  printf("yığıtın kaç elemanı kuyruğa eklensin:");
  scanf("%d",&a);
 for(int i=0;i<a;i++){
    aktar();
 }
 printf("yığıt son hali:\n");
  Yyazdir();
  printf("kuyruk son hali:\n");
  Kyazdir();
    return 0;
}