#include <stdlib.h>
#include <stdio.h>

void printArray(int *array, int tam){
  printf("Vetor =");
  for (int i = 0; i < tam; i++){
    printf(" %i ", array[i]);
  }
  printf("\n");
}

int particiona(int *v, int inicio, int fim){
  int esq = inicio;
  int dir = fim;
  int pivo = v[inicio];
  while(esq < dir){
    while(v[esq] <= pivo){
      esq++;
    }
    while(v[dir] > pivo){
      dir--;
    }
    if (esq < dir){
      int aux = v[dir];
      v[dir] = v[esq];
      v[esq] = aux;
    }
  }

  v[inicio] = v[dir];
  v[dir] = pivo;
  return dir;
}


void quickSort(int* v, int inicio, int fim){
  int pivo;
  if(inicio < fim){
    pivo = particiona(v, inicio, fim);
    quickSort(v, inicio, pivo-1);
    quickSort(v, pivo+1, fim);
  }
}

int main(){
  int v[] = {35,15,36,13,1,40,11,17,37,33};
  printArray(v,10);
  quickSort(v, 0, 9);
  printArray(v,10);



  return 0;
}
