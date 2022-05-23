#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int *v, int tam){
   bool troca = true;
   int aux;
   while(troca){
     troca = false;
     for (int i = 0; i <= tam-2; i++){
       if(v[i] > v[i+1]){
         aux = v[i];
         v[i] = v[i+1];
         v[i+1] = aux;
         troca = true;
       }
     }
   }
}



int main(){
  int vetor[] = {30,14,10,13,37,80,1,3,26,5};
  for (int i = 0; i < 10; i++){
    printf(" %i -", vetor[i]);
  }
  printf("\n");
  bubbleSort(vetor, 10);
  for (int i = 0; i < 10; i++){
    printf(" %i -", vetor[i]);
  }
  printf("\n");



}
