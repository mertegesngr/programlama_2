#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogr {
    char ad[45];
    int vize;
    int final;
};

int main() {
    struct ogr student[5];

    for(int i = 0; i < 5; i++) {
        printf("%d. öğrenci adı soyadı: ", i + 1);
        fgets(student[i].ad, sizeof(student[i].ad), stdin);
        student[i].ad[strcspn(student[i].ad, "\n")] = '\0';  // Yeni satır karakterini kaldır

        printf("öğrenci vize notu: ");
        if (scanf("%d", &student[i].vize) != 1) {
            fprintf(stderr, "Hatalı vize notu girdisi!\n");
            return 1;
        }

        printf("öğrenci final notu: ");
        if (scanf("%d", &student[i].final) != 1) {
            fprintf(stderr, "Hatalı final notu girdisi!\n");
            return 1;
        }

        getchar();  // Buffer'ı temizle
    }

    FILE *ptr = fopen("p6_adlar.txt", "w");
    if (ptr == NULL) {
        perror("Dosya açılamadı");
        return 1;
    }

    for(int i = 0; i < 5; i++) {
        fprintf(ptr, "%s\n", student[i].ad);
    }

    fclose(ptr);
    FILE *tr=fopen("p6_notlar.txt","w");
    for(int i = 0; i < 5; i++) {
        fprintf(ptr, "%d   %d\n", student[i].vize,student[i].final);
    }
    fclose(tr);
    printf("Öğrenci bilgileri p6.txt dosyasına yazıldı.\n");

    return 0;
}