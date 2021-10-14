/*
 * clientes.h
 *
 *  Created on: 9 oct. 2021
 *      Author: ACantarini
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

typedef struct
{
    int idCliente;
    char nombreEmpresa[50];
    int cuil;
    char direccion[50];
    char localidad[50];
    int isEmpty;
}eCliente;

int menu();
void inicializarCliente(eCliente clientes[], int tamCliente);
int buscarPosicionVaciaCliente(eCliente clientes[], int tamCliente, int* posicion);
int altaCliente(eCliente clientes[], int posicion, int id);
int buscarCliente(eCliente clientes[], int tamCliente, int id);
void mostrarCliente(eCliente cliente);
int mostrarClientes(eCliente clientes[], int tamCliente);
int bajaCliente(eCliente clientes[], int tamCliente);
int subMenuModificarCliente();
int modificarCliente(eCliente clientes[], int tamCliente);

#endif /* CLIENTES_H_ */
