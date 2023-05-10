#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define TAMANHO_VETOR 90000
#define NUM_THREADS 4


typedef struct{
   long comeco;
   long fim;
   long* vetor_1;
   long* vetor_2;
   long long* produto_escalar;
   pthread_mutex_t* mutex;

}Dados;


void* thread_function(void* arg){
   Dados* dados = (Dados*) arg;

   pthread_mutex_lock(dados->mutex);
   for(long i = dados->comeco; i < dados->fim; i++){
      (*dados->produto_escalar) += dados->vetor_1[i] * dados->vetor_2[i];
   }
   pthread_mutex_unlock(dados->mutex);

   return NULL;
}


int main(){
   //inicialização dos vetores
   long* vetor_1 = (long*) malloc(TAMANHO_VETOR * sizeof(long));
   long* vetor_2 = (long*) malloc(TAMANHO_VETOR * sizeof(long));
   
   for(int i = 0; i < TAMANHO_VETOR; i++){
      vetor_1[i] = i;
      vetor_2[i] = i*2;
   }

   //variavel de resultado
   long long* produto_escalar = (long long*) malloc(sizeof(long long));
   *produto_escalar = 0;
   
   //criação das threads e mutex
   pthread_t threads[NUM_THREADS];
   pthread_mutex_t mutex;
   pthread_mutex_init(&mutex, NULL);

   Dados* dados = (Dados*) malloc(NUM_THREADS * sizeof(Dados));

   //indices virtuais para execução das threads
   long indice_inicial = 0;
   long indice_final = (long) TAMANHO_VETOR/NUM_THREADS;

   for(int i = 0; i < NUM_THREADS; i++){
      dados[i].comeco = indice_inicial;
      dados[i].fim = indice_inicial + indice_final;
      indice_inicial += indice_final;

      dados[i].vetor_1 = vetor_1;
      dados[i].vetor_2 = vetor_2;
      dados[i].mutex = &mutex;
      dados[i].produto_escalar = produto_escalar;

      pthread_create(&threads[i], NULL, thread_function, (void*) &dados[i]);
   }

   for(int i = 0; i < NUM_THREADS; i++){
      pthread_join(threads[i], NULL);
   }

   pthread_mutex_destroy(&mutex);

   printf("Produto escalar = %lld\n", *produto_escalar);
   return 0;
}