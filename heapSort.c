#include <stdlib.h>
#include <stdio.h>

void printArray(int *array, int tam){
  printf("Vetor =");
  for (int i = 0; i < tam; i++){
    printf(" %i ", array[i]);
  }
  printf("\n");
}

void criaHeap(int *vet, int i, int f) {
  int aux = vet[i];
  int j = 2*i +1;
  while (j <= f){
    if (j < f){
      if (vet[j] < vet[j+1]){
        j++;
      }
    }
    if (aux < vet[j]){
      vet[i] = vet[j];
      i = j;
      j = 2*i + 1;
    } else {
      j = f+1;
    }
  }
  vet[i] = aux;
}


void heapSort(int *vet, int n){
  int i, aux;
  for(i = (n-1/2); i >= 0; i--){
    criaHeap(vet, i, n-1);
  }
  for(i = n-1; i >= 0; i--){
    aux = vet[0];
    vet[0] = vet[i];
    vet[i] = aux;
    criaHeap(vet, 0, i-1);
  }
}


int main(){
  int array[7] = {23,4,67,-8,90,54,21};
  printArray(array,7);
  heapSort(array,7);
  printArray(array,7);

  return 0;
}
