#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;
    struct node *prox;
};

struct fila
{
    struct node *inicio;
    struct node *fim;
    int tam;
};

void inserir(struct fila *a_fila, int value){
    struct node *novo;
    novo = malloc(sizeof(struct node));

    if (a_fila->inicio == NULL){
        novo->valor = value;
        a_fila->inicio = novo;
        a_fila->fim = novo;
        novo->prox = NULL;
    } else{
        novo->valor = value;
        a_fila->fim->prox = novo;
        a_fila->fim = novo;
        novo->prox = NULL;
    }
}

void printar(struct fila *a_fila){
    struct node *aux;
    aux = a_fila->inicio;

    while (aux != NULL)
    {
        printf("%d", aux->valor);
        if(aux->prox == NULL){
            printf(" ");
        }
        aux = aux->prox;
    }
    free(aux);
}

void pop(struct fila *a_fila){
    if(a_fila->inicio != NULL){
        struct node *aux;
        aux = a_fila->inicio;
        a_fila->inicio = aux->prox;
        free(aux);
    } else {
        printf("Fila esta vazia\n");
        return;
    }
}

int main()
{

    int op;
    int value;

    struct fila *a_fila;
    a_fila = malloc(sizeof(struct fila));
    a_fila->fim = NULL;
    a_fila->inicio = NULL;

    printf("1- Inserir\n2- Mostrar Fista\n3- Excluir da Fila\n");

    while (1)
    {

        scanf("%d", &op);

        if (op == 1)
        {
            printf("Valor: ");
            scanf("%d", &value);
            inserir(a_fila, value);
        }
        else if (op == 2)
        {
            printar(a_fila);
            printf("\n");
        } else if(op == 3){
            pop(a_fila);
        }
        else
        {
            return 0;
        }
    }

    return 0;
}
