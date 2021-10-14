/*
 * validaciones.c
 *
 *  Created on: 9 oct. 2021
 *      Author: ACantarini
 */
#include "validaciones.h"

int validarEntero(char* mensaje, char* mensajeError, int min, int max)
{
    int entero;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &entero);
    while(entero<min || entero>max)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%d", &entero);
    }
    return entero;
}



float validarFlotante(char* mensaje, char* mensajeError, float min, float max)
{
    float flotante;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &flotante);
    while(flotante<min || flotante>max)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%f", &flotante);
    }
    return flotante;
}

char validarCaracter(char* mensaje, char* mensajeError)
{
    char letra;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letra);
    while((letra<'a' || letra>'z') && (letra<'A' || letra>'Z'))
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%c", &letra);
    }
    return letra;
}

void validarCadena(char* mensaje, char* mensajeError, int tamanio, char* cadenaRetorno)
{
    char cadenaAuxiliar[100];
    printf("%s", mensaje);
    fflush(stdin);
    gets(cadenaAuxiliar);

    while(strlen(cadenaAuxiliar) > tamanio)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(cadenaAuxiliar);
    }
    strcpy(cadenaRetorno, cadenaAuxiliar);
}

char* primerMayuscula(char* cadena)
{
    cadena[0]= toupper(cadena[0]);
    return cadena;
}




