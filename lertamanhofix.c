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
  FILE *arq_s = fopen("output1.txt", "r");
  Professor p;
  // receber os dados em tmanho fixo
  fgets(p.codigo,4,arq_s);
  fseek(arq_s,1,SEEK_CUR);
  fgets(p.nome,30,arq_s);
  fseek(arq_s,1,SEEK_CUR);
  fgets(p.sexo,1,arq_s);
  //fseek(arq_s,1,SEEK_CUR);
  fgets(p.idade,3, arq_s);
  fseek(arq_s,1,SEEK_CUR);
  fgets(p.area,30,arq_s);
  fseek(arq_s,1,SEEK_CUR);
  fgets(p.telefone,14,arq_s);
  printf("%s %s %s %s %s %s\n", p.codigo,p.nome,p.sexo,p.idade,p.area,p.telefone);

  //ajeitar os tamanhos nome e area
  int cont = 0;
  for(int i = 0; i < 30; i++){
    if(p.nome[i] == ' '){
      cont++;
    }
    if(cont == 2){
      p.nome[i] = '\0';
    }
  }

  cont = 0;
  for(int i = 0; i < 30; i++){
    if(p.area[i] == ' '){
      cont++;
    }
    if(cont == 2){
      p.area[i] = '\0';
    }
  }
  printf("%s %s %s %s %s %s\n", p.codigo,p.nome,p.sexo,p.idade,p.area,p.telefone);


  fclose(arq_s);
  return 0;
}
