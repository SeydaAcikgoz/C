#include<stdio.h>
#include<stdlib.h>
#define size 10
 
int ikiliarama(int[], int, int, int);
 
int main() {
   int boyut, i, aranan, pozisyon;
   int ilk, son, list[size];
 
   printf("\nListe kac elemanli olacak: ");
   scanf("%d", &boyut);
 
   printf("\nListenin elemanlarini giriniz :");
   for (i = 0; i < boyut; i++) {
      scanf("%d", &list[i]);
   }
 
   ilk = 0;
   son = boyut - 1;
 
   printf("\nAranan eleman : ");
   scanf("%d", &aranan);
 
   pozisyon = ikiliarama(list, aranan, ilk, son);
 
   if (pozisyon != -1) {
      printf("\nAranan eleman %d.siradadir", (pozisyon + 1));
   } else
      printf("\n Aranan eleman listede yok");
   return (0);
}
 
int ikiliarama(int a[], int x, int ilk, int son) {
   int orta;
 
   if (ilk > son)
      return -1;
 
   orta = (ilk + son) / 2;
   
 
   if (x == a[orta]) {
      return (orta);
   } else if (x < a[orta]) {
      ikiliarama(a, x, ilk, orta - 1);
   } else {
      ikiliarama(a, x, orta + 1, son);
   }
}
