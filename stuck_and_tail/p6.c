#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define BOYUT 5 // Yığıtın kapasitesi

char Yigit[BOYUT];  // İlk yığıt (normal ekleme)
char TersYigit[BOYUT];  // İkinci yığıt (tersten ekleme)
int top1 = -1;  // İlk yığıt için top
int top2 = BOYUT;  // İkinci yığıt için top (ters ekleme)

int isEmpty1() { return top1 == -1; }
int isEmpty2() { return top2 == BOYUT; }

void Push1(char c) { if (top1 < BOYUT - 1) Yigit[++top1] = c; }
void Push2(char c) { if (top2 > 0) TersYigit[--top2] = c; }

char Pop1() { return isEmpty1() ? '\0' : Yigit[top1--]; }
char Pop2() { return isEmpty2() ? '\0' : TersYigit[top2++]; }

void Listele1() {
    if (!isEmpty1()) {
        printf("Yigit elemanlari: ");
        for (int i = 0; i <= top1; i++) {
            printf("%c ", Yigit[i]);
        }
        printf("\n");
    }
}

void Listele2() {
    if (!isEmpty2()) {
        printf("Ters Yigit elemanlari: ");
        for (int i = top2; i < BOYUT; i++) {
            printf("%c ", TersYigit[i]);
        }
        printf("\n");
    }
}

int isPalindrome() {
    for (int i = 0; i < BOYUT; i++) {
        if (Pop1() != Pop2()) {
            return 0; // Farklı karakter bulundu, palindrom değil
        }
    }
    return 1; // Hepsi eşleşti ise palindromdur
}

int main() {
    char kelime[BOYUT + 1];
    printf("Bir kelime girin (%d harf): ", BOYUT);
    scanf("%s", kelime);

    int uzunluk = strlen(kelime);
    if (uzunluk > BOYUT) {
        printf("Girilen kelime %d karakterden uzun olamaz!\n", BOYUT);
        return 1;
    }

    for (int i = 0; i < uzunluk; i++) {
        Push1(kelime[i]);  // Normal ekleme
        Push2(kelime[i]);  // Tersten ekleme
    }

    Listele1();
    Listele2();

    if (isPalindrome()) {
        printf("'%s' bir palindromdur.\n", kelime);
    } else {
        printf("'%s' bir palindrom degildir.\n", kelime);
    }

    return 0;
}