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

void escreverRegisTamFix(FILE* arq_s, Professor* p, int tam){
  for(int i = 0; i < tam; i++){
    fprintf(arq_s,"%-3s|%-30s|%-1s|%-3s|%-30s|%-14s\n",p[i].codigo,p[i].nome,p[i].sexo,p[i].idade,p[i].area,p[i].telefone);
  }
}

void escreverRegisIndTam(FILE* arq_s, Professor* p, int tam){
  for(int i = 0; i < tam; i++){
    int ind = strlen(p[i].codigo)+strlen(p[i].nome)+strlen(p[i].sexo)+strlen(p[i].idade)+strlen(p[i].area)+strlen(p[i].telefone) + 6;
    fprintf(arq_s,"%d %s|%s|%s|%s|%s|%s|",ind, p[i].codigo,p[i].nome,p[i].sexo,p[i].idade,p[i].area,p[i].telefone);
  }
}

void escreverRegisDel(FILE* arq_s, Professor* p, int tam){
  for(int i = 0; i < tam; i++){
    fprintf(arq_s,"%s|%s|%s|%s|%s|%s|#",p[i].codigo,p[i].nome,p[i].sexo,p[i].idade,p[i].area,p[i].telefone);
  }
}

int main(){
  FILE* arq_e = fopen("input2.txt", "r"); // arquivo entrada
  FILE* arq_s = fopen("output2.txt", "w"); // arquivo saida
  Professor* p = (Professor*) malloc(sizeof(Professor)); // vetor de um para colocar mais depois se precisar

  int tam = 0;
  char c;

  while(true){
    c = fgetc(arq_e);
    if(c == '{'){
      //aumenta o tamanho do vetor e realoca o mesmo
      tam++;
      p = (Professor*) realloc(p,tam*sizeof(Professor));
      //consegue os dados
      fscanf(arq_e,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^}]}",
                   p[tam-1].codigo,p[tam-1].nome,p[tam-1].sexo,p[tam-1].idade,p[tam-1].area,p[tam-1].telefone);
      // ajusta o ponteiro do arquivo por causa do \n
      fseek(arq_e,1,SEEK_CUR);
    } else {
      // se o tamanho for 0, não houve nenhuma leitura, erro no arquivo
      if (tam == 0){
        printf("Entrada inválida\n");
        exit(1);
      }
      break;
    }
  }
  //o char c já está com o valor do tipo por causa da ajustada dentro do while
  int tipo = c - '0';

  switch (tipo){
    case 1:
       escreverRegisTamFix(arq_s, p, tam);
       break;
    case 2:
       escreverRegisIndTam(arq_s, p, tam);
       break;
    case 3:
       escreverRegisDel(arq_s, p, tam);
       break;
    default:
       printf("Erro na opção do arquivo de entrada\n");
       exit(1);
  }



  free(p);
  fclose(arq_e);
  fclose(arq_s);
  return 0;
}
