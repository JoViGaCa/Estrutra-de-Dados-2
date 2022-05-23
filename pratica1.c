/*
Alunos:
   João Carvalho 2270340
   Rafael Zaupa 1941399
*/

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void printArray(char tipo[], int *array, int tam, FILE* arq_s, float tempo, int comp){
  fprintf(arq_s,"%s: ", tipo);
  for (int i = 0; i < tam; i++){
    fprintf(arq_s," %i ", array[i]);
  }
  fprintf(arq_s,", %d comp, %f ms\n", comp, tempo);
}

void insertionSort(int* array, int tam, int* comp){
  int i, j;
  int aux;
  for (i = 0; i < tam; i++){
    *comp+= 1;
    aux = array[i];
    j = i-1;
    while (j >= 0 && aux < array[j]){
      array[j+1] = array[j];
      j = j-1;
      array[j+1] = aux;
    }
  }
}

void selectionSort(int *array, int tam, int* comp){
  int menor;
  int aux;
  int i;
  for (i = 0; i < tam; i++){
    menor = i;
    *comp += 1;
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
  }
}

void bubbleSort(int *v, int tam, int*comp){
   bool troca = true;
   int aux;
   while(troca){
     troca = false;
     for (int i = 0; i <= tam-2; i++){
       *comp += 1;
       if(v[i] > v[i+1]){
         aux = v[i];
         v[i] = v[i+1];
         v[i+1] = aux;
         troca = true;
       }
     }
   }
}

void merge(int *v, int start, int middle, int end) {
  int *temp;
  int i, j, k, p1, p2;


 bool finished1, finished2;
 finished1 = 0;
 finished2 = 0;

  int vecSize = (end - start) + 1;

  p1 = start;
  p2 = middle + 1;

  temp = (int*) malloc(vecSize * sizeof(int));

  if(temp != NULL) {
    for(i = 0; i < vecSize; i++) {

      if(!finished1 && !finished2) {
        if(v[p1] < v[p2]) {
          temp[i] = v[p1];
          p1++;
        } else {
          temp[i] = v[p2];
          p2++;
        }

      if(p1 > middle) finished1 = 1;
      if(p2 > end)    finished2 = 1;

     } else {

        if(!finished1){
          temp[i] = v[p1];
          p1++;
        }else{
          temp[i] = v[p2];
          p2++;
        }
      }

    }
    for(j=0, k=start; j<vecSize; j++, k++) {
      v[k] = temp[j];
   }
  }
  free(temp);
}

/* ------------------------------------------------------- */
/* ------------------------------------------------------- */
void mergeSort(int *v, int start, int end, int* comp) {
  int middle;
  if(start < end) {
    middle = (int)floor((start + end)/2);
    mergeSort(v, start, middle, comp);
    mergeSort(v,middle+1,end, comp);
    *comp += 1;
    merge(v, start, middle, end);
  }
}

int particiona(int *v, int inicio, int fim){
  int esq = inicio;
  int dir = fim;
  int pivo = v[inicio];
  while(esq < dir){
    while(v[esq] <= pivo && esq <= fim){
      esq++;
    }
    while(v[dir] > pivo && dir  >= inicio){
      dir--;
    }
    if (esq < dir){
      int aux = v[dir];
      v[dir] = v[esq];
      v[esq] = aux;
    }
  }
  int aux1 = v[dir];
  v[dir] = v[inicio];
  v[inicio] = aux1;
  return dir;
}


void quickSort(int* v, int inicio, int fim, int* comp){
  int pivo;
  if(inicio < fim){
    pivo = particiona(v, inicio, fim);
    quickSort(v, inicio, pivo-1, comp);
    quickSort(v, pivo+1, fim, comp);
    *comp += 1;
  }
}



int main(int argc, const char * argv[]){
  // if(argc != 3){
  //   printf("Erro na entrada de argumentos\n");
  //   exit(1);
  // }

  //abre os arquivos
  FILE* arq_e = fopen("input1.txt","r");
  FILE* arq_s = fopen("output1.txt","w");
  char opcao;
  int numero;
  time_t tempo;
  float start;
  float tempo_funcao;

  //recebe os valores dos arquivos
  if( (fscanf(arq_e,"%d\n%c", &numero, &opcao)) != 2){
    printf("Arquivo Inválido\n");
    fprintf(arq_s, "Arquivo Inválido\n");
    exit(1);
  }

  int *vetor = malloc(numero*sizeof(int));
  int *vetor2 = malloc(numero*sizeof(int));

  srand((unsigned)time(&tempo));

  //recebe o método de geração do vetor de acordo com o input do usuário
  switch(opcao){
    case 'c':
      for(int i = 0; i < numero; i++){
        vetor[i]= 1 + i;
      }
      break;
    case 'd':
      for(int i = 0; i < numero; i++){
        vetor[i]= numero - i;
      }
      break;
    case 'r':
      for(int i = 0; i < numero; i++){
        vetor[i] = rand()%32000;
      }
        break;
    default:
      fprintf(arq_s, "Arquivo inválido.");
      exit(1);
  }

  //passa o conteudo do vetor 1 para o 2 para poder resetar o vetor 1 dps
  for (int i = 0; i< numero; i++){
    vetor2[i] = vetor[i];
  }

  //reseta os parametros e chama a função
  int comp = 0;
  start = clock();
  insertionSort(vetor, numero, &comp);
  tempo_funcao = ((clock()-start)*1E3/CLOCKS_PER_SEC);
  printArray("InsertionSort",vetor, numero, arq_s, tempo_funcao, comp);


  //reseta os parametros e chama a função
  for(int i = 0; i < numero; i++){
    vetor[i] = vetor2[i];
  }
  comp = 0;
  start = clock();
  selectionSort(vetor, numero, &comp);
  tempo_funcao = ((clock()-start)*1E3/CLOCKS_PER_SEC);
  printArray("SelectionSort", vetor, numero, arq_s, tempo_funcao, comp);


  //reseta os parametros e chama a função
  for (int i = 0; i< numero; i++){
    vetor[i] = vetor2[i];
  }
  comp = 0;
  start = clock();
  bubbleSort(vetor, numero, &comp);
  tempo_funcao = ((clock()-start)*1E3/CLOCKS_PER_SEC);
  printArray("BubbleSort", vetor, numero, arq_s, tempo_funcao, comp);


  //reseta os parametros e chama a função
  for (int i = 0; i< numero; i++){
    vetor[i] = vetor2[i];
  }
  comp = 0;
  start = clock();
  mergeSort(vetor, 0, numero-1, &comp);
  tempo_funcao = ((clock()-start)*1E3/CLOCKS_PER_SEC);
  printArray("MergeSort", vetor, numero, arq_s, tempo_funcao, comp);


  //reseta os parametros e chama a função
  for (int i = 0; i< numero; i++){
    vetor[i] = vetor2[i];
  }
  comp = 0;
  start = clock();
  quickSort(vetor, 0, numero-1, &comp);
  tempo_funcao = ((clock()-start)*1E3/CLOCKS_PER_SEC);
  printArray("QuickSort", vetor, numero, arq_s, tempo_funcao, comp);


  fclose(arq_s);
  fclose(arq_e);

  free(vetor);
  free(vetor2);

  return 0;
}
