//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

//declaracando pilha dinamica
typedef struct Cartas* PtrNoPilha;

typedef struct Cartas{
  char valor;
  char naipe;
  bool foiJogada;
  PtrNoPilha proximo;
} Cartas;

typedef struct {
  PtrNoPilha topo;
  int tamanho;
} PilhaDinamica;//struct pd

void iniciaPd(PilhaDinamica *pd) {

  //define o valor do topo da pilha como NULL
  pd->topo = NULL;
  //define o tamanho da pilha dinamica como 0
  pd->tamanho = 0;

}//iniciapd

void empilhaPilhaDin(PilhaDinamica*pd, char valor, char naipe){
  printf("Aqui foi\n");
  PtrNoPilha aux = (PtrNoPilha) malloc(sizeof(PtrNoPilha));
  aux->valor = valor;
  aux->naipe = naipe;
  aux->proximo = pd->topo;
  pd->topo = aux;
  pd->tamanho++;
}


void empilhaPd(PilhaDinamica *pd, int linha, int coluna, Cartas baralho[4][13],int pilhas) {

  //declaracao de variaveis
  PtrNoPilha Aux[4][13];

  //declaracao para gerar os numeros aleatorios
  time_t t;
  srand((unsigned) time(&t));

  //aloca dinamicamente
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 13; j++)
    {
      Aux[i][j] = (PtrNoPilha)malloc(sizeof(Cartas));
    }
  }

if(pilhas<1){

  for (int i = 0; i < 7;) {

    //Gera a Carta aleatoria
    linha = rand() % 4;
    coluna = rand() % 13;
    //if para exibir uma carta que ainda nao foi jogada
    if(baralho[linha][coluna].foiJogada == false) {

      //define a carta como jogada
      baralho[linha][coluna].foiJogada = true;

      Aux[linha][coluna]->valor=baralho[linha][coluna].valor;
      Aux[linha][coluna]->naipe=baralho[linha][coluna].naipe;
      //contador
      i++;
      //if para quando o tamanho da pilha for 0
      if (pd->tamanho == 0)
      //define como null como o proximo valor da pilha
      Aux[linha][coluna]->proximo = NULL;
      //else para quando o tamanho for maior que 1
      else
      //adiciona o topo como valor do proximo da pilha
      Aux[linha][coluna]->proximo = pd->topo;

      //copia o valor de auxiliar para topo
      pd->topo = Aux[linha][coluna];
      //adiciona mais um no tamanho da pilha
      pd->tamanho++;
    }//if

  }//for
}//if

  else{

    for (int j = 0; j < 6;) {

      //Gera a Carta aleatoria
      linha = rand() % 4;
      coluna = rand() % 13;

      //if para exibir uma carta que ainda nao foi jogada
      if(baralho[linha][coluna].foiJogada == false) {

        //define a carta como jogada
        baralho[linha][coluna].foiJogada = true;

        Aux[linha][coluna]->valor=baralho[linha][coluna].valor;
        Aux[linha][coluna]->naipe=baralho[linha][coluna].naipe;
        //contador
        j++;
        //if para quando o tamanho da pilha for 0
        if (pd->tamanho == 0)
        //define como null como o proximo valor da pilha
        Aux[linha][coluna]->proximo = NULL;
        //else para quando o tamanho for maior que 1
        else
        //adiciona o topo como valor do proximo da pilha
        Aux[linha][coluna]->proximo = pd->topo;

        //copia o valor de auxiliar para topo
        pd->topo = Aux[linha][coluna];
        //adiciona mais um no tamanho da pilha
        pd->tamanho++;
      }//if
    }//for
  }//else

}//empilha na pilha dimanima

void trocapilhapd(PilhaDinamica *pd1, PilhaDinamica *pd2, Cartas baralho[4][13]){

  //copia o valor de auxiliar para topo
  pd2->topo = pd1->topo;
  //adiciona mais um no tamanho da pilha
  pd2->tamanho++;

}

