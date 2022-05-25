#include<stdio.h>
#include<stdlib.h>

/*
a primeira fazer uma lista encadeada e criar as estruturas
 necessarios,
neste caso, duas estruturas, uma para a lista propriamente
 dita e outra para os nós da lista
 A estrutura nó e bem simples, possuindo um campo do tipo
 inteiro chamado valor(poderia ser qualquer tipo,
 inclusive outro tipo mais complexo)
 e um ponteiro para o proximo.
*/

typedef struct No
{
    int valor;
    struct No *prox;
}No;

/*
 A estrutura lista possuir um ponteiro para um nó chamado inicio,
 o primeiro no de nossa lista, e um segundo campo inteiro para 
 guardar
 o tamanho da lista.aqui acrescentando um segundo ponteiro para
  o fim 

 da lista com a finalidade de facilitar uma insercao de novos
  elementos no final da lista.
 Ressaltamos que este segundo ponteiro e optional e sua 
 inclusao ou nao vai depender da finalidade da lista que esta
  sendo construida.

*/

typedef struct 
{
    No *inicio, *fim;
    int nlem; //tamanho
}Le; // lista encadeada = le

// inserção no início da lista
void inserirInicio(Le *le, int valor) {
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;// (*novo).valor = valor

    if(le->inicio == NULL) { // a lista está vazia
        novo->prox = NULL;
        le->inicio = novo;
        le->fim = novo;
    } else { // a lista não está vazia
        novo->prox = le->inicio;
        le->inicio = novo;
    }
    le->nlem++;
}


// inserir no final da lista
void inserirFim(Le *le, int valor) {
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;
    novo->prox = NULL;

    if(le->inicio == NULL) { // lista vazia
        le->inicio = novo;
        le->fim = novo;
    } else { // lista não vazia
        le->fim->prox = novo;
        le->fim = novo;
    }
    le->nlem++;
}

// imprimir a lista
void imprimir(Le *le) {
    No *inicio = le->inicio;
    printf("Tamanho da lista: %d\n", le->nlem);
    while(inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("\n\n");
}

// remover um elemento da lista
void remover(Le *le, int valor) {
    No *inicio = le->inicio; // ponteiro para o início da lista
    No * noARemover = NULL; // ponteiro para o nó a ser removido

    if(inicio != NULL && le->inicio->valor == valor) { // remover 1º elemento
        noARemover = le->inicio;
        le->inicio = noARemover->prox;
        if(le->inicio == NULL)
            le->fim = NULL;
    } else { // remoção no meio ou no final
        while(inicio != NULL && inicio->prox != NULL && inicio->prox->valor != valor) {
            inicio = inicio->prox;
        }
        if(inicio != NULL && inicio->prox != NULL) {
            noARemover = inicio->prox;
            inicio->prox = noARemover->prox;
            if(inicio->prox == NULL) // se o último elemento for removido
                le->fim = inicio;
        }
    }
    if(noARemover) {
        free(noARemover); // libera a memória do nó
        le->nlem--; // decrementa o tamanho da lista
    }
}

// função que remove e retorna o primeiro nó
No* removerPrimeiroNO(Le *le) {
    if(le->inicio != NULL) {
        No *no = le->inicio;
        le->inicio = no->prox;
        le->nlem--;
        if(le->inicio == NULL)
            le->fim = NULL;
        return no;
    } else
        return NULL;
}


// procedimento que divide uma lista em duas
void dividirLista(Le *le, Le *leI, Le *leP) {
    No *removido;
    while(le->inicio != NULL) {
        removido = removerPrimeiroNO(le);
        inserirFim(leI, removido->valor);
        free(removido);

        removido = removerPrimeiroNO(le);
        if(removido != NULL) {
            inserirFim(leP, removido->valor);
            free(removido);
        }
    }
}


int main() {
    Le le, leI, leP; // criação de 3 listas
    int opcao, valor;

    // inicialização das listas
    le.inicio = NULL;
    le.fim = NULL;
    le.nlem = 0;

    leI.inicio = NULL;
    leI.fim = NULL;
    leI.nlem = 0;

    leP.inicio = NULL;
    leP.fim = NULL;
    leP.nlem = 0;

    do { // menu de opções
        printf("1 - Inserir no inicio\n2 - Imprimir\n3 - Inserir no fim\n4 - Remover\n6 - Dividir lista\n5 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserirInicio(&le, valor);
            break;
        case 2:
            printf("\nLista original:\n");
            imprimir(&le);
            printf("\nLista impar:\n");
            imprimir(&leI);
            printf("\nLista par:\n");
            imprimir(&leP);
            break;
        case 3:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserirFim(&le, valor);
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            remover(&le, valor);
            break;
        case 5:
            printf("Finalizando...\n");
            break;
        case 6:
            dividirLista(&le, &leI, &leP);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while(opcao != 5);

    return 0;
}




