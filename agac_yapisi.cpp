
#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	n*sol;
	n*sag;
}n;
typedef n node;

node * ekle (node *agac , int x){
	if (agac == NULL){
		node * root = (node*)malloc(sizeof(node));
		root -> sol = NULL;
		root -> sag = NULL;
		root -> data =x;
		return root;
	}
	
	if(agac->data < x){
		agac->sag = ekle(agac->sag,x);
		return agac;
 	}
	
	agac->sol = ekle (agac->sol,x);
	return agac;
}

int bul(node *agac,int aranan){
	if(agac==NULL)	return -1;
	if(agac->data==aranan) return 1;
	
	if(bul(agac->sag,aranan)==1) return 1;
	if(bul(agac->sol,aranan)==1) return 1;

return -1;
	
}

int max(node *agac){
	while(agac->sag != NULL)
	agac=agac->sag;
	return agac ->data;
}

int min(node *agac){
	while(agac->sol != NULL)
	agac=agac->sol;
	return agac ->data;
}

void inorderdolas (node *agac){
	if (agac == NULL)
	return;
	inorderdolas(agac->sol);
	printf("%d ",agac->data);
	inorderdolas(agac->sag);
}

void preorderdolas (node *agac){
	if (agac == NULL)
	return;

	printf("%d ",agac->data);
	preorderdolas(agac->sol);
	preorderdolas(agac->sag);
}

void postorderdolas (node *agac){
	if (agac == NULL)
	return;
	postorderdolas(agac->sol);
	postorderdolas(agac->sag);
	printf("%d ",agac->data);
}

node *sil(node *agac,int x){
	if(agac==NULL){
		return NULL;
	}
	
	if(agac->data==x){
		if(agac->sol==NULL &&agac->sag==NULL){
			return NULL;
		}
		if(agac->sag!=NULL){
			agac->data=min(agac->sag);
			agac->sag=sil(agac->sag,min(agac->sag));
			return agac;
		}
		agac->data=max(agac->sol);
		agac->sol=sil(agac->sol,max(agac->sol));
		return  agac;
	}
	if(agac->data<x){
		agac->sag=sil(agac->sag,x);
		return agac;
	}	
		agac->sol=sil(agac->sol,x);
		return agac;
}

int main(){
	node *agac = NULL;
	agac=ekle(agac,12);
	agac=ekle(agac,200);
	agac=ekle(agac,190);
	agac=ekle(agac,213);
	agac=ekle(agac,56);
	agac=ekle(agac,24);
	agac=ekle(agac,18);
	agac=ekle(agac,27);
	agac=ekle(agac,28);
	printf("\nagacin elemanlari (inorder) = ");
	inorderdolas(agac);
	
	printf("\nagacin elemanlari (preorder) = ");
	preorderdolas(agac);
	
	printf("\nagacin elemanlari (postorder) = ");
	postorderdolas(agac);
	
	printf("\n");
	printf("agactaki en buyuk deger = %d \nagactaki en kucuk deger = %d",max(agac),min(agac));
	
	if(bul(agac,190)==1){
		printf("\nAranan eleman agacta yer aliyor.");
	}
	else{
		printf("\nAranan eleman agacta yer almiyor.");
	}
	printf("\n");
	sil(agac,56);
	inorderdolas(agac);
	
	printf("\n");
	sil(agac,213);
	inorderdolas(agac);
	
	printf("\n");
	sil(agac,28);
	inorderdolas(agac);
}