void imprimePd(PilhaDinamica *pd1,PilhaDinamica *pd2,PilhaDinamica *pd3,PilhaDinamica *pd4,PilhaDinamica *pd5,PilhaDinamica *pd6,PilhaDinamica *pd7,PilhaDinamica *pd8) {

//declaracao de variaveis
  PtrNoPilha ptr1 = pd1->topo;
  PtrNoPilha ptr2 = pd2->topo;
  PtrNoPilha ptr3 = pd3->topo;
  PtrNoPilha ptr4 = pd4->topo;
  PtrNoPilha ptr5 = pd5->topo;
  PtrNoPilha ptr6 = pd6->topo;
  PtrNoPilha ptr7 = pd7->topo;
  PtrNoPilha ptr8 = pd8->topo;
  int cont1=1;
  int cont2=1;
  int cont3=1;
  int cont4=1;
  int cont5=1;
  int cont6=1;
  int cont7=1;
  int cont8=1;
  int max=0;
  int tamanho=pd1->tamanho;
  if(tamanho<pd2->tamanho){
    tamanho=pd2->tamanho;
  }if(tamanho<pd3->tamanho){
    tamanho=pd3->tamanho;
  }if(tamanho<pd4->tamanho){
    tamanho=pd4->tamanho;
  }if(tamanho<pd5->tamanho){
    tamanho=pd5->tamanho;
  }if(tamanho<pd6->tamanho){
    tamanho=pd6->tamanho;
  }if(tamanho<pd7->tamanho){
    tamanho=pd7->tamanho;
  }if(tamanho<pd8->tamanho){
    tamanho=pd8->tamanho;
  }
  max=tamanho;
    //printf("%d\n",max );

  for(;(ptr1 != NULL && cont1<=tamanho);){
    if(pd1->tamanho >= max ){
      printf(" [%c%c]",ptr1->valor,ptr1->naipe);
      ptr1 = ptr1->proximo;
    } else{
      printf(" [ ]");
    }
    if(pd2->tamanho >= max ){
      printf(" [%c%c]",ptr2->valor,ptr2->naipe);
      ptr2 = ptr2->proximo;
    }else{
      printf(" [ ]");
    }
    if(pd3->tamanho >= max ){
      printf(" [%c%c]",ptr3->valor,ptr3->naipe);
      ptr3 = ptr3->proximo;
    }else{
      printf(" [ ]");
    }
    if(pd4->tamanho >= max ){
      printf(" [%c%c]",ptr4->valor,ptr4->naipe);
      ptr4 = ptr4->proximo;
    }else{
      printf(" [ ]");
    }
    if(pd5->tamanho >= max ){
      printf(" [%c%c]",ptr5->valor,ptr5->naipe);
      ptr5 = ptr5->proximo;
    }else{
      printf(" [ ]");
    }
    if(pd6->tamanho >= max ){
      printf(" [%c%c]",ptr6->valor,ptr6->naipe);
      ptr6 = ptr6->proximo;
    }else{
      printf(" [ ]");
    }
    if(pd7->tamanho >= max ){
      printf(" [%c%c]",ptr7->valor,ptr7->naipe);
      ptr7 = ptr7->proximo;
    }else{
      printf(" [ ]");
    }
    if(pd8->tamanho >= max ){
      printf(" [%c%c]",ptr8->valor,ptr8->naipe);
      ptr8 = ptr8->proximo;
    }else{
      printf(" [ ]");
    }
    printf("\n");

  cont1++;
  cont2++;
  cont3++;
  cont4++;
  cont5++;
  cont6++;
  cont7++;
  cont8++;
  max--;
  }//for para rodar todas as posiçoes da pilhas

}//imprime no arquivo

bool estaVaziaPilhaDinamica(PilhaDinamica*p){
  return (p-> tamanho == 0); //true
}

int desempilhaPilhaDinamica(PilhaDinamica*p){
  int ret=99;//controle
  if(estaVaziaPilhaDinamica(p)==false){
    PtrNoPilha aux;
    aux = p-> topo;
    ret = aux -> valor;
    p->topo = p->topo->proximo;
    free(aux);
    p->tamanho--;
  }else{
    printf("A Pilha esta vazia !\n");
  }
  return (ret);
}


int movPilhaDin(PilhaDinamica*b1, PilhaDinamica*b2){
  int ret = -99;
  if(atoi(&(b1->topo->valor)) < atoi(&(b2->topo->valor))){
    if(b1->topo->naipe == 'C' || b1->topo->naipe == 'O'){
      if(b2->topo->naipe == 'P' || b2->topo->naipe == 'E'){
        empilhaPilhaDin((b2), b1->topo->valor, b1->topo->naipe);
        desempilhaPilhaDinamica(&(*b1));
      }
    }
    if(b1->topo->naipe == 'P' || b1->topo->naipe == 'E'){
      if(b2->topo->naipe == 'C' || b2->topo->naipe == 'O'){
        empilhaPilhaDin((b2), b1->topo->valor, b1->topo->naipe);
        desempilhaPilhaDinamica(&(*b1));
      }
    }
    ret = 1;
  } else {
    printf("Incapaz de realizar tal movimento\n");
  }
  return ret;
}


