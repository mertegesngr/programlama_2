#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strlen() için eklenmeli

int main() {
    FILE *ptr = fopen("p4.txt", "w");  
    if (ptr == NULL) {
        printf("Dosya açılamadı!\n");
        return -1;
    }

    char adlar[5][20];  

    for (int i = 0; i < 5; i++) {
        printf("Ad %d gir: ", i + 1);
        fgets(adlar[i], 20, stdin);
        adlar[i][strcspn(adlar[i], "\n")] = '\0';
    }

    for (int i = 0; i < 5; i++) {
      fprintf(ptr,"%s\n",adlar[i]);
    }

    fclose(ptr);
    printf("Veriler başarıyla dosyaya yazıldı.\n");

    return 0;
}
