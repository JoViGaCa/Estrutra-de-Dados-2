#include <stdlib.h>
#include <stdio.h>

int buscaLinear(int *v, int n, int elem){
// testa todas as posições até encontrar o elemento desejado ou chegar no final do vetor
  int i;
  for ( i = 0; i < n; i++){
    if(v[i] == elem){
      printf("Contador: %i\n", i+1);
      return i;
    }
  }
  printf("Contador: %i\n", i+1);
  return -1;
}

int buscaOrdenada(int *v, int n, int elem){
//testa todas as posições até encontrar o elemento desejado ou encontrar um
//    valor maior que o desejado ou até o final do vetor
  int i;
  for ( i = 0; i < n; i++){
    if(v[i] == elem){
      printf("Contador: %i\n", i+1);
      return i;
    } else if (v[i] > elem){
      return -1;
      // ou pode usar break;
    }
  }
  printf("Contador: %i\n", i+1);
  return -1;

}


int buscaBinaria(int *v, int i, int f, int elem){
// Divisão e conquista, calcula o elemento médio e varifica se o
//    elemento é maior ou menor que o meio
  int med = (i + f)/2;
  int ret;
  if (elem <= v[med]){
    if (elem == v[med]){
      return 1;
    } else{
      if(i == f){
        return -1;
      } else {
        ret = 1 + buscaBinaria(v,i,f/2,elem);
        return ret;
      }
    }
  } else {
    if(i == f){
      return -1;
    } else {
      ret = 1 + buscaBinaria(v,f/2,f,elem);
      return ret;
    }
  }
}



int main(){
  int vetor[] = {30,14,10,13,37,80,1,3,26,5};
  int vetor2[] = {1,3,5,10,13,14,26,30,37,80};
  int busca;
  int busca2;
  int busca3;

  busca = buscaLinear(vetor,10,5);
  printf("Índice da busca linear: %i\n", busca);

  busca2 = buscaOrdenada(vetor2,10,5);
  printf("Índice da busca ordenada: %i\n", busca2);

  busca3 = buscaBinaria(vetor2,0,10,3);
  printf("Índice da busca binária: %i\n", busca3);


}
