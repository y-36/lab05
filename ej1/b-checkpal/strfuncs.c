#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "strfuncs.h"

/*Implement *str where*/
size_t string_length(const char *str){
/*Calcula la longitud de la cadena apuntada por str*/
   int s;
   if(str == NULL){
	printf("NULL\n");
         s=0;
	return s;
    }
    size_t i = 1;
    while (*str != '\0') {
        i++;
        str++;
    }
    return i;
}

 char *string_filter(const char *str, char c){
/*Devueleve una nueva cadena en memoria dinamina
  se optine tomando los char de str !=c */
    if (str == NULL) {
        printf("NULL\n");
        return NULL; // Devuelve un puntero nulo
    }
    // Calcula la longitud de la cadena original
    size_t len = string_length(str);
    // Asigna memoria dinámica para la nueva cadena
    char *filtered_str = (char *)malloc(len + 1); // +1 para el carácter nulo
    if (filtered_str != NULL) {
        size_t i = 0;
        size_t j = 0;
        // Copia los caracteres que no son igual a 'c'
        while (str[i] != '\0') {
            if (str[i] != c) {
                filtered_str[j] = str[i];
                j++;
            }
            i++;
        }
        // Agrega el carácter nulo al final
        filtered_str[j] = '\0';
        free(filtered_str);
	//-----------------//
	/*VALGRIND DETEDED*/
        //----------------//
    }
    return filtered_str;
}

bool string_is_symmetric(const char *str){
/*Indica si la cadena apuntada por str es simetrica
   ejemplos "aba" "abcba, "a", "".*/
    if (str == NULL) {
        return false; // Manejo de puntero nulo
    }

    // Calcula la longitud de la cadena sin usar strlen
    size_t tamano = 0;
    while (str[tamano] != '\0') {
        tamano++;
    }

    // Inicializa los índices para recorrer la cadena
    int inicio = 0;
    int fin = tamano - 1;

    // Compara los caracteres desde los extremos hacia el centro
    while (inicio < fin) {
        if (str[inicio] != str[fin]) {
            return false; // No es simétrica
        }
        inicio++;
        fin--;
    }

    return true;
}

