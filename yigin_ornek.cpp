#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Yigin{
	char harf;
	struct Yigin*onceki;	
	struct Yigin*sonraki;	

}Yigin;

typedef struct Yigin1{
	char harf;
	struct Yigin1*onceki;	
	struct Yigin1*sonraki;	

}Yigin1;

typedef struct Yigin2{
	char sayi;
	struct Yigin2*onceki;	
	struct Yigin2*sonraki;	
}Yigin2;

Yigin*ilk=NULL;
Yigin*son=NULL;

Yigin1*ilk1=NULL;
Yigin1*son1=NULL;

Yigin2*ilk2=NULL;
Yigin2*son2=NULL;

YiginListele(){
	Yigin*gecici=ilk;
	while(gecici!=NULL){
		printf("%c  ",gecici->harf);
		gecici=gecici->sonraki;
	}
}

Yigin1Listele(){
	Yigin1*gecici=ilk1;
	while(gecici!=NULL){
		printf("%c\t",gecici->harf);
		gecici=gecici->sonraki;
	}
}

Yigin2Listele(){
	Yigin2*gecici=ilk2;
	while(gecici!=NULL){
		printf("%c\t",gecici->sayi);
		gecici=gecici->sonraki;
	}
}

YiginEkle(char harf){
	Yigin*yeni=(Yigin*)malloc(sizeof(Yigin));
	yeni->harf=harf;
	
	if(ilk==NULL){
		ilk=yeni;
		ilk->onceki=NULL;
	}
	else{
		son->sonraki=yeni;
		yeni->onceki=son;
	}
	son=yeni;
	son->sonraki=NULL;
}

Yigin1Ekle(char harf){
	Yigin1*yeni=(Yigin1*)malloc(sizeof(Yigin1));
	yeni->harf=harf;
	
	if(ilk1==NULL){
		ilk1=yeni;
		ilk1->onceki=NULL;
	}
	else{
		son1->sonraki=yeni;
		yeni->onceki=son1;
	}
	son1=yeni;
	son1->sonraki=NULL;
}

Yigin2Ekle(char karakter){
	Yigin2*yeni=(Yigin2*)malloc(sizeof(Yigin2));
	yeni->sayi=karakter;
	
	if(ilk2==NULL){
		ilk2=yeni;
		ilk2->onceki=NULL;
	}
	else{
		son2->sonraki=yeni;
		yeni->onceki=son2;
	}
	son2=yeni;
	son2->sonraki=NULL;
}

char*format="%c\n";
int main(){
	
	char karakter,aranan1,aranan2,aranan3;
	char ara1,ara2,ara3;
	int secim,kontrol=0;
	
	FILE*dosya=fopen("yigin.txt","r");
	//sayi 48-57
	//harf 97-122
	while(fscanf(dosya,format,&karakter)!=EOF){
		YiginEkle(karakter);

		if(karakter>=97 && karakter<=122){		//gelen karakter harf ise
		Yigin1Ekle(karakter);
		}
		else if(karakter>=48 && karakter<=57){	//gelen karakter sayi ise
		Yigin2Ekle(karakter);
		}
	}
	printf("\nYigin:");
	YiginListele();
	
	printf("\n\nArdisik karakter dizisi:");
	Yigin1Listele();
	
	printf("\n\nArdisik rakam dizisi:");
	Yigin2Listele();
	
	while(1){
	
		kontrol=0;
	
				printf("\n\nAranan karakterleri giriniz:");
				
				printf("\n1.karakter:");
				aranan1=getche();
				printf("\n2.karakter:");
				aranan2=getche();
				printf("\n3.karakter:");
				aranan3=getche();
			
			
				Yigin*gecici=ilk;
				while(gecici->sonraki->sonraki!=NULL){
					if(gecici->harf==aranan1 && gecici->sonraki->harf==aranan2 && gecici->sonraki->sonraki->harf==aranan3){
						printf("\nAranan karakter dizisi vardir.");
						kontrol++;
						break;
					}
					else{
						gecici=gecici->sonraki;
					}
				}
				if(kontrol==0){
					printf("\nAranan karakter dizisi yoktur.");
				}	
			}
	return 0;
}
