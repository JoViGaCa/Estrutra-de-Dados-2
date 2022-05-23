#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
 char last[11];
 char first[11];
 char address[16];
 char city[16];
 char state[3];
 char zip[10];
} Person;

void writeFixedLenghts(FILE *arq, Person pessoa){
  fprintf(arq,"%10s", pessoa.last);
  fprintf(arq,"%10s", pessoa.first);
  fprintf(arq,"%16s", pessoa.address);
  fprintf(arq,"%16s", pessoa.city);
  fprintf(arq,"%2s", pessoa.state);
  fprintf(arq,"%9s\n", pessoa.zip);
}

void writeLenghtIndicators(FILE *arq, Person pessoa){
  fprintf(arq,"0%d%s",(int)strlen(pessoa.last),pessoa.last);
  fprintf(arq,"0%d%s",(int)strlen(pessoa.first), pessoa.first);
  fprintf(arq,"0%d%s",(int)strlen(pessoa.address), pessoa.address);
  fprintf(arq,"0%d%s",(int)strlen(pessoa.city), pessoa.city);
  fprintf(arq,"0%d%s",(int)strlen(pessoa.state), pessoa.state);
  fprintf(arq,"0%d%s\n",(int)strlen(pessoa.zip), pessoa.zip);
}

void writeKeywordTags(FILE* arq, Person pessoa){
  fprintf(arq,"last=%s|", pessoa.last);
  fprintf(arq,"first=%s|", pessoa.first);
  fprintf(arq,"address=%s|", pessoa.address);
  fprintf(arq,"city=%s|", pessoa.city);
  fprintf(arq,"state=%s|", pessoa.state);
  fprintf(arq,"zip=%s\n", pessoa.zip);
}


int main(){
  FILE * arq = fopen("Teste.txt", "w");
  Person pessoa;
  strcpy(pessoa.first, "Joao");
  strcpy(pessoa.last, "Carvalho");
  strcpy(pessoa.address, "47 Bakker");
  strcpy(pessoa.city, "Apucarana");
  strcpy(pessoa.state, "PR");
  strcpy(pessoa.zip, "2270340");

  writeFixedLenghts(arq, pessoa);
  fprintf(arq,"\n ------------- \n");
  writeLenghtIndicators(arq,pessoa);
  fprintf(arq,"\n ------------- \n");
  writeKeywordTags(arq,pessoa);

  fclose(arq);


  return 0;
}
