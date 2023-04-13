#include <stdio.h>
#include <string.h>

// Union Tanýmlama  - 1
union ogrenci {
    char isim[20];
    int no;
    float ort;
};

// Union Tanýmlama - 2 
typedef union {
    char isim[20];
    int yas;
} ogretmen;

int main(){

    printf("Boyut: %ld Byte \n", sizeof(union ogrenci));

    union ogrenci o;

    strcpy(o.isim, "Yucel");
    printf("Isim: %s \n", o.isim);

    o.no = 148;
    printf("No: %d \n", o.no);

    o.ort = 85.5;
    printf("Ortalama: %f \n", o.ort);

    // Typedef ile Kullaným
    ogretmen ogrt;
    strcpy(ogrt.isim, "Ismail");

    printf("Ogretmen Adi: %s \n", ogrt.isim);

    ogrt.yas = 45;
    printf("Ogretmen Yasi: %d", ogrt.yas);

    return 1;
}
