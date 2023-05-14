#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
   calcula a quantidade de numeros primos de um vetor
*/
long calcular_numeros_primos(long* numeros, long tamanho_vetor){
   long numeros_primos = 0;
   long divisoes = 0;
   long valor = 0;

   for(long indice = 0; indice < tamanho_vetor; indice++){
      divisoes = 0;
      valor = numeros[indice];
      for(long i = 1; i <= valor; i++){
         if(valor % i == 0) divisoes ++;
      }
      if(divisoes == 2) numeros_primos++;
   }

   return numeros_primos;
}

/**
 * calcula se um valor especifico é primo 
*/
bool numero_primo(int valor){
   int divisoes = 0;
   for(int i = 1; i <= valor; i++){
      if(valor % i == 0) divisoes ++;
   }
   if(divisoes == 2) true;
   else false;
}


int main(){

   //criação do vetor
   long tamanho_vetor = 100;
   long* vetor_numeros = (long*) malloc(tamanho_vetor * sizeof(long));
   for(long i = 0; i < tamanho_vetor; i++) vetor_numeros[i] = i;

   long numeros_primos = calcular_numeros_primos(vetor_numeros, tamanho_vetor);

   printf("Numeros primos entre %ld e %ld: %ld\n", vetor_numeros[0], vetor_numeros[tamanho_vetor-1], numeros_primos);

   return 0;
}