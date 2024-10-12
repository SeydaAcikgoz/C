//negatif ile çarpma
#include <stdio.h>
 
int negatifCarpmaIslemi(int x, int y);
 
int main() {
    int sayi1 = 15;
    int sayi2 = -5;
    int sonuc = negatifCarpmaIslemi(sayi1, sayi2);
    printf("%d * %d = %d\n", sayi1, sayi2, sonuc);
    return 0;
}
 
int negatifCarpmaIslemi(int x, int y) {
    if (y == 0)
        return 0;
    if (y < 0)
        return (-x) + negatifCarpmaIslemi(x, y + 1);
    return x + negatifCarpmaIslemi(x, y - 1);
}
