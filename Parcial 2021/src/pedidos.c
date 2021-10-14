/*
 * pedidos.c
 *
 *  Created on: 11 oct. 2021
 *      Author: ACantarini
 */
#include "pedidos.h"

void inicializarPedido(ePedido pedidos[], int tamPedido)
{
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			pedidos[i].isEmpty=0;
		}
	}
}

int buscarPosicionVaciaPedido(ePedido pedidos[], int tamPedido, int* posicion)
{
	int error;
	error=-1;
	*posicion=-1;
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].isEmpty==0)
			{
				*posicion=i;
				error=0;
				break;
			}
		}
	}
	return error;
}

int crearPedido(eCliente clientes[], int tamCliente,ePedido pedidos[],int id, int posicion)
{
	int error;
	int idIngresado;
	int posicionEncontrada;
	int cantidadKilos;

	error=-1;
	if(clientes!=NULL && pedidos!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarCliente(clientes[i]);
			}
		}

		idIngresado=validarEntero("\nIngrese numero de id: \n", "Error, reingrese id: \n", 100, 999);
		posicionEncontrada=buscarCliente(clientes, tamCliente, idIngresado);

		if(posicionEncontrada!=-1)
		{
			cantidadKilos=validarEntero("Ingrese cantidad de kilos a recolectar: \n","Error, reingrese nuevamente: \n", 1, 9999);
			pedidos[posicion].cantidadKilos=cantidadKilos;
			pedidos[posicion].idCliente=idIngresado;
			strcpy(pedidos[posicion].estado, "Pendiente");
			pedidos[posicion].idPedido=id;
			pedidos[posicion].isEmpty=1;
			error=0;
		}
		else
		{
			printf("ID NO ENCONTRADO\n");
		}
	}
	return error;
}

void mostrarPedido(ePedido pedido)
{
	printf("----------------------------\n");
	printf("ID  KILOS   ESTADO   ID CLIE\n");
	printf("----------------------------\n");
	printf("%2d %3d     %5s   %3d\n",pedido.idPedido,pedido.cantidadKilos,
	pedido.estado,pedido.idCliente);
}

void mostrarPedidos(ePedido pedidos[], int tamPedido)
{
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].isEmpty==1)
			{
				mostrarPedido(pedidos[i]);
			}
		}
	}
}

int buscarPedido(ePedido pedidos[], int tamPedido, int id)
{
	int posicion=-1;
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].idPedido==id && pedidos[i].isEmpty==1)
			{
				posicion=i;
				break;
			}
		}
	}
	return posicion;
}

int mostrarClienteConPedidosPendiente(eCliente clientes[], int tamCliente, ePedido pedidos[], int tamPedido)
{
	int error;
	error=-1;

	if(clientes!=NULL && tamCliente>0 && pedidos!=NULL && tamPedido>0)
	{
		printf("**********CLIENTES**********\n");
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarCliente(clientes[i]);
			}

		}
		printf("\n\n");
		printf("*******PEDIDOS PENDIENTES*******\n");
		for(int j=0; j<tamPedido; j++)
		{
			if(pedidos[j].isEmpty==1 && strcmp(pedidos[j].estado, "Pendiente")==0)
			{
				mostrarPedido(pedidos[j]);
			}
		}
	}
	return error;
}



