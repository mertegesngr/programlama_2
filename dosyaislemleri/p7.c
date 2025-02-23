#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct student {
    int vize;
    int final;
    char ad_soyad[35];
};

int main() {
    setlocale(LC_ALL, "Turkish");

    FILE *pt = fopen("p6_adlar.txt", "r");
    if (pt == NULL) {
        printf("Adlar dosyası açılamadı!\n");
        return 1;
    }

    struct student sd[5];

    for (int i = 0; i < 5; i++) {
        fgets(sd[i].ad_soyad, sizeof(sd[i].ad_soyad), pt);
        sd[i].ad_soyad[strcspn(sd[i].ad_soyad, "\n")] = '\0';  // Satır sonu karakterini kaldır
    }

    fclose(pt);

    FILE *ptr = fopen("p6_notlar.txt", "r");
    if (ptr == NULL) {
        printf("Notlar dosyası açılamadı!\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        fscanf(ptr, "%d %d", &sd[i].vize, &sd[i].final);
    }
    fclose(ptr);

    FILE *p = fopen("p7_notlar.txt", "w");
    if (p == NULL) {
        printf("Çıktı dosyası oluşturulamadı!\n");
        return 1;
    }

    fprintf(p, "Ad-Soyad             Vize  Final  Ortalama\n");
    fprintf(p, "------------------------------------------\n");

    float ort[5] = {0};
    for (int i = 0; i < 5; i++) {
        ort[i] = (sd[i].final * 0.6) + (sd[i].vize * 0.4);
        fprintf(p, "%-20s %5d %5d %7.2f\n", sd[i].ad_soyad, sd[i].vize, sd[i].final, ort[i]);
    }

    fclose(p);
    printf("İşlem tamamlandı, p7_notlar.txt dosyası oluşturuldu.\n");

    return 0;
}
