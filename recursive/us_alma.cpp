//recursive us alma
#include <stdio.h>
 
int usAlma(int, int);
 
int main() {
    int taban = 4;
    int us = 3;
    int sonuc;
 
    sonuc = usAlma(taban, us);
 
    printf("(%d)^%d = %d\n", taban, us, sonuc);
    return 0;
}
 
int usAlma(int taban, int us) {
    if (us == 0)
        return 1;
    return taban * usAlma(taban, us - 1);
}
