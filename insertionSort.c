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

void insertionSort(int* array, int tam){
  int i, j;
  int aux;
  for (i = 0; i < tam; i++){
    aux = array[i];
    j = i-1;
    while (j >= 0 && aux < array[j]){
      array[j+1] = array[j];
      j = j-1;
      array[j+1] = aux;
    }
    printArray(array,tam);
  }
}



int main(){
  int array[7] = {23,4,67,-8,90,54,21};
  printArray(array,7);
  insertionSort(array, 7);

  return 0;
}
