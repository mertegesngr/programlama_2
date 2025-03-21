#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int g_gun, g_ay, g_yil;
int a_gun, a_ay, a_yil;

// Güncel tarihi alan fonksiyon
void g_zaman() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    g_gun = tm_info->tm_mday;
    g_ay = tm_info->tm_mon + 1;  // tm_mon 0'dan başlar, bu yüzden 1 ekliyoruz
    g_yil = tm_info->tm_year + 1900; // tm_year, 1900 yılından itibaren hesaplanır
}

struct p5 {
    int yil;
    int ay;
    int gun;
};

// Yaşı hesaplayan fonksiyon
void yashesapla(struct p5 i) {
    if (g_gun < i.gun) {
        g_gun += 30;
        g_ay -= 1;
    }
    a_gun = g_gun - i.gun;

    if (g_ay < i.ay) {
        g_ay += 12;
        g_yil -= 1;
    }
    a_ay = g_ay - i.ay;

    a_yil = g_yil - i.yil;
}

int main() {
    struct p5 b;

    printf("Doğum tarihinizi giriniz: (G/AA/YYYY): ");
    scanf("%d/%d/%d", &b.gun, &b.ay, &b.yil);

    // Güncel tarihi al26/
    g_zaman();

    printf("Güncel tarih: %d/%d/%d\n", g_gun, g_ay, g_yil);

    // Yaşı hesapla
    yashesapla(b);

    printf("%d yıl %d ay %d gün yaşındasınız.\n", a_yil, a_ay, a_gun);

    return 0;
}
