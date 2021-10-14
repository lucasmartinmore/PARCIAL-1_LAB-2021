/*
 * informes.c
 *
 *  Created on: 14 oct. 2021
 *      Author: ACantarini
 */
#include "informes.h"

int mostrarPedidosPendienteConCliente(ePedido pedidos[],int tamPedidos, eCliente clientes[], int tamClientes)
{
	int error;
	error=-1;
	if(pedidos!=NULL && clientes!=NULL && tamClientes>0 && tamPedidos>0)
	{
		printf("*****PEDIDOS PENDIENTE INFORMACION*****\n");
		printf("-------------------------------------\n");
		printf("ID PED  ESTADO  CANT  CUIT  DIRECCION\n");
		printf("-------------------------------------\n");
		for(int i=0; i<tamPedidos; i++)
		{
			if(pedidos[i].isEmpty==1 && strcmp(pedidos[i].estado, "Pendiente")==0)
			{
				for(int j=0; j<tamClientes; j++)
				{
					if(pedidos[i].idCliente==clientes[j].idCliente)
					{
						printf("%2d    %7s  %2d   %5d  %8s\n",pedidos[i].idPedido,pedidos[i].estado,
						pedidos[i].cantidadKilos,clientes[j].cuil,clientes[j].direccion.direccion);
						printf("-------------------------------------\n");
						error=0;
					    //break;
					}
				}
			}
		}
	}
	return error;
}

int mostrarPedidosCompletadosConCliente(eProcesar procesar[],int tamProcesar, ePedido pedidos[], int tamPedidos)
{
	int error;
	error=-1;
	if(procesar!=NULL && pedidos!=NULL && tamPedidos>0 && tamProcesar>0)
	{
		printf("*****PEDIDOS COMPLETADOS INFORMACION*****\n");
		printf("-----------------------------------------\n");
		printf("ID PED  ESTADO   CANT  ID CLI  TIPO\n");
		printf("-----------------------------------------\n");
		for(int i=0; i<tamProcesar; i++)
		{
			if(procesar[i].isEmpty==1 && strcmp(procesar[i].estadoPedido, "Completado")==0)
			{
				for(int j=0; j<tamPedidos; j++)
				{
					if(procesar[i].idPedido==pedidos[j].idPedido)
					{
						printf("%2d    %7s  %2d     %3d  %2d\n",procesar[i].idPedido,procesar[i].estadoPedido,
						procesar[i].cantidadKilos,pedidos[j].idCliente,procesar[i].idTipo);
						printf("-----------------------------------------\n");
						error=0;
						//break;
					}
				}
			}
		}
	}
	return error;
}

int mostrarPedidosPorLocalidad(ePedido pedidos[], int tamPedido, eCliente clientes[], int tamCliente)
{
	int error;
	char localidad[50];
	error=-1;
	if(pedidos!=NULL && clientes!=NULL && tamCliente>0 && tamPedido>0)
	{
		validarCadena("Ingrese la localidad la cual quiere mostrar sus pedidos: \n", "Error, reingrese nuevamente: \n", 50, localidad);
		printf("*****PEDIDOS PENDIENTE POR LOCALIDAD*****\n");
		printf("ID PED  ESTADO  CANT  CUIT  DIRECCION\n");
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].isEmpty==1 && strcmp(pedidos[i].estado, "Pendiente")==0)
			{
				for(int j=0; j<tamCliente; j++)
				{
					if(strcmp(clientes[j].localidad.localidad,localidad)==0 && clientes[j].idCliente==pedidos[i].idCliente)
					{
						printf("%2d    %7s  %2d   %5d  %8s\n",pedidos[i].idPedido,pedidos[i].estado,
						pedidos[i].cantidadKilos,clientes[j].cuil,clientes[j].direccion.direccion);
						error=0;
					}
				}
			}
		}
	}
	return error;
}

/*
 * Cantidad de kilos de polipropileno reciclado promedio por cliente.
 *  (kilos totales / cantidad de clientes)
 */
void cantidadPoplipropilenoxCliente(eProcesar procesar[], int tamProcesar)
{
	int acumulador;
	int contador;
	float promedio;
	acumulador=0;
	contador=0;
	if(procesar!=NULL && tamProcesar>0)
	{
		for(int i=0; i<tamProcesar; i++)
		{
			if(procesar[i].idTipo==3 && procesar[i].isEmpty==1)
			{
				acumulador=acumulador+procesar[i].cantidadKilos;
				contador++;
			}
		}
		if(contador!=0)
		{
			promedio=(float)acumulador/contador;
			printf("*****EL PRECIO PROMEDIO DE POLIPROPILENO ES %.2f KILOS*****\n",promedio);
		}
		else
		{
			printf("*****NO SE REGISTRO NINGUN RECICLADO DE POLIPROPILENO*****\n");
		}
	}
}
