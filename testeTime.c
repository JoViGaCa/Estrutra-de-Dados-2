#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  float start = clock();
  for(int i = 0; i < 500000000; i++){
  }
  float end = clock();
  printf("%f\n", end-start);



}
