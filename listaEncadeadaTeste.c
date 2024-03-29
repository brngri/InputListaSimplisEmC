#include<stdio.h>
#include<ctype.h>
#include<String.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *next;
}no;

void inserirInicio(no **lista, int num){
    no *novo = malloc(sizeof(no)); // alocou espaço em memória para auxiliar
    if(novo){
        novo->valor = num;
        novo->next = *lista; // *lista = primeiro da lista
        *lista = novo;
    }else{
        printf("\nERRO AO CRIAR O ARQUIVO!");
    }
}

void inserirFim(no **lista, int num){
    no *auxiliar, *novo = malloc(sizeof(no));
    if(novo){
        novo->valor = num;
        novo->next = NULL;
        // é o primeiro?
        if(*lista == NULL){
            *lista = novo;
        }else{
            auxiliar = *lista;
            while(auxiliar->next){
                auxiliar = auxiliar->next;
            }
            auxiliar->next = novo;
        }
    }else{
        printf("\nERRO AO CRIAR O ARQUIVO!");
    }
}

void inserirMeio(no **lista, int num, int ant){
    no *novo, *auxiliar = malloc(sizeof(no));

    if(novo){
        novo->valor = num;
        // é o primeiro?
        if(*lista == NULL){
            novo->next = NULL;
            *lista = novo;
        }else{
            auxiliar = *lista;
            while(auxiliar->valor != ant && auxiliar->next)
                auxiliar = auxiliar->next;
            novo->next = auxiliar->next;
            auxiliar->next = novo;
        }
    }else{
        printf("\nERRO AO CRIAR O ARQUIVO!");
    }
}

void imprimir(no *no){
    printf("\n\n\t----TABELA---");
    while(no){
        printf("\ncodigo: %d", no->valor);
        no = no->next;
    }
    printf("\n\tFim da lista...");
}

int main(){
    no *lista = NULL;
    int controle, valor, anterior;
    do{
        printf("\n\n\t---Lista---");
        printf("\n1 - inserir no inicio\n2 - inserir no meio\n3 - inserir no fim\n4 - imprimir\n0 - sair\n\n>> ");
        scanf("%d", &controle);
        switch(controle){
            case 1:
                printf("\nDigite um valor: ");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;
            case 2:
                printf("\nDigite um valor: ");
                scanf("%d", &valor);
                fflush(stdin);
                printf("\nDigite a variavel de referencia: ");
                scanf("%d", &anterior);
                inserirMeio(&lista,valor,anterior);
                break;
            case 3:
                printf("\nDigite um valor: ");
                scanf("%d", &valor);
                inserirFim(&lista, valor);
                break;
            case 4:
                imprimir(lista);
                break;
            case 0:
                printf("\nSaindo...");
                break;
            default:
                printf("\nOpcao invalida!");
        }
    }while(controle != 0);

    return 0;
}
