#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>


void *funcao_threads(void* valor){
   int valor_func = (int) valor;
   int num_pares = 0;
   int operacoes = (10000*(valor_func+1));

   for(int i = 0; i < operacoes; i++){
      if(i%2 == 0) num_pares++;
   }
   printf("executando thread %d num_pares = %d\n", valor_func, num_pares);
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
}


int main(){ 
   int num_threads = (int)(get_num_nucleos_logicos()/2);
   pthread_t threads[num_threads];
   
   int valores[num_threads];
   for(int i = 0; i <  num_threads; i++) valores[i] = i;

   criar_threads(threads, valores, num_threads);
   aguardar_threads(threads, num_threads);

   return 0;
}