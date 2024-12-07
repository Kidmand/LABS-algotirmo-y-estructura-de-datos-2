#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

void copy(char a[], char b[], size_t length) {
 for (unsigned int i = 0; i <length; i++){
  a[i] = b[i];
 } 
 a[length-1] = '\0';
} 

int main(void) {
    char user_input[MAX_LENGTH];
    printf("Ingrese su nombre y apellido: ");
    fgets(user_input,MAX_LENGTH,stdin);
    
    size_t length = strlen(user_input);
    
    if (length == 19 && user_input[19]!='\n' && user_input[18]!='\n') {
     length++; 
    }
    
    copy(user_input, user_input, length);
    
    printf("Te damos la bienvenida %s a este maravilloso programa!\n", user_input);


    return EXIT_SUCCESS;
}

