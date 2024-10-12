//asallýk kontrolu
#include <stdio.h>
 
int asalSayi(int, int);
 
int main() {
    int sayi = 29;
    int sonuc = asalSayi(sayi, sayi / 2);
    if (sonuc == 0)
        printf("%d asal sayi degildir\n", sayi);
    else
        printf("%d asal sayidir\n", sayi);
    return 0;
}
 
int asalSayi(int x, int i) {
    if (x < 2)
        return 0;
    if (i == 1)
        return 1;
    if (x % i == 0)
        return 0;
    return asalSayi(x, i - 1);
}
