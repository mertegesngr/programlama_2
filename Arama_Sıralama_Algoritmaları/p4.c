#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100  // Rastgele sayıların maksimum değeri

// Diziyi ekrana yazdıran fonksiyon
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort algoritması
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap işlemi
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // Her adımda dizinin durumunu yazdır
        printf("Adım %d: ", i + 1);
        printArray(arr, n);
    }
}

// Selection Sort algoritması
void selectionSort(int arr[], int n) {
    int minIndex, temp;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap işlemi
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // Her adımda dizinin durumunu yazdır
        printf("Adım %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() {
    int n, choice;

    // Rastgele sayı üretmek için seed ayarı
    srand(time(NULL));

    // Kullanıcıdan dizi boyutunu al
    printf("Kaç adet rastgele sayı üretmek istersiniz? ");
    scanf("%d", &n);

    int arr[n];

    // Rastgele sayılarla diziyi doldur
    printf("Oluşturulan rastgele dizi: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Kullanıcıya sıralama algoritmasını seçtir
    printf("Sıralama algoritmasını seçin:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("Seçiminiz: ");
    scanf("%d", &choice);

    // Seçime göre sıralama işlemini gerçekleştir
    switch (choice) {
        case 1:
            printf("Bubble Sort işlemi başlıyor...\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("Selection Sort işlemi başlıyor...\n");
            selectionSort(arr, n);
            break;
        default:
            printf("Geçersiz seçim!\n");
            return 1;
    }

    // Son olarak sıralanmış diziyi yazdır
    printf("Sıralanmış dizi: ");
    printArray(arr, n);

    return 0;
}
