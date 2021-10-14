/*
 * pedidos.h
 *
 *  Created on: 11 oct. 2021
 *      Author: ACantarini
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#include "clientes.h"

typedef struct
{
    int idCliente;
    int idPedido;
    int cantidadKilos;
    char estado[50];
    int isEmpty;
}ePedido;

void inicializarPedido(ePedido pedidos[], int tamPedido);
int buscarPosicionVaciaPedido(ePedido pedidos[], int tamPedido, int* posicion);
int crearPedido(eCliente clientes[], int tamCliente,ePedido pedidos[],int id, int posicion);
void mostrarPedido(ePedido pedido);
void mostrarPedidos(ePedido pedidos[], int tamPedido);
int buscarPedido(ePedido pedidos[], int tamPedido, int id);
int mostrarClienteConPedidosPendiente(eCliente clientes[], int tamCliente, ePedido pedidos[], int tamPedido);

#endif /* PEDIDOS_H_ */
