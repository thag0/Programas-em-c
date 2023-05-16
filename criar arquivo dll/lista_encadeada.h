#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct No{
   int valor;
   struct No* proximo;
}No;

typedef struct Lista_Encadeada{
   No* inicio;
   int tamanho;
}Lista_Encadeada;

Lista_Encadeada* LE_inicializar_lista();
void LE_adicionar_fim(Lista_Encadeada* lista, int valor);
void LE_adicionar_inicio(Lista_Encadeada* lista, int valor);
void LE_adicionar_em(Lista_Encadeada* lista, int valor, int indice);
void LE_remover_fim(Lista_Encadeada* lista);
void LE_remover_inicio(Lista_Encadeada* lista);
void LE_remover_em(Lista_Encadeada* lista, int indice);
void LE_exibir_lista(Lista_Encadeada* lista);
No* LE_obter_item(Lista_Encadeada* lista, int indice);
void LE_editar_item(Lista_Encadeada* lista, int valor, int indice);

#endif