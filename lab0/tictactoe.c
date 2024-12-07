#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX ((largo+1) * (largo+1) - 1)
#define largo 4
/* 
void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[largo+1][largo+1])
{
    int cell = 0;

    print_sep(largo+1);
    for (int row = 0; row < largo+1; ++row) {
        for (int column = 0; column < largo+1; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(largo+1);
    }
}


char fila (int x, char board[largo+1][largo+1]) {

    int centinela=0;
    char salida = '-';
    for (int counter=0; counter<largo; counter++) {
         if (board[x][counter]==board[x][counter+1] && board[x][counter]!='-') {
            centinela++;
          }
    }

    if (centinela==largo) {
           salida = board[x][0];
        } 

  return salida;      
}

char columna (int y, char board[largo+1][largo+1]) {

    int centinela=0;
    char salida = '-';
    for (int counter=0; counter<largo; counter++) {
         if (board[counter][y]==board[counter+1][y] && board[counter][y]!='-') {
            centinela++;
          }
    }

    if (centinela==largo) {
           salida = board[0][y];
        } 

  return salida;      
}


char diagonal (char board[largo+1][largo+1]) {
    char salida = '-';
    int centinela=0; 
   for (int counter=0; counter<largo; counter++) {
    if (board[counter][counter]==board[counter+1][counter+1] && board[counter][counter]!='-') {
        centinela++;
    }
   }

   if (centinela==largo) {
     salida = board[0][0];
   }

   return salida; 
}

char diagonalreversa(char board[largo+1][largo+1]) {
    char salida = '-';
    int pivote = largo;
    int centinela=0; 
   for (int counter=0; counter<largo; counter++) {
    if (board[counter][pivote]==board[counter+1][pivote-1] && board[counter][pivote]!='-') {
        pivote--;
        centinela++;
     }
        if (centinela==largo) {
     salida = board[0][largo];
     
      }

   }


   return salida; 
}

char get_winner(char board[largo+1][largo+1]) { 

    char winner = '-';

    for (int counter=0; counter<=largo; counter++) {
        
          if ('-'!= fila(counter,board)) {
            winner=board[counter][0];
            break;
         }

          if ('-'!= columna(counter,board)) {
            winner=board[0][counter];
            break;
         }        
    
       }


        if ('-'!= diagonal(board)) {
            winner=board[0][0];
         }

        if ('-'!= diagonalreversa(board)) {
            winner=board[0][largo];
         }

    return winner;
}


bool has_free_cell(char board[largo+1][largo+1])
{
    bool free_cell=false;
    for (int counter=0; counter<=largo; counter++) {
        for (int counter1=0; counter1<=largo; counter1++) {
            if (board[counter][counter1]=='-') {
                free_cell=true;
                break;
            }
        }
    }

    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[largo+1][largo+1] = {
        { '-', '-', '-', '-' , '-'},
        { '-', '-', '-', '-' , '-'},
        { '-', '-', '-', '-' , '-'},
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / (largo+1);
            int colum = cell % (largo+1);
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }

    return 0;
}
*/

bool ordenMayor (int a[4]) {
    bool y = true; 

    for (int i=0; i<3; i++) {
        if (a[i]<a[i+1]) {
            y=false;
        }
    }

    return y;
}

bool ordenMenor (int a[4]) {
    bool y = true; 

    for (int i=0; i<3; i++) {
        if (a[i]>a[i+1]) {
            y=false;
        }
    }

    return y;
}




/*bool orden (int a[4]) {

    bool y;
    if (ordenMayor(a) || ordenMenor(a)) {
        y=true;
    } else {
        y=false;
    }
   return y;
 }*/


bool orden (int a[4]) {

    bool y,n,m;
    y=true; 
    n=true;
    m=true;

    for (int i=0; i<3; i++) {
        if (a[i]>a[i+1] && n) {
          m=false;
        } else if (a[i]<a[i+1] && m) {
            n=false;
        } else if (a[i]!=a[i+1]) { 
            y=false;
            break;
        }
    }
   
   return y;
 }


int main() {
    int a[4] = {2,2,2,2};

    printf("%d", orden(a));

    return 0;
}