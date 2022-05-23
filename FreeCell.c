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
} PilhaDin;//struct pd

void iniciaPilhaDin(PilhaDin *p){
  //inicia ptr topo nulo e contador = 0
  p->topo = NULL;
  p->tamanho = 0;
}

void empilhaPd(PilhaDin *pd, int linha, int coluna, Cartas baralho[4][13],int pilhas) {

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

}

int main(){
  
}
