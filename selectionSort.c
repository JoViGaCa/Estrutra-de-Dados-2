#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void printArray(int *array, int tam){
  printf("Vetor =");
  for (int i = 0; i < tam; i++){
    printf(" %i ", array[i]);
  }
  printf("\n");
}


void selectionSort(int *array, int tam){
  int menor;
  int aux;
  int i;
  for (i = 0; i < tam; i++){
    menor = i;
    for(int j = i; j < tam; j++){
      if(array[menor] > array[j]){
        menor = j;
      }
    }
    if(array[menor] < array[i]){
      aux = array[menor];
      array[menor] = array[i];
      array[i] = aux;
    }
    printArray(array, tam);
  }
}



int main(){
  int array[7] = {23,4,67,-8,90,54,21};
  printArray(array,7);
  selectionSort(array,7);

  return 0;
}
