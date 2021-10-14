/*
 * validaciones.h
 *
 *  Created on: 9 oct. 2021
 *      Author: ACantarini
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validarEntero(char* mensaje, char* mensajeError, int min, int max);
float validarFlotante(char* mensaje, char* mensajeError, float min, float max);
char validarCaracter(char* mensaje, char* mensajeError);
void validarCadena(char* mensaje, char* mensajeError, int tamanio, char* cadenaRetorno);
char* primerMayuscula(char* cadena);


#endif /* VALIDACIONES_H_ */
