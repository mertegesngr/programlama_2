#include <stdio.h>

// Özyinelemeli doğrusal arama fonksiyonu
int dogrusalArama(int dizi[], int n, int aranan, int indeks) {
    if (indeks >= n)  // Dizi sonuna ulaşıldıysa
        return -1;
    
    if (dizi[indeks] == aranan)  // Eğer aranan eleman bulunduysa
        return indeks;

    return dogrusalArama(dizi, n, aranan, indeks + 1); // Bir sonraki elemanda ara
}

int main() {
    int dizi[] = {3, 7, 2, 9, 5, 10};
    int n = sizeof(dizi) / sizeof(dizi[0]);
    int aranan = 9;

    int sonuc = dogrusalArama(dizi, n, aranan, 0);

    if (sonuc != -1)
        printf("Eleman %d, %d. indiste bulundu.\n", aranan, sonuc);
    else
        printf("Eleman bulunamadı.\n");

    return 0;
}
