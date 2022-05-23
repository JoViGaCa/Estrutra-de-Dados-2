#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/* ------------------------------------------------------- */
/* ------------------------------------------------------- */
int count = 0;
void printArray(int *array, int tam){
  printf("Vetor =");
  for (int i = 0; i < tam; i++){
    printf(" %i ", array[i]);
  }
  printf("\n");
}

void merge(int *v, int start, int middle, int end) {
  count++;
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
void mergeSort(int *v, int start, int end) {
   //printArray(v, (end - start) + 1);
  int middle;
  if(start < end) {
    middle = (int)floor((start + end)/2);
    //printf("%i -- %i -- %i\n", start, middle, end);
    mergeSort(v, start, middle);
    mergeSort(v,middle+1,end);
    merge(v, start, middle, end);
  }
}


/* ------------------------------------------------------- */
/* ------------------------------------------------------- */

int main(int argc, const char * argv[]) {

  int v[] = {45, 36, 2, 8, 0, 1, 23, 7, 5, 10};
  mergeSort(v, 0, 9);
  printArray(v, 10);

  return 0;
}

/* ------------------------------------------------------- */
/* ------------------------------------------------------- */
