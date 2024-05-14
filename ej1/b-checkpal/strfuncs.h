#ifndef _STRFUNCS_H
#define _STRFUNCS_H


size_t string_length(const char *str);
/*Calcula la longitud de la cadena apuntada por str*/

char *string_filter(const char *str, char c);
/*Devueleve una nueva cadena en memoria dinamina
  se optine tomando los char de str !=c*/

bool string_is_symmetric(const char *str);
/*Indica si la cadena apuntada por str es simetrica
   ejemplos "aba" "abcba, "a", "".*/

#endif
