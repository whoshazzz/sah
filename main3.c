#include <stdio.h> 
#include <stdlib.h>

void paraCimahey(char matriz[][4]);
void paraBaixohey(char matriz[][4]);
void paraEsquerdahey(char matriz[][4]);
void paraDireitahey(char matriz[][4]);
void imprimir(char matriz[][4]);
void flush_in();


int main(){
    
  char matriz[4][4];
  char teclado;
  int continuar = 1;
    
  for(int i = 0; i < 4; i++){ //preenche a matriz com espaços em brancos
    for(int j = 0; j < 4; j++){
       matriz[i][j] = ' ';
    }
  }    
    
  matriz[0][0] = '*';
  imprimir(matriz);

  
  while(continuar){
    teclado = getchar();
    flush_in();
    system("clear");

    switch(teclado){
    case 'w':
    case 'W': 
      paraCimahey(matriz);
      imprimir(matriz);
      break;
    case 's':
    case 'S':
      paraBaixohey(matriz);
      imprimir(matriz);
      break;
    case 'a':
    case 'A': 
      paraEsquerdahey(matriz);
      imprimir(matriz);
      break;
    case 'd':
    case 'D': 
      paraDireitahey(matriz);
      imprimir(matriz);
      break;
    case 'q':
    case 'Q': 
      continuar = 0;
      break;
    default:
      printf("Tecla digitada inválida\n");
      printf("(Tecla W) Para cima\n");
      printf("(Tecla S) Para baixo\n");
      printf("(Tecla A) Para esquerda\n");
      printf("(Tecla D) Para direita\n");
   } 
  } 
}


void flush_in() { //funçãão q limpa o buffer do teclado
  int ch;
  do {
  ch = fgetc(stdin);
  } while (ch != EOF && ch != '\n');
}

void imprimir(char matriz[][4]){
  for(int i = 0; i < 4; i++){ //linhas
    printf("|");
    for(int j = 0; j < 4; j++){  //colunas             //barrinha no inicio e
      printf(" %c ", matriz[i][j]);           //fim de cada linha
    }
    printf("|\n");
  }    
}

void paraCimahey(char matriz[][4]){

  int i, j;

	for(i = 0 ; i < 4; i++){ //linha
  	for(j = 0 ; j < 4; j++){ //coluna
  		if(matriz[i][j] == '*'){
        if(i == 0){ //se a linha for 0 o * se mantém no mantém no mesmo lugar
          matriz[i][j] = '*';
          break;
        } else {
          matriz[i][j] = ' ';
          matriz[i - 1][j] = '*';
          break;
        }
      }
  	}
  }
}

void paraBaixohey(char matriz[][4]){

  int i, j;

	for(i = 0 ; i < 4; i++){ //linha
  	for(j = 0 ; j < 4; j++){ //coluna
  		if(matriz[i][j] == '*'){
        if(i == 3){ //se a linha for 3 o * se mantém no mantém no mesmo lugar
          matriz[i][j] = '*';
          break;
        } else {
          matriz[i][j] = ' ';
          i++; 
          matriz[i][j] = '*';
          break;
        }
      }
  	}
  }
}

void paraEsquerdahey(char matriz[][4]){

  int i, j;

	for(i = 0 ; i < 4; i++){ //linha
  	for(j = 0 ; j < 4; j++){ //coluna
  		if(matriz[i][j] == '*'){
        if(j == 0){ //se a coluna for 0 o * se mantém no mantém no mesmo lugar
          matriz[i][j] = '*';
          break;
        } else {
          matriz[i][j] = ' ';
          matriz[i][j - 1] = '*';
          break;
        }
      }
  	}
  }
}

void paraDireitahey(char matriz[][4]){

  int i, j;

	for(i = 0 ; i < 4; i++){ //linha
  	for(j = 0 ; j < 4; j++){ //coluna
  		if(matriz[i][j] == '*'){
        if(j == 3){//se a coluna for 3 o * se mantém no mantém no mesmo lugar
          matriz[i][j] = '*';
          break;
        } else {
          matriz[i][j] = ' ';
          matriz[i][j + 1] = '*';
          break;
        }
      }
  	}
  }
}
