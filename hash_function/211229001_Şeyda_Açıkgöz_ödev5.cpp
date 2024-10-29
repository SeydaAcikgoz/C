#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Personel{
	int no;
	char ad[20];
	char soyad[20];
	struct Personel*sonraki;	

}Personel;

H_Listele(Personel*gecici ){

			printf("%d %s %s \n",gecici->no,gecici->ad,gecici->soyad);
			gecici=gecici->sonraki;
		    while(gecici!=NULL){
				printf("%d %s %s \n",gecici->no,gecici->ad,gecici->soyad);
				gecici=gecici->sonraki;
			}
	}
	
H_Yaz(Personel*dizi[],Personel*yeni,int mod){
	Personel*gecici=NULL;
			if(dizi[mod]==NULL){
				dizi[mod]=yeni;
				yeni->sonraki=NULL;
			}
			else{
				if ((dizi[mod]->no) > yeni->no) {
	            yeni->sonraki = dizi[mod];
	            dizi[mod] = yeni;
	        	}
	        	else {
	            gecici = dizi[mod];
	            while (gecici != NULL) { //gecici elemaninin sonraki null ise ve son elemandan buyukse
	                if (gecici->sonraki == NULL && (gecici->no) <=yeni->no) {
	                    yeni->sonraki = NULL;
	                    gecici->sonraki = yeni;
	                    break;
	                }
	                
	                if ((gecici->sonraki->no) >yeni->no) {//Araya Ekleme
	                    yeni->sonraki = gecici->sonraki;
	                    gecici->sonraki = yeni;
	                    break;
	                }
	                gecici = gecici->sonraki;
	            }
	        }
			
				
	}
}

H_Arama(Personel*dizi[],int aranan,int boyut ){
		int index = aranan%boyut;
		
		if(dizi[index]->no==aranan){
			return 1;
		}
				 
		else{
		
			Personel*gecici=dizi[index];
			while(gecici!=NULL){
				if(gecici->no==aranan){
					return 1;
				}
				gecici=gecici->sonraki;
			}
		}	
	
		return 0;
}
	
	
	H_Silme(Personel*dizi[],int silinecek,int boyut ){
		int index = silinecek%boyut;

		 	if(dizi[index]->no==silinecek){
					dizi[index]=dizi[index]->sonraki;
					return 0;
			}
			
			Personel*once=NULL;
			Personel*sonra=NULL;
			Personel*gecici=dizi[index];
				while(gecici->sonraki->no!=silinecek){
					gecici=gecici->sonraki;
				}
				if(gecici->sonraki->sonraki==NULL){
					free(gecici->sonraki);
					gecici->sonraki=NULL;
					return 0;
				}
				once=gecici;
				sonra=gecici->sonraki->sonraki;
				free(gecici->sonraki);
				once->sonraki=sonra;
				return 0;
		
		return 0;
	}	



char*format="%d %s %s\n";

int main(){
	int boyut;
	printf("Hash tablosunun indis sayisini giriniz:");
	scanf("%d",&boyut);
	
	Personel*dizi[boyut];
	
	for(int i=0;i<boyut;i++){
			dizi[i]=NULL;
	}

	FILE*dosya=fopen("Personel.txt","r");
	
	if(dosya==NULL){
		printf("Dosya bulunamadi.");
		return 0;
	}
	else{
		while(!feof(dosya)){
			Personel*yeni =(Personel*)malloc(sizeof(Personel));
			fscanf(dosya,format,&yeni->no,&yeni->ad,&yeni->soyad);
				int mod=yeni->no%boyut;
				
				H_Yaz(dizi,yeni,mod);
		}	
	}

	
	for(int i=0;i<boyut;i++){
		if(dizi[i]==NULL){
			continue;
		}
		H_Listele(dizi[i]);
		
		printf("\n");
	}	
	
		
	printf("\n\n*****ARAMA ISLEMI*****\n");
	int aranan;
	printf("\n\nAranan personel numarasini giriniz:");
	scanf("%d",&aranan);
	
	while(aranan!=-1){
		if(H_Arama(dizi,aranan, boyut)==0){
			printf("Aranan numara hash tablosunda bulunamadi.");
		}
		else{
			printf("Aranan numara hash tablosunda bulunmaktadir.");
		}	
	printf("\n\nAranan personel numarasini giriniz:");
	scanf("%d",&aranan);	
	}
	
	printf("\n\n*****SILME ISLEMI*****\n");
	int silinecek;
	
	printf("\n\Silinecek personel numarasini giriniz:");
	scanf("%d",&silinecek);
	
	while(silinecek!=-1){
		
		if(H_Arama(dizi,silinecek, boyut)==0){
			printf("Silinecek personel numarasi bulunamadi.\n");
		}
		else{
			H_Silme(dizi,silinecek, boyut);
		}
		
		
		for(int i=0;i<boyut;i++){
			if(dizi[i]==NULL){
				continue;
			}
			H_Listele(dizi[i]);
			printf("\n");
		}	
		
	printf("\n\Silinecek personel numarasini giriniz:");
	scanf("%d",&silinecek);
		
	}
	
	return 0;
}
