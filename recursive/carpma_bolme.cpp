//recursive carpma
#include <stdio.h>
 
int carpmaIslemi(int x, int y);

 int bolmeIslemi(int x, int y) {
    if (y == 0)
        return 0;
    if (x - y == 0)
        return 1;
    if (x < y)
        return 0;
    return (1 + bolmeIslemi(x - y, y));
}
 
 
int main() {
    int sayi1 = 15;
    int sayi2 = 6;
    int sonuc = carpmaIslemi(sayi1, sayi2);
    printf("%d * %d = %d\n", sayi1, sayi2, sonuc);
    
    sayi1=10,sayi2=5;
    sonuc=bolmeIslemi(sayi1,sayi2);
    printf("%d / %d =%d",sayi1,sayi2,sonuc);
    
    return 0;
}
 
int carpmaIslemi(int x, int y) {
    if (x==0 || y == 0)
        return 0;
    return x + carpmaIslemi(x, y - 1);
}
