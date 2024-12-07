#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;

    while (s[length]!='\0') {
        ++length;
    }

    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
     bool eq, aux;
    eq= true;
    aux = true;
    unsigned int i = 0;

    while (eq && aux) {       

        if (s1[i]!='\0' && s2[i]!='\0') {
            eq = (s1[i] == s2[i]);
            ++i;
        } else { 
           eq = s1[i] == s2[i];
           aux=false;
        }
    
    } 

    return eq;
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

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux,s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);
}


