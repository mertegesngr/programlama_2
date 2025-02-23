#include <stdio.h>
#include<stdlib.h>
#include <string.h>

// Bir banka için müşteri hesap 
// bilgileri(müşteri adı,bakiyesi) kaydedilecektir. 
// Kullanıcıdan alınan n sayısına göre n adet müşteriyi pointer kullanarak oluşturunuz
//  ve her müşterinin adını ve bakiyesini kullanıcıdan alınız. HesapListele fonksiyonunu kullanarak 
//  bankadaki müşterilerin adını ve bakiyesini listeledikten sonra tüm müşterilerin toplam bakiyesini yazdırınız.

struct p7
{
    char ad_soyad[35];
    int bakiye; 
};

void hesapla(struct p7  m [],int n){
 
    int t_bakiye=0;
    printf("adlar \t\t\t bakiye\n");  
for(int i =0 ; i<n;i++){
    printf("%s\t\t  %d\n",m[i].ad_soyad,m[i].bakiye); 
    t_bakiye+=m[i].bakiye; 
}
printf("toplam bakiye=%d\n",t_bakiye);


}
int dosyayaYaz(struct p7  m [],int n){
    FILE *ptr=fopen("musteriler.txt","w");
    if(ptr==NULL){
        printf("dosyaya yazma başarısız!!"); 
        return -1;
    }
    int t_bakiye=0;
    fprintf(ptr,"%s","adlar \t\t\t bakiye\n");  
for(int i =0 ; i<n;i++){
    fprintf(ptr,"%s\t\t  %d\n",m[i].ad_soyad,m[i].bakiye); 
    t_bakiye+=m[i].bakiye; 
}
fprintf(ptr,"%s %d","toplam bakiye=",t_bakiye);
printf("dosyaya yazma başarılı\n");
fclose(ptr);
return 0 ; 
}

int main (){

int n ; 
printf("müşteri sayısı giriniz:"); 
scanf("%d",&n);

struct p7 *m= (struct p7*)malloc(n*sizeof(struct p7));

for(int i =0 ; i<n;i++){
     printf("%d.müşteri adı:",i+1);
     getchar();
     fgets(m[i].ad_soyad,sizeof(m[i].ad_soyad),stdin);
    printf("müşteri bakiyesi:"); 
    scanf("%d",&m[i].bakiye); 
}

for(int i =0 ; i<n;i++){
    m[i].ad_soyad[strcspn(m[i].ad_soyad, "\n")] = '\0';
}

hesapla(m,n); 
dosyayaYaz(m,n); 



free(m);



    return 0; 
}