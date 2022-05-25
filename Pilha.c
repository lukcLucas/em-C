#include <stdio.h>
#include <stdlib.h>

struct prato
{
	char cor;
	struct prato *prox;
};

typedef struct prato Prato;

Prato *pilha;

void add(char cor){
	Prato *p = (Prato*) malloc(sizeof(Prato));
	p->cor = cor;
	p->prox = pilha;
	pilha = p;
}

void rem(){
	if(pilha==NULL){
		printf("Pilha Vazia");
	}else{
		pilha = pilha->prox;
	}
}


void imprime(Prato *p){
	if(p!=NULL){
		printf("\nCor do Prato: %c",p->cor);
		imprime(p->prox);
	}
}

int main(void) {
  	
	add('b');
	add('r');
	add('g');
	add('y');

	rem();
	rem();
	rem();
	rem();

	Prato *pilhaAux = pilha;
	imprime(pilhaAux);

	return 0;
}
