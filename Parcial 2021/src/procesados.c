/*
 * procesados.c
 *
 *  Created on: 13 oct. 2021
 *      Author: ACantarini
 */
#include "procesados.h"

int subMenuTipo()
{
	int opcion;
	opcion=validarEntero("1)HDPE\n2)LDPE\n3)PP\n4)OTROS\n\nIngrese tipo de plastico: \n", "Opcion invalidad, reingrese opcion: \n", 1, 4);
	return opcion;
}

void inicializarProcesar(eProcesar procesados[], int tamProcesar)
{
	if(procesados!=NULL && tamProcesar>0)
	{
		for(int i=0; i<tamProcesar; i++)
		{
			procesados[i].isEmpty=0;
		}
	}
}

int buscarPosicionVaciaProcesar(eProcesar procesados[], int tamProcesado, int* posicion)
{
	int error;
	error=-1;
	*posicion=-1;
	if(procesados!=NULL && tamProcesado>0)
	{
		for(int i=0; i<tamProcesado; i++)
		{
			if(procesados[i].isEmpty==0)
			{
				*posicion=i;
				error=0;
				break;
			}
		}
	}
	return error;
}
/*
 * Procesar residuos: Se elegirá esta opción cuando los residuos que volvieron
 * a la empresa se hayan procesado y separado en los diferentes tipos de plástico
 * que la empresa puede reciclar. Se imprimirán los pedidos por pantalla
 * y se pedirá seleccionar el ID de uno de ellos. Luego deberán ingresarse
 * la cantidad de kilos de plástico de cada uno de los 3 tipos que la empresa
 * puede procesar que se obtuvieron de los kilos totales que se recolectaron.
 * Por último, se marcará al pedido como “Completado”.
 */
int procesarResiduos(eProcesar procesar[], ePedido pedidos[], int tamPedidos, int id, int posicion)
{
	int error;
	int posicionEncontrada;
	int idIngresado;
	int kilosIngresados;
    int opcion;
	error=-1;

	if(procesar!=NULL && pedidos!=NULL && tamPedidos>0)
	{
		for(int i=0; i<tamPedidos; i++)
		{
			if(pedidos[i].isEmpty && strcmp(pedidos[i].estado, "Pendiente")==0)
			{
				mostrarPedido(pedidos[i]);
			}
		}

		idIngresado=validarEntero("\nIngrese numero de id: \n", "Error, reingrese id: \n", 1, 1000);
		posicionEncontrada=buscarPedido(pedidos, tamPedidos, idIngresado);

		if(posicionEncontrada!=-1)
		{
			kilosIngresados=validarEntero("Ingrese cantidad de kilos a procesar: \n", "Error, reingrese cantidad: \n", 1, 9999);
			if(kilosIngresados<=pedidos[posicionEncontrada].cantidadKilos)
			{
				opcion=subMenuTipo();
				procesar[posicion].cantidadKilos=kilosIngresados;
				strcpy(procesar[posicion].estadoPedido,"Completado");
				procesar[posicion].idProcesar=id;
				procesar[posicion].idPedido=idIngresado;
				procesar[posicion].idTipo=opcion;
				procesar[posicion].isEmpty=1;
				error=0;

				for(int i=0; i<tamPedidos; i++)
				{
					if(pedidos[i].idPedido==procesar[posicion].idPedido)
					{
						pedidos[i].cantidadKilos=pedidos[i].cantidadKilos-kilosIngresados;
						strcpy(pedidos[i].estado, "Completado");
						pedidos[i].isEmpty=0;
						error=0;
						break;
					}
				}
			}
			else
			{
				printf("CANTIDAD DE KILOS MAYOR A LO REGISTRADO\n");
			}
		}
		else
		{
			printf("ID NO ENCONTRADO\n");
		}
	}
	return error;
}

void mostrarProcesar(eProcesar procesar)
{
	printf("ID  KILOS   ESTADO   ID PED\n");
	printf("%2d %3d     %5s  %2d\n",procesar.idProcesar,procesar.cantidadKilos,
	procesar.estadoPedido,procesar.idPedido);
}

void mostrarProcesados(eProcesar procesados[], int tamProcesados)
{
	if(procesados!=NULL && tamProcesados>0)
	{
		for(int i=0; i<tamProcesados; i++)
		{
			if(procesados[i].isEmpty==1)
			{
				mostrarProcesar(procesados[i]);
			}
		}
	}
}


