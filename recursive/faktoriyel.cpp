#include <stdio.h>
 
int faktoriyel(int x) {
    int sonuc = 1;
    
    if (x <= 1)
        return 1;
    return x * faktoriyel(x - 1);
    
   
}
 
int main() {
    int sayi;
    printf("Faktoriyeli alinacak sayi:");
    scanf("%d",&sayi);
    int sonuc = faktoriyel(sayi);
    printf("%d! = %d\n", sayi, sonuc);
    return 0;
}
 

