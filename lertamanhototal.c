#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
  char codigo[4];
  char nome[31];
  char sexo[2];
  char idade[4];
  char area[31];
  char telefone[15];
} Professor;

int main(){
  FILE* arq_s = fopen("output2.txt", "r");
  Professor p;
  char c[2];
  fscanf(arq_s, "%2s", c);
  int tam = atoi(c);
  printf("%s %d\n", c, tam);
  char* string = (char*) malloc(tam * sizeof(char));
  fgets(string, tam+1, arq_s);
  printf("%s\n", string);
  char*palavra;
  palavra = strtok(string,"|");
  strcpy(p.codigo,palavra);
  printf("%s\n", p.codigo);
  palavra = strtok(NULL, "|");
  strcpy(p.nome,palavra);
  printf("%s\n", p.nome);
  palavra = strtok(NULL, "|");
  strcpy(p.sexo,palavra);
  printf("%s\n", p.sexo);
  palavra = strtok(NULL, "|");
  strcpy(p.idade,palavra);
  printf("%s\n", p.idade);
  palavra = strtok(NULL, "|");
  strcpy(p.area, palavra);
  printf("%s\n", p.area);
  palavra = strtok(NULL, "|\0");
  strcpy(p.telefone,palavra);
  printf("%s\n", p.telefone);


  return 0;
}
