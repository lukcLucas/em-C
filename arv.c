struct No{
   int num;
   struct No *esq;
   struct No * dir;
};
typedef struct No no; //typedef permite ao programador definir um novo nome para um determinado tipo.

void CriarArvore(no **pRaiz){

    *pRaiz = NULL;

}

//insercao

void insercao(no **pRaiz, int num2)
{
	if (*pRaiz == NULL)
	{
	      *pRaiz=(no *)malloc(sizeof (no));
	      (*pRaiz)->esq=NULL;
	      (*pRaiz)->dir=NULL;
	      (*pRaiz)->num=num2;
	}
	else 
        {
		if (num2 < ((*pRaiz)->num))
		{
			insercao(&((*pRaiz)->esq), num2);
		}
		else
		{
			insercao(&((*pRaiz)->dir), num2);
		}
	}
}

//remocao

no *MaiorDireita(no **no)
{
    if((*no)->dir != NULL)
    {
       return MaiorDireita(&(*no)->dir);
    }
    else
    {
       no *aux = *no;
       
       if((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
        {
          *no = (*no)->esq;
        }
        else
        {
            *no = NULL;
            return aux;
        }
    }
        
}

no *MenorEsquerda(no **no)
{
    if((*no)->esq != NULL)
    {
       return MenorEsquerda(&(*no)->esq);
    }
    else
    {
        no *aux = *no; 
        if((*no)->dir != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
        {
          *no = (*no)->dir;
        }
        else
        {
          *no = NULL;
        }
        return aux;
    }
}

void remover(no **pRaiz, int num){
    if(*pRaiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Numero nao existe na arvore!");
       getch();
       return;
    }
    if(num < (*pRaiz)->num)
       remover(&(*pRaiz)->esq, num);
    else 
       if(num > (*pRaiz)->num)
          remover(&(*pRaiz)->dir, num);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          no *pAux = *pRaiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)){         // se nao houver filhos...
                free(pAux);
                (*pRaiz) = NULL; 
               }
          else{     // so tem o filho da direita
             if ((*pRaiz)->esq == NULL){
                (*pRaiz) = (*pRaiz)->dir;
                pAux->dir = NULL;
                free(pAux); pAux = NULL;
                }
             else{            //so tem filho da esquerda
                if ((*pRaiz)->dir == NULL){
                    (*pRaiz) = (*pRaiz)->esq;
                    pAux->esq = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{       //Escolhi fazer o maior filho direito da subarvore esquerda.
                   pAux = MaiorDireita(&(*pRaiz)->esq); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                   pAux->esq = (*pRaiz)->esq;          //        pAux = MenorEsquerda(&(*pRaiz)->direita);
                   pAux->dir = (*pRaiz)->dir;
                   (*pRaiz)->esq = (*pRaiz)->dir = NULL;
                   free((*pRaiz));  *pRaiz = pAux;  pAux = NULL;   
                   }
                }
             }
          }
}

// em ordem 
void exibirEmOrdem(no *pRaiz){
    if(pRaiz != NULL){
        exibirEmOrdem(pRaiz->esq);
        printf("\n%i", pRaiz->num);
        exibirEmOrdem(pRaiz->dir);
    }
}

// Pre-ordem

void exibirPreOrdem(no *pRaiz){
    if(pRaiz != NULL){
        printf("\n%i", pRaiz->num);
        exibirPreOrdem(pRaiz->esq);
        exibirPreOrdem(pRaiz->dir);
    }
}

//pos-ordem

void exibirPosOrdem(no *pRaiz){
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->esq);
        exibirPosOrdem(pRaiz->dir);
        printf("\n%i", pRaiz->num);
    }
}

//contar nos

int contarNos(no *pRaiz){
   if(pRaiz == NULL)
        return 0;
   else
        return 1 + contarNos(pRaiz->esq) + contarNos(pRaiz->dir);

}

//contar folha 

int contarFolhas(no *pRaiz){
   if(pRaiz == NULL)
        return 0;
   if(pRaiz->esq == NULL && pRaiz->dir == NULL)
        return 1;
   return contarFolhas(pRaiz->esq) + contarFolhas(pRaiz->dir);
}

// altura da arvore

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}//maior



int altura(no *pRaiz){
   if((pRaiz == NULL) || (pRaiz->esq == NULL && pRaiz->dir == NULL))
       return 0;
   else
       return 1 + maior(altura(pRaiz->esq), altura(pRaiz->dir));

}


