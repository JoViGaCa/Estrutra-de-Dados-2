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

void removerRegis(FILE* arq_e, char codigo [], int* top, int tam){
  fseek(arq_e,15,SEEK_SET);
  int linha = 0;
  char c;
  while(true) {
    char numero[4] = "";
    fgets(numero,4,arq_e);
    if((strcmp(numero,codigo)) == 0){
      fseek(arq_e, -3, SEEK_CUR);
      fprintf(arq_e,"*%i|", *top);
      *(top) = linha;
      fseek(arq_e,12,SEEK_SET);
      fprintf(arq_e,"0%i", linha);
      fseek(arq_e,(linha*tam) + 7,SEEK_CUR);
    } else {
      fseek(arq_e,tam-3, SEEK_CUR);
      linha++;
    }
    if((c = fgetc(arq_e)) == EOF){
      break;
    }

  }
}

void adicionaRegis(FILE *arq_e, Professor p, int* top, int tamanho){
  //conseguir o novo top e armazenar em um aux
  int posicao = 15 + tamanho*(*top) + *(top);
  fseek(arq_e,posicao, SEEK_SET);
  int aux;
  fscanf(arq_e,"*%i", &aux);
  //reajusta a posição para o novo registro
  fseek(arq_e,-2,SEEK_CUR);
  fprintf(arq_e,"%-3s|%-30s|%-1s|%-2s|%-30s|%-14s|\n",p.codigo,p.nome,p.sexo,p.idade,p.area,p.telefone);
  //printa o aux no arquivo
  *(top) = aux;
  fseek(arq_e,12,SEEK_SET);
  fprintf(arq_e,"0%i", *top);
}




int main(){
   FILE* arq_e = fopen("input1.txt", "r+");
   FILE* arq_o = fopen("operations1.txt", "r");
   FILE* arq_t = fopen("temp1.txt","w+");
   FILE* arq_s = fopen("output1.txt", "W");

   int tamanho, top, tam_registros = 0;
   char opc, codigo[4];

   fscanf(arq_e,"size=%i top=%i", &tamanho, &top);

   removerRegis(arq_e,"050",&top, tamanho);
   removerRegis(arq_e,"008",&top,tamanho);

   Professor p;

   strcpy(p.codigo,"023");
   strcpy(p.nome,"Joao Carvalho");
   strcpy(p.sexo,"m");
   strcpy(p.idade,"19");
   strcpy(p.area,"Robotica");
   strcpy(p.telefone,"(44)99999-9999");

   adicionaRegis(arq_e,p,&top,tamanho);



   // while (true){
   //   opc = fgetc(arq_o);
   //   fgetc(arq_o);//pegar o espaco dps do i ou d
   //   tam_registros++;
   //   p = (Professor*) realloc(p,tam_registros*sizeof(Professor));
   //
   //   switch(opc){
   //     case 'i':
   //        fscanf(arq_o,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",p[tam_registros-1].codigo,
   //             p[tam_registros-1].nome,p[tam_registros-1].sexo,p[tam_registros-1].idade,p[tam_registros-1].area,p[tam_registros-1].telefone);
   //        fseek(arq_o, 1, SEEK_CUR);
   //        break;
   //     case 'd':
   //        //fscanf(arq_o,"%s",codigo);
   //        //fseek(arq_o, 84, SEEK_CUR);
   //        //removerRegis(arq_e,codigo,&top,tamanho);
   //        break;
   //     default:
   //        printf("Opcao de operacao invalida.\n");
   //   }
   //
   //   if(feof(arq_o)){
   //     break;
   //   }
   // }



  return 0;
}