int main(){

//declaracao de variaveis
Cartas baralho[4][13];
char valores[13] = {'A','2','3','4','5','6','7','8','9','B','J','Q','K'};
char naipes[4] = {'P','C','E','O'};
int carta1 = 0, carta2 = 0, carta3 = 0, carta4 = 0;
int linha, coluna, fim,pilhas=0;
int opcao=0;
int definitivo,baralho1,baralho2,auxiliar;

//declaracao pilha dinamicamente
PilhaDinamica pilha[8];

for(int i = 0; i < 8; i++){
  iniciaPd(&pilha[i]);
}

//define as cartas do baralho
for(int i = 0; i < 4; i ++){
  for(int j = 0; j < 13; j++) {
    baralho[i][j].naipe = naipes[i];
    baralho[i][j].valor = valores[j];
    //define todas as cartas como nao jogadas
    baralho[i][j].foiJogada = false;
  }//for
}//for
//pilhas de 7 cartas
empilhaPd(&pilha[0],linha,coluna,baralho,pilhas);

empilhaPd(&pilha[1],linha,coluna,baralho,pilhas);
empilhaPd(&pilha[2],linha,coluna,baralho,pilhas);
empilhaPd(&pilha[3],linha,coluna,baralho,pilhas);
pilhas++;
//pilhas de 6 cartas
empilhaPd(&pilha[4],linha,coluna,baralho,pilhas);
empilhaPd(&pilha[5],linha,coluna,baralho,pilhas);
empilhaPd(&pilha[6],linha,coluna,baralho,pilhas);
empilhaPd(&pilha[7],linha,coluna,baralho,pilhas);

while (fim!=0) {
  //exibe as cartas
  printf("-=-=- FreeCell -=-=-\n\n");
  printf(" Auxiliares Definitivos \n");
  printf("[ ] [ ] [ ] [ ] [ ][ ][ ][ ] \n\n\n");
  printf(" Baralho\n\n");
  imprimePd(&pilha[0],&pilha[1],&pilha[2],&pilha[3],&pilha[4],&pilha[5],&pilha[6],&pilha[7]);

  if(opcao==0){
    printf("\n-=-=- Menu -=-=-\n\n");
    printf(" [1]Mover para Definitivos\n");
    printf(" [2]Mover para Auxiliares\n");
    printf(" [3]Mover para outro Baralho\n");
    printf(" [4]Tutorial\n");
    printf("\nDigite sua opcao: ");
    scanf("%i",&opcao);
  }
  else if(opcao==1){
    printf("\nDigite o numero do baralho: ");
    scanf("%i",&baralho1 );
    printf("Digite o numero do definitivo: ");
    scanf("%i",&definitivo );
    opcao = 0;
  }
  else if(opcao==2) {
    printf("\nDigite o numero do baralho: ");
    scanf("%i",&baralho1 );
    printf("Digite o numero do auxiliar: ");
    scanf("%i",&auxiliar );
    opcao = 0;
  }
  else if(opcao==3){
    printf("\nDigite o numero do baralho inicial: ");
    scanf("%i",&baralho1 );
    printf("Digite o numero do baralho final: ");
    scanf("%i",&baralho2 );
    movPilhaDin(&pilha[baralho1-1],&pilha[baralho2-1]);

    opcao = 0;
  }
  //else if(opcao==4){
  // fgets();
  // opcao = 0;
  //}
  else{
    printf("\n-=-=- Menu -=-=-\n\n");
    printf(" [1]Mover para Definitivos\n");
    printf(" [2]Mover para Auxiliares\n");
    printf(" [3]Mover para outro Baralho\n");
    printf(" [4]Tutorial\n");
    printf("\n!!! Opcao Invalida !!!\n\nDigite novamente: ");
    scanf("%i",&opcao);
  }
  //limpa console
  system("cls");
}//while em loop ate o jogo terminar ou nao for possivel fazer mais nenhuma jogada

  return 0;

}
