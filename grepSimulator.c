#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char** foundString(FILE* arq, char* string, int* cont){
  *cont = 0;
  char* found;
  char** strings = (char**) malloc(sizeof(char*));
  strings[0] = (char*) malloc(1000*sizeof(char));
  while(!feof(arq)){
    char buffer[1000] = "";
    fgets(buffer,999,arq);
    char buffer1[1000];
    strcpy(buffer1, buffer);
    found = NULL;
    for(found = strtok(buffer, "}{ ,."); found!= NULL; found = strtok(NULL,"}{ ,.")){
      if((strcmp(string,found)) == 0){
        strcpy(strings[*cont],buffer1);
        (*cont)++;
        strings = (char**)realloc(strings, (*cont+1) * sizeof(char*));
        for(int i = 0; i < (*cont)-1; i++){
          strings[i] = (char*) realloc(strings[i], 1000*sizeof(char));
        }
        strings[*cont] = (char*) malloc(1000*sizeof(char));
      }
    }
  }
  return strings;
}


int main(int argc, char*argv[]){
  if (argc != 3){
    printf("Erro nos argumentos\n");
    return 0;
  }

  FILE * arq = fopen(argv[1], "r");
  if(arq == NULL){
    printf("Erro ao abrir o arquivo\n");
    return 0;
  }

  int cont;
  char **string = foundString(arq, argv[2], &cont);

  for(int i = 0; i < cont; i++){
    printf("%s\n", string[i]);
  }


  return 0;
}
