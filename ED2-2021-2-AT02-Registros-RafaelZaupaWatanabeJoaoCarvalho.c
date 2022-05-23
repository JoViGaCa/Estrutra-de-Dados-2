/*
Alunos:
   João Carvalho 2270340
   Rafael Zaupa 1941399
*/

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

void lerRegisTamFix(FILE* arq_s, int tam, FILE* arq_p){
    for(int i = 0; i < tam; i++){
        char codigo[4];
        char nome[31];
        char sexo[2];
        char idade[4];
        char area[31];
        char telefone[15];

        // receber os dados em tamanho fixo
        fgets(codigo,4,arq_s);
        fseek(arq_s,1,SEEK_CUR);
        fgets(nome,31,arq_s);
        fscanf(arq_s,"|%1s|%3s|", sexo, idade);
        fseek(arq_s,2,SEEK_CUR);
        fgets(area,30,arq_s);
        fseek(arq_s,1,SEEK_CUR);
        fscanf(arq_s,"|%14s", telefone);
        fseek(arq_s,1,SEEK_CUR);

        //ajeitar os tamanhos dos campos nome e area
        int cont = 0;
        for(int i = 0; i < 30; i++){
            if(nome[i] == ' '){
            cont++;
            }
            if(cont == 2){
            nome[i] = '\0';
            }
        }

        cont = 0;
        for(int i = 0; i < 30; i++){
            if(area[i] == ' '){
            cont++;
            }
            if(cont == 2){
            area[i] = '\0';
            }
        }
        fprintf(arq_p,"{%s,%s,%s,%s,%s,%s}\n",codigo,nome,sexo,idade,area,telefone);
    }
}

void lerRegisIndTam(FILE* arq_s, int tamanho, FILE* arq_p){
    char codigo[4];
    char nome[31];
    char sexo[2];
    char idade[4];
    char area[31];
    char telefone[15];

    for(int i = 0; i < tamanho; i++){
        char c[2];
        fscanf(arq_s, "%2s", c);
        fgetc(arq_s);//pega o espaço ' ' logo após o indicador de tamanho
        int tam = atoi(c);
        char* string = (char*) malloc(tam * sizeof(char));
        fgets(string, tam+1, arq_s);
        char* palavra;
        palavra = strtok(string,"|");
        strcpy(codigo,palavra);
        fprintf(arq_p,"{%s,",codigo);
        palavra = strtok(NULL, "|");
        strcpy(nome,palavra);
        fprintf(arq_p,"%s,",nome);
        palavra = strtok(NULL, "|");
        strcpy(sexo,palavra);
        fprintf(arq_p,"%s,",sexo);
        palavra = strtok(NULL, "|");
        strcpy(idade,palavra);
        fprintf(arq_p,"%s,",idade);
        palavra = strtok(NULL, "|");
        strcpy(area, palavra);
        fprintf(arq_p,"%s,",area);
        palavra = strtok(NULL, "|\0");
        strcpy(telefone,palavra);
        fprintf(arq_p,"%s}\n",telefone);
    }
}

void lerRegisDel(FILE* arq_s, int tam, FILE* arq_p){

    for(int i = 0; i < tam; i++){
        char codigo[4];
        char nome[31];
        char sexo[2];
        char idade[4];
        char area[31];
        char telefone[15];

        fscanf(arq_s,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",codigo,nome,sexo,idade,area,telefone);
        fgetc(arq_s);
        fprintf(arq_p,"{%s,%s,%s,%s,%s,%s}\n",codigo,nome,sexo,idade,area,telefone);
    }
}

int main(int argc, const char * argv[]){

  FILE* arq_e = fopen(argv[1], "r"); // arquivo entrada
  FILE* arq_s = fopen(argv[2], "w"); // arquivo saida

  if(argc!=4){
    fprintf(stderr,"Quantidade de parametros invalida.\n");
    exit(1);
  }//caso de erro - parametros

  if(arq_e==NULL || arq_s==NULL){
    fprintf(stderr,"O arquivo de entrada não existe; ou o de saida não foi criado.\n");
    exit(1);
  }//caso de erro - arquivos vazios ou invalidos

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
    fseek(arq_e,-1,SEEK_CUR);

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


  // fecha os arquivos e libera a memória
  free(p);
  fclose(arq_e);
  fclose(arq_s);

  // abre o arquivo de saida de novo para ler e abre um para persistencia
  FILE *arq_s1 = fopen(argv[2], "r");
  FILE *arq_p = fopen(argv[3], "w");

  if(arq_e==NULL || arq_s==NULL){
    fprintf(stderr,"O arquivo de saida não criado; ou o de persistência não foi criado.\n");
    exit(1);
  }//caso de erro - arquivos vazios ou invalidos

  switch (tipo){
    case 1:
       lerRegisTamFix(arq_s, tam, arq_p);
       break;
    case 2:
       lerRegisIndTam(arq_s, tam, arq_p);
       break;
    case 3:
       lerRegisDel(arq_s, tam, arq_p);
       break;
    default:
       printf("Erro na opção do arquivo de entrada\n");
       exit(1);
  }

  fclose(arq_s1);
  fclose(arq_p);
  return 0;
}
