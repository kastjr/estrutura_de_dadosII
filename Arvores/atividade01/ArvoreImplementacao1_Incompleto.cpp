#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	int info;
    struct arv *esq;
	struct arv *dir;
}Arv;

Arv *arvore(int x,Arv *d,Arv *e){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	return novo;

}

void imprime (No *n){
]   if(raiz == NULL){
    cout<<"\n <VAZIO>";
    }
    else{
    if(n!=NULL){
    cout<<"<"<<n->info;
    imprime(n->esq);
    imprime(n->dir);
    cout<<">";
        }
    }
    else
    cout<<"<>";
    }
}

void emnivel (Arv a){
if (A == NULL)return;
Fila f = fila(MAX);
enfileira(A, F);
while(!vaziaf(F)){
   Arv A = desenfileira(F)
   }
}


main(){

}
