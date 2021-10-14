/*
 * informes.h
 *
 *  Created on: 14 oct. 2021
 *      Author: ACantarini
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "pedidos.h"
#include "clientes.h"
#include "procesados.h"

int mostrarPedidosPendienteConCliente(ePedido pedidos[],int tamPedidos, eCliente clientes[], int tamClientes);
int mostrarPedidosCompletadosConCliente(eProcesar procesar[],int tamProcesar, ePedido pedidos[], int tamPedidos);
int mostrarPedidosPorLocalidad(ePedido pedidos[], int tamPedido, eCliente clientes[], int tamCliente);
void cantidadPoplipropilenoxCliente(eProcesar procesar[], int tamProcesar);

#endif /* INFORMES_H_ */
