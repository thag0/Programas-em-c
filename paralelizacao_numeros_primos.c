#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define TAMANHO_VETOR 100000

pthread_mutex_t mutex;

typedef struct{
   long indice_inicio;
   long indice_fim;
   long* numeros_primos;
   long* vetor_numeros;
} Dados;


void* calcular_numeros_primos(void* args){
   long divisoes = 0;
   long valor = 0;

   Dados* dados = (Dados*) args;
   long* vetor_numeros = dados->vetor_numeros;
   long inicio = dados->indice_inicio;
   long fim = dados->indice_fim;

   /*
      cada thread fica responsavel pelo mesmo vetor
      mas vai trabalhar entre um certo intervalo de indices
      como se fossem mini vetores virtuais
   */
   for(long indice = inicio; indice < fim; indice++){
      divisoes = 0;
      valor = vetor_numeros[indice];

      for(long i = 1; i <= valor; i++){
         if(valor % i == 0) divisoes ++;
      }

      if(divisoes == 2){
         pthread_mutex_lock(&mutex);
         (*dados->numeros_primos) += 1;
         pthread_mutex_unlock(&mutex);
      }
   }
}


int main(){
   //criação do vetor
   long tamanho_vetor = TAMANHO_VETOR;
   long* vetor_numeros = (long*) malloc(tamanho_vetor * sizeof(long));
   for(long i = 0; i < tamanho_vetor; i++) vetor_numeros[i] = i;

   long* numeros_primos = (long*) malloc(sizeof(long));
   *numeros_primos = 0;

   //dados de threads
   pthread_t threads[NUM_THREADS];
   Dados* dados = (Dados*) malloc(NUM_THREADS * sizeof(Dados));
   long indice_inicio = 0;
   long indice_fim = (long) tamanho_vetor/NUM_THREADS;
   
   pthread_mutex_init(&mutex, NULL);
   for(int i = 0; i < NUM_THREADS; i++){
      dados[i].indice_inicio = indice_inicio;
      dados[i].indice_fim = indice_inicio + indice_fim;
      indice_inicio += indice_fim;

      dados[i].numeros_primos = numeros_primos;
      dados[i].vetor_numeros = vetor_numeros;

      pthread_create(&threads[i], NULL, calcular_numeros_primos, (void*) &dados[i]);
   }
   
   for(int i = 0; i < NUM_THREADS; i++){
      pthread_join(threads[i], NULL);
   }
   pthread_mutex_destroy(&mutex);

   printf("Numeros primos entre %ld e %ld: %ld\n", vetor_numeros[0], vetor_numeros[tamanho_vetor-1],*numeros_primos);

   free(dados);
   free(vetor_numeros);
   free(numeros_primos);

   return 0;
}