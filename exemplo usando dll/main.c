#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main(){
   Lista_Encadeada* lista = LE_inicializar_lista();
   for(int i = 0; i < 10; i++) LE_adicionar_fim(lista, i);

   LE_exibir_lista(lista);
   LE_editar_item(lista, -1, 0);
   
   int tamanho = lista->tamanho;
   for(int i = 0; i < tamanho; i++) printf("[%d]", LE_obter_item(lista, i)->valor);
   printf("\n");

   printf("tamanho lista: %d\n", lista->tamanho);

   system("pause");
}