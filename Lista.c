#include<stdio.h>
#include<stdlib.h>

//criando lista simplemente encadeada

struct cel
{
   int dados;
   struct cel *prox;
};
typedef struct cel celula;

celula *lista;

int nlem = 0; //tamanho

//adicionar lista 

void addIndex(int dados, int index){
      celula *p = (celula*) malloc(sizeof(celula));
	p->dados = dados;
	
   
   if (index>nlem){
       printf("Posicao invalida");
   }else{
       if (index==0)
       {
           p->prox = lista; 
           lista = p;
       }else{
           celula *listaAux = lista;
           int i =0; //contador
           while(i!=index-1){
             listaAux = listaAux ->prox;
             i++;
           }
           p ->prox = listaAux->prox;
           listaAux->prox = p;
       }
       nlem++;
       
   }

   
   
}

//remocao

void removeIndex(int index)
{
	if(index>nlem || nlem==0){
		printf("Posição Inválida ou Lista Vazia");
	}else{
		if(index==0){
			lista = lista->prox;
		}else{
			celula *listaAux = lista;
			int i=0;
			while(i!=index-1)
			{
				listaAux = listaAux->prox;
				i++;
			}
			listaAux->prox = listaAux->prox->prox;
		}
		nlem--;
	}
}

//funcao para  impressao da lista - recursao

void imprime(celula *p){
    
    if (p!=NULL)
    {
        printf("\n%d", p->dados);
        imprime(p->prox);
    }
    
    
}

int main(int argc, char const *argv[])
{
    addIndex(10,0);
    addIndex(20,1);
    addIndex(30,2);
    addIndex(40,3);
    addIndex(50,4);
    addIndex(60,5);
    addIndex(64,6);

    //removeIndex(0);
	//removeIndex(0);
	//removeIndex(0);
	//removeIndex(0);
	//removeIndex(0);
    celula *auxLista = lista;
    imprime(auxLista);
  return 0;
}
