#include <stdio.h>

// Özyinelemeli ikili arama fonksiyonu
int ikiliArama(int dizi[], int sol, int sag, int aranan) {
    if (sol > sag)  // Dizi tamamen tarandıysa ve eleman yoksa
        return -1;

    int orta = sol + (sag - sol) / 2;  // Ortadaki elemanı bul

    if (dizi[orta] == aranan)  // Eğer ortadaki eleman aranana eşitse
        return orta;

    if (dizi[orta] > aranan)  // Aranan eleman daha küçükse, sol yarıda ara
        return ikiliArama(dizi, sol, orta - 1, aranan);
    
    // Aranan eleman daha büyükse, sağ yarıda ara
    return ikiliArama(dizi, orta + 1, sag, aranan);
}

int main() {
    int dizi[] = {1, 3, 5, 7, 9, 11, 15, 18, 21};
    int n = sizeof(dizi) / sizeof(dizi[0]);
    int aranan = 9;

    int sonuc = ikiliArama(dizi, 0, n - 1, aranan);

    if (sonuc != -1)
        printf("Eleman %d, %d. indiste bulundu.\n", aranan, sonuc);
    else
        printf("Eleman bulunamadı.\n");

    return 0;
}
