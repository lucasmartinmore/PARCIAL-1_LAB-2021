/*
 * procesados.h
 *
 *  Created on: 13 oct. 2021
 *      Author: ACantarini
 */

#ifndef PROCESADOS_H_
#define PROCESADOS_H_
#include "pedidos.h"

typedef struct
{
	int idProcesar;
    int idPedido;
    int idTipo;
    int idCliente;
    int cantidadKilos;
    char estadoPedido[50];
    int isEmpty;
}eProcesar;

int subMenuTipo();
void inicializarProcesar(eProcesar procesados[], int tamProcesar);
int buscarPosicionVaciaProcesar(eProcesar procesados[], int tamProcesado, int* posicion);
int procesarResiduos(eProcesar procesar[], ePedido pedidos[], int tamPedidos, int id, int posicion);
void mostrarProcesar(eProcesar procesar);
void mostrarProcesados(eProcesar procesados[], int tamProcesados);



#endif /* PROCESADOS_H_ */
