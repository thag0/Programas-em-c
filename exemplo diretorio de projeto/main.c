#include "lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
   Lista_Encadeada* lista = inicializar_lista();
   for(int i = 0; i < 10; i++) adicionar_no_fim(lista, (i+1));
   adicionar_no_em(lista, 99, 3);
   visualizar_lista(lista);
   
   system("pause");
}