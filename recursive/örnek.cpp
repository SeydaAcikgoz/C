//girilen sayiya kadar olan sayýlarý toplama
#include <stdio.h>

 
int girilenSayiyaKadarTopla(int);
 
int main() {
    int sayi = 11;
    int sonuc = girilenSayiyaKadarTopla(sayi);
    printf("sonuc = %d\n", sonuc);
    return 0;
}
 
int girilenSayiyaKadarTopla(int x) {
    if (x == 1)
        return 1;
    return x + girilenSayiyaKadarTopla(x - 1);
}
