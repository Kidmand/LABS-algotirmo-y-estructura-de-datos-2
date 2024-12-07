#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;

    while (s[length]!='\0') {
        ++length;
    }

    return length;
}


bool fstring_eq(fixstring s1, fixstring s2) {
     bool eq = true;
     int k = 0;

    while (s1[k] != '\0' && s2[k] != '\0' && eq) {       
         eq = s1[k] == s2[k];
         k = k+1;
    } 
    
    return eq && s2[k]=='\0' && s1[k]=='\0';
}


bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool menor, resultado;
    unsigned int i = 0;
    menor = true;
    resultado = true;

    while ( menor && s1[i]!='\0' && s2[i]!='\0' ) {       
        if (s1[i]!=s2[i]) {
            resultado=s1[i]<s2[i];
            menor = false;
        } else 
        ++i;   
    }

    if (menor) {
        resultado = fstring_length(s1) <= fstring_length(s2);
    }
    return resultado;
}




