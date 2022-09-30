#include <stdio.h>
#include <stdlib.h>

struct pilha
{
        struct node *topo;
};

struct node
{
        int valor;
        struct node *proximo;
};

void empilhar(struct pilha *a_pilha){
        struct node *novo;
        novo = malloc(sizeof(struct node));

        novo->proximo = a_pilha->topo;
        novo->valor = 0;

        a_pilha->topo = novo;
}

void printar(struct pilha *a_pilha){

        struct node *a = NULL;
        a = a_pilha->topo;

        while (a != NULL)
        {
                printf("%d ", a->valor);
                if(a->proximo != NULL){
                        printf(" ");
                }
                a = a->proximo;
        }
        free(a);
}

void pop(struct pilha *a_pilha){
        struct node *p;
        if(a_pilha->topo != NULL){
                p = a_pilha->topo;
                a_pilha->topo = p->proximo;
                p->proximo = NULL;
                free(p);
        } else {
                printf("A pilha esta vazia\n");
                return;
        }
}


int main(){

        int op;
        struct pilha *a_pilha;
        a_pilha = malloc(sizeof(struct pilha));
        a_pilha->topo = NULL;

        while(1){
                scanf("%d", &op);

                if(op == 1){
                        empilhar(a_pilha);
                } else if(op == 2){
                        printar(a_pilha);
                        printf("\n");
                } else {
                        pop(a_pilha);
                }
        }

        return 0;
}