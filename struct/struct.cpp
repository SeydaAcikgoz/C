#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct kitap {
    char kitapAdi[30];
    float fiyat;
    int sayfa;
};

typedef struct {
    char adSoyad[30];
    int yas;
} yazar;

int main(){

    // Direct 
    struct kitap kitap1;
    strcpy(kitap1.kitapAdi, "T�rklerin Tarihi");
    kitap1.fiyat = 17.50;
    kitap1.sayfa = 350;

    // Undirect
    struct kitap *kitap2 = (struct kitap *)malloc(sizeof(struct kitap));
    strcpy(kitap2->kitapAdi, "Fabrika Ayar�");
    kitap2->fiyat = 16.50;
    kitap2->sayfa = 300;

    // TypeDef ile Kullan�m - Direct
    yazar yazar1; 
    strcpy(yazar1.adSoyad, "�lber Ortayl�");
    yazar1.yas = 74;

    // Typedef - Undirect 
    yazar *yazar2 = (yazar *)malloc(sizeof(yazar));
    strcpy(yazar2->adSoyad, "Hayati �nan�");
    yazar2->yas = 60;

    printf("Yazar 1: %s %d \n", yazar1.adSoyad, yazar1.yas);
    printf("Yazar 2: %s %d", yazar2->adSoyad, yazar2->yas);

    return 1;
}
