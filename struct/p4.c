#include <stdio.h>
#include <string.h>  // String manipülasyonu için gerekli

int g_yil = 2025;
int g_gun = 20;
int g_ay = 2;

struct dogumTarihi {
    int yil;
    int gun;
    int ay;
};

struct personel {
    char ad[50];
    int maas;
    struct dogumTarihi dt;
    int yas;
};

int yasHesapla(struct personel pc) {
    int yas = g_yil - pc.dt.yil;

    if (g_ay < pc.dt.ay || (g_ay == pc.dt.ay && g_gun < pc.dt.gun)) {
        yas--;  // Eğer doğum günü bu yıl geçmediyse bir yaş eksik alıyoruz.
    }

    return yas;
}

int main() {
    struct personel ps[2];

    // Kullanıcıdan bilgileri alıyoruz
    for (int i = 0; i < 2; i++) {
        printf("%d. personel için :\n", i + 1);
        printf("ad-soyad : ");
        if (i != 0)
            getchar();  // Bu satır, fgets ile ad girmeden önce önceki inputlardan kalan '\n' karakterini temizler
        fgets(ps[i].ad, sizeof(ps[i].ad), stdin);
        getchar(); 
        // ps[i].ad[strcspn(ps[i].ad, "\n")] = 0; // \n'yi temizliyoruz

        printf("maaş: ");
        scanf("%d", &ps[i].maas);
        printf("doğum günü (gün): ");
        scanf("%d", &ps[i].dt.gun);
        printf("doğum yılı: ");
        scanf("%d", &ps[i].dt.yil);
        printf("doğum ayı: ");
        scanf("%d", &ps[i].dt.ay);
    }

    // Yaş hesaplama
    for (int i = 0; i < 2; i++) {
        ps[i].yas = yasHesapla(ps[i]);
    }

    // Yaşı 18 ile 21 arasında olan çalışanları ekrana yazdırıyoruz
    for (int i = 0; i < 2; i++) {
        if (ps[i].yas >= 18 && ps[i].yas <= 21) {
            printf("Çalışan %d için \n ad-soyad: %s maaş: %d yaş: %d\n", i + 1, ps[i].ad, ps[i].maas, ps[i].yas);
            printf("******************************************\n\n");
        }
    }

    // Dosyaya yazma işlemi
    FILE *ptr = fopen("calisanlar.txt", "w");
    if (ptr == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }

    // Başlık satırlarını dosyaya yazıyoruz
    fprintf(ptr, "%-20s %-10s %-15s\n", "Ad-Soyad", "Maaş", "Yaş");

    // Çalışan bilgilerini dosyaya yazıyoruz
    for (int i = 0; i < 2; i++) {
        fprintf(ptr, "%-20s %-10d %-15d\n", ps[i].ad, ps[i].maas, ps[i].yas);
    }

    // Dosyayı kapatıyoruz
    fclose(ptr);

    printf("Veriler dosyaya kaydedildi.\n");

    return 0;
}
