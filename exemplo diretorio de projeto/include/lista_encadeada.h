#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct No {
   int valor;
   struct No* proximo;
} No;

typedef struct Lista_Encadeada {
   No* inicio;
   int tamanho;
} Lista_Encadeada;

Lista_Encadeada* inicializar_lista();
void adicionar_no_fim(Lista_Encadeada* lista, int valor);
void adicionar_no_inicio(Lista_Encadeada* lista, int valor);
void adicionar_no_em(Lista_Encadeada* lista, int valor, int indice);
void remover_primeiro_no(Lista_Encadeada* lista);
void remover_ultimo_no(Lista_Encadeada* lista);
void remover_no_em(Lista_Encadeada* lista, int indice);
void visualizar_lista(Lista_Encadeada* lista);
No* obter_item(Lista_Encadeada* lista, int indice);

#endif