#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>


void *funcao_threads(void* valor){
   int valor_thread = (int) valor;
   long num_pares = 0;
   long operacoes = (10000 * (valor_thread + 1));

   int divisoes = 0, aux;
   for(int i = 0; i < operacoes; i++){
      if(i%2 == 0) num_pares ++; 
   }

   printf("executando thread %d num_pares = %ld\n", valor_thread, num_pares);
   return NULL;
}


void criar_threads(pthread_t threads[], int valores[],int num_threads){
   for(int i = 0; i < num_threads; i++){
      //precisa fazer um casting pra ponteiro do tipo void
      pthread_create(&threads[i], NULL, funcao_threads, (void*) valores[i]);
   }
}


void aguardar_threads(pthread_t threads[], int num_threads){
   for(int i = 0; i < num_threads; i++){
      pthread_join(threads[i], NULL);
   }
}


//só peguei da internet mesmo pra testar mas funciona
int get_num_nucleos_logicos(){
   SYSTEM_INFO sysinfo;
   GetSystemInfo(&sysinfo);
   int num_nucleos = sysinfo.dwNumberOfProcessors;
   num_nucleos /= (int) 2;
   return num_nucleos;
}


int main(){ 
   int num_threads = get_num_nucleos_logicos();
   pthread_t threads[num_threads];
   
   int valores[num_threads];
   for(int i = 0; i <  num_threads; i++) valores[i] = i;

   criar_threads(threads, valores, num_threads);
   aguardar_threads(threads, num_threads);

   return 0;
}