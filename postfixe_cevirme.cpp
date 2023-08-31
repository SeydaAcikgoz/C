#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Yigin {
    int karakter;
    int kapasite;
    int* dizi;
}Yigin;
  
struct Yigin* YiginOlustur(int kapasite){
    struct Yigin* yigin= (struct Yigin*)malloc(sizeof(struct Yigin));
  
    if (!yigin)
        return NULL;
	
    yigin->karakter = -1;
    yigin->kapasite = kapasite;
  
    yigin->dizi= (int*)malloc(yigin->kapasite * sizeof(int));
  
    return yigin;
}
  
int BosMu(struct Yigin* yigin){
    return yigin->karakter == -1;
}
  
char peek(struct Yigin* yigin){
    return yigin->dizi[yigin->karakter];
}
  
char cikar(struct Yigin* yigin){
    if (!BosMu(yigin))
        return yigin->dizi[yigin->karakter--];
    return 0;
}
  
ekle(struct Yigin* yigin, char sonuc){
    yigin->dizi[++yigin->karakter] = sonuc;
}
  

int kontrol(char ch){
	if((ch >= 'a' && ch <= 'z')|| (ch >= 'A' && ch <= 'Z')){
		return 1;
	}
   	else{
		return 0;
   }
}
  

int oncelikbul(char ch){
    	if(ch=='+' || ch=='-'){
		return 1;
	}
	else if(ch=='*' || ch=='/'){
		return 2;
	}
	else{
		return -1;
	}
}

int infixToPostfix(char* postfix){
    int i, k;
   
    struct Yigin* yigin = YiginOlustur(strlen(postfix));
    if (!yigin) 
        return -1;
  
    for (i = 0, k = -1; postfix[i]; ++i) {
        if (kontrol(postfix[i])){
        	postfix[++k] = postfix[i];
		}
       
        else if (postfix[i] == '('){
        	ekle(yigin, postfix[i]);

		}
  
        else if (postfix[i] == ')') {
            while (!BosMu(yigin) && peek(yigin) != '('){
            	 postfix[++k] = cikar(yigin);

			}
               
            if (!BosMu(yigin) && peek(yigin) != '('){
            	return -1; 
		}
			
            else{
            	cikar(yigin);
		}
        }
  
        else{
            while (!BosMu(yigin) && oncelikbul(postfix[i]) <= oncelikbul(peek(yigin))){
            	postfix[++k] = cikar(yigin);
			}
            ekle(yigin, postfix[i]);
        }
        printf("\n%s\t", postfix);
    }
  
    while (!BosMu(yigin)){
        postfix[++k] = cikar(yigin);
	}
  
    postfix[++k] = '\0';
    printf("\nPostfix sonucu:%s", postfix);
}
  
int main()
{
    char postfix[] = "((a/b)-c)+(d*e)-(a*c)";
    infixToPostfix(postfix);
    return 0;
}
