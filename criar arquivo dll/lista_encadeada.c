#include "lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Faz as configurações iniciais. Aloca memória pra lista, inicializa o nó inicial e configura o tamanho
*/
Lista_Encadeada* inicializar_lista(){
   Lista_Encadeada* lista = (Lista_Encadeada*) malloc(sizeof(Lista_Encadeada));
   
   lista->inicio = (No*) malloc(sizeof(No));
   lista->inicio->valor = 0;
   lista->inicio->proximo = NULL;

   lista->tamanho = 1;

   return lista;
}


/**
 * Adiciona um novo nó ao final da lista
*/
void adicionar_no_fim(Lista_Encadeada* lista, int valor){
   No* novo_no = (No*) malloc(sizeof(No));
   novo_no->valor = valor;
   novo_no->proximo = NULL;

   No* no_percorrer = lista->inicio;
   while(no_percorrer->proximo != NULL){
      no_percorrer = no_percorrer->proximo;
   }

   no_percorrer->proximo = novo_no;
   lista->tamanho++;
}

/**
 * Adiciona um novo nó no inicio da lista
*/
void adicionar_no_inicio(Lista_Encadeada* lista, int valor){
   No* novo_no = (No*) malloc(sizeof(No));
   novo_no->valor = valor;

   novo_no->proximo = lista->inicio;
   lista->inicio = novo_no;

   lista->tamanho++;
}


/**
 * Adiciona um novo nó numa posição específica da lista
*/
void adicionar_no_em(Lista_Encadeada* lista, int valor, int indice){
   if(indice < 0) return;
   if(indice > lista->tamanho-1) return;

   int contador = 0;
   No* no_percorrer = lista->inicio;
   while(contador != indice-1){
      no_percorrer = no_percorrer->proximo;
      contador++;
   }
   No* novo_no = (No*) malloc(sizeof(No));
   novo_no->valor = valor;

   novo_no->proximo = no_percorrer->proximo;
   no_percorrer->proximo = novo_no;

   lista->tamanho++;
}


/**
 * Remove o nó no inicio da lista
*/
void remover_primeiro_no(Lista_Encadeada* lista){
   if(lista->tamanho == 0) return;
   lista->inicio = lista->inicio->proximo;
   lista->tamanho--;
}


/**
 * Remove o nó no final da lista
*/
void remover_ultimo_no(Lista_Encadeada* lista){
   if(lista->tamanho == 0) return;
   
   if(lista->tamanho == 1){
      lista->inicio = NULL;
      lista->tamanho--;
      return;
   }

   No* no_percorrer = lista->inicio;
   while(no_percorrer->proximo->proximo != NULL){
      no_percorrer = no_percorrer->proximo;
   }
   no_percorrer->proximo = NULL;   
   lista->tamanho--;
}


/**
 * Remove um nó num indice específico da lista
*/
void remover_no_em(Lista_Encadeada* lista, int indice){
   if(indice < 0) return;
   if(indice > lista->tamanho-1) return;
   if(indice == 0)remover_primeiro_no(lista);

   No* no_percorrer = lista->inicio;
   for(int i = 0; i < i-1; i++){
      no_percorrer = no_percorrer->proximo;
   }

   no_percorrer->proximo = no_percorrer->proximo->proximo;
   lista->tamanho--;
}


/**
 * Exibe uma mensagem com todos os elementos da lista e seus valores
*/
void visualizar_lista(Lista_Encadeada* lista){
   No* no_percorrer = lista->inicio;
   while(no_percorrer != NULL){
      printf("[%d]", no_percorrer->valor);
      no_percorrer = no_percorrer->proximo;
   }
   printf("\n");
}


/**
 * Retorna um nó num indice específico, retorna nulo caso saia dos limites da lista
*/
No* obter_item(Lista_Encadeada* lista, int indice){
   if(indice < 0) return NULL;
   if(indice > lista->tamanho-1) return NULL;

   No* no_percorrer = lista->inicio;
   int contador = 0;
   while(contador != indice){
      no_percorrer = no_percorrer->proximo;
      contador++;
   }
   return no_percorrer;
}