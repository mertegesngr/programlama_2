#include <stdio.h>
#include <stdlib.h>


struct n{
 int x;
 struct n *next;


};

typedef struct n node ; 

void bastir(node *yaz) {
    while (yaz != NULL) { // Listenin sonuna kadar git
        printf("%d -> ", yaz->x);
        yaz = yaz->next;
    }
    printf("NULL\n"); // Listenin sonunu belirt
}
int main() {

 node*root;
 
 root = (node *)malloc(sizeof(node));  
    root->x = 20;  
    root->next = (node *)malloc(sizeof(node)); // İkinci düğüm için bellek tahsisi

    root->next->x = 10;  // İkinci düğüme değer atandı
    root->next->next = (node *)malloc(sizeof(node)); // Üçüncü düğüm için bellek tahsisi

    root->next->next->x = 5;  // Üçüncü düğüme değer atandı
    root->next->next->next = NULL; // Listenin sonunu belirtiyoruz
  node *iter;
  iter=root;
node *esag=iter->next;
// while(esag!=NULL){
// printf("%d  ",iter->x);
//     iter=iter->next;
   
// }
bastir(root);
    return 0;
}
