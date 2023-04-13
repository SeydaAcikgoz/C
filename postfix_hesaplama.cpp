#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
typedef struct Yigin{
    int karakter;
    int kapasite;
    int* dizi;
}Yigin;
 

struct Yigin* YiginOlustur( int kapasite ){
    struct Yigin* yigin = (struct Yigin*) malloc(sizeof(struct Yigin));
 
    if (!yigin) return NULL;
 
    yigin->karakter = -1;
    yigin->kapasite = kapasite;
    yigin->dizi = (int*) malloc(yigin->kapasite * sizeof(int));
 
    if (!yigin->dizi) return NULL;
 
    return yigin;
}
 
int BosMu(struct Yigin* yigin){
    return yigin->karakter == -1 ;
}
 
int peek(struct Yigin* yigin){
    return yigin->dizi[yigin->karakter];
}
 
int cikar(struct Yigin* yigin){
    if (!BosMu(yigin))
        return yigin->dizi[yigin->karakter--] ;
    return 0;
}
 
void ekle(struct Yigin* yigin,int sonuc){
    yigin->dizi[++yigin->karakter] = sonuc;
}
 


int PostfixHesapla(char* postfix){
    struct Yigin* yigin = YiginOlustur(strlen(postfix));
 
    if (!yigin){
    	return -1;
	} 
 
    for (int i = 0; postfix[i]; ++i){
        if(postfix[i]==' '){
        	continue;
		}
         
        
        else if (isdigit(postfix[i])){		//isdigit->sayi mi
            int sayi=0;
             
            while(isdigit(postfix[i])){
            sayi=sayi*10 + (int)(postfix[i]-'0');
                i++;
            }
            i--;
             
            ekle(yigin,sayi);
        }
         
        
        else{
            int deger1 = cikar(yigin);
            int deger2 = cikar(yigin);
             
            switch (postfix[i]){
	            case '+':
				ekle(yigin, deger2 + deger1);
				break;
				  
	            case '-':
				ekle(yigin, deger2 - deger1);
				break;
				
	            case '*': 
				ekle(yigin, deger2 * deger1); 
				break;
				
	            case '/': 
				ekle(yigin, deger2/deger1); 
				break;
	             
            }
        }
        
    }
    return cikar(yigin);
}
 
int main()
{
    char postfix[] = "8 2 / 1 - 2 3 * + 8 1 * -";		
    
    int uzunluk=sizeof(postfix);
    printf("Postfix:");
	for(int i=0;i<uzunluk;i++){
		printf("%c",postfix[i]);
	}
    printf ("\n\nSonuc:%d", PostfixHesapla(postfix));
    return 0;
}
 
