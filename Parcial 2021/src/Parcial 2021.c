/*
 ============================================================================
 Name        : Parcial.c
 Author      : Lucas More
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "clientes.h"
#include "pedidos.h"
#include "procesados.h"
#include "informes.h"


//DEFINE DE TAMAÑOS
#define TAM_CLIENTE 100
#define TAM_PROCESAR 1000
#define TAM_PEDIDO 1000

//FUNCIONES EXTRAS POR SI LAS MOSCAS
int buscarPedidoMasKilosPendiente(ePedido pedidos[], int tamPedido);
void mostrarPedidoPendienteMasKilos(ePedido pedidos[], int tamPedido, int kilosMasPesado);
int buscarPedidoMasKilosProcesadoPP(eProcesar procesar[], int tamProcesar);
void mostrarPedidoProcesadoPPMasKilos(eProcesar procesar[], int tamProcesar, int kilosMasPesado);

int main(void) {
	setbuf(stdout,NULL);

	//ARRAYS PRINCIPALES

	eCliente clientes[TAM_CLIENTE];/*=
	{
	{100,"Philips",14562,"Barragan 858","G.Catan",1},
	{101,"Malboro",87456,"Saenz 875","Laferrere",1},
	{102,"Cañuelas",78469,"Bariloche 78","Laferrere",1},
	{103,"Molto SA",98632,"Chopin 8754","Casanova",1},
	{104,"Luchetti",74589,"Atalco 5874","C.Evita",1},
	{105,"PepitoSA",57478,"Piedras 858","Balvanera",1},
	{106,"Pepa SRL",74529,"Guemes 7845","Casanova",1}
	};*/

	ePedido pedidos[TAM_PEDIDO];/*=
	{
	{100,1,25,"Pendiente",1},
	{100,2,35,"Pendiente",1},
	{102,3,55,"Pendiente",1},
	{106,4,70,"Pendiente",1},
	{103,5,15,"Pendiente",1},
	{103,6,95,"Pendiente",1},
	{105,7,67,"Pendiente",1},
	{106,8,64,"Pendiente",1},
	{107,9,38,"Pendiente",1},
	{108,10,27,"Pendiente",1},
	};*/

	eProcesar procesar[TAM_PROCESAR];

	//CONTADORES ARRAYS

	int contadorCliente=100;
	int contadorPedidos=1;
	int contadorProcesar=200;

	//INICIADORES DE ARRAYS
	//QUITAR EN CASO DE HARDCODEO
	inicializarCliente(clientes, TAM_CLIENTE);
	inicializarPedido(pedidos, TAM_PEDIDO);
	inicializarProcesar(procesar, TAM_PROCESAR);

	//VARIABLES DE CLIENTES

	int posicionLibreCliente;
	int posicionDisponibleCliente;

	//VARIBLES DE PEDIDOS

	int posicionLibrePedido;
	int posicionDisponiblePedido;

	//VARIABLES DE PROCESAR

	int posicionLibreProcesar;
	int posicionDisponibleProcesar;

	char seguir='s';
	do
	{
		switch(menu())
		{
		case 1:
			posicionLibreCliente=buscarPosicionVaciaCliente(clientes, TAM_CLIENTE, &posicionDisponibleCliente);
			if(posicionLibreCliente!=-1)
			{
				if((altaCliente(clientes, posicionDisponibleCliente, contadorCliente++))!=-1)
				{
					printf("ALTA DE CLIENTE EXITOSA\n");
				}
			}
			else
			{
				printf("NO SE ENCUENTRA NINGUNA POSICION LIBRE\n");
			}
			system("pause");
			break;
		case 2:
			if(modificarCliente(clientes, TAM_CLIENTE)!=-1)
			{
				printf("MODIFICACION EXITOSA\n");
			}
			system("pause");
			break;
		case 3:
			if(bajaCliente(clientes, TAM_CLIENTE)==0)
		    {
				printf("BAJA EXITOSA\n");
			}
			system("pause");
			break;
		case 4:
			posicionLibrePedido=buscarPosicionVaciaPedido(pedidos, TAM_PEDIDO, &posicionDisponiblePedido);
			if(posicionLibrePedido!=-1)
			{
				if(crearPedido(clientes, TAM_CLIENTE, pedidos, contadorPedidos++, posicionDisponiblePedido)==0)
				{
					printf("PEDIDO CREADO EXITOSAMENTE\n");
				}
			}
			else
			{
				printf("NO SE ENCUENTRA NINGUNA POSICION LIBRE\n");
			}
			system("pause");
			break;
		case 5:
			posicionLibreProcesar=buscarPosicionVaciaProcesar(procesar,TAM_PROCESAR, &posicionDisponibleProcesar);
			if(posicionLibreProcesar!=-1)
			{
				if(procesarResiduos(procesar, pedidos, TAM_PEDIDO, contadorProcesar++,posicionDisponibleProcesar)==0)
				{
					printf("PEDIDO PROCESADO EXITOSAMENTE\n");
				}
			}
			else
			{
				printf("NO SE ENCUENTRA NINGUNA POSICION LIBRE\n");
			}
			system("pause");
			break;
		case 6:
			mostrarClienteConPedidosPendiente(clientes, TAM_CLIENTE, pedidos, TAM_PEDIDO);
			system("pause");
			break;
		case 7:
		    if(mostrarPedidosPendienteConCliente(pedidos, TAM_PEDIDO, clientes, TAM_CLIENTE)==-1)
		    {
		    	printf("*****NO SE INGRESO NINGUN PEDIDO*****\n");
		    }
			system("pause");
			break;
		case 8:
			if(mostrarPedidosCompletadosConCliente(procesar, TAM_PROCESAR, pedidos, TAM_PEDIDO)==-1)
			{
				printf("*****NO SE COMPLETO NINGUN PEDIDO*****\n");
			}
			system("pause");
			break;
		case 9:
			if(mostrarPedidosPorLocalidad(pedidos, TAM_PEDIDO, clientes, TAM_CLIENTE)==-1)
			{
				printf("*****NO SE COMPLETO NINGUN PEDIDO EN LA LOCALIDAD INDICADA*****\n");
			}
			system("pause");
			break;
		case 10:
			cantidadPoplipropilenoxCliente(procesar, TAM_PROCESAR);
			system("pause");
			break;
		}
	}while(seguir=='s');
	return EXIT_SUCCESS;
}

int buscarPedidoMasKilosPendiente(ePedido pedidos[], int tamPedido)
{
	int banderaInicial=0;
	int KilosMasPesado;
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].isEmpty==1)
			{
				if((banderaInicial==0 || pedidos[i].cantidadKilos>KilosMasPesado) && strcmp(pedidos[i].estado,"Pendiente")==0)
				{
					KilosMasPesado=pedidos[i].cantidadKilos;
					banderaInicial=1;
				}
			}
		}
	}
	return KilosMasPesado;
}

void mostrarPedidoPendienteMasKilos(ePedido pedidos[], int tamPedido, int kilosMasPesado)
{
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].isEmpty==1 && pedidos[i].cantidadKilos==kilosMasPesado)
			{
				mostrarPedido(pedidos[i]);
			}
		}
	}
}

int buscarPedidoMasKilosProcesadoPP(eProcesar procesar[], int tamProcesar)
{
	int banderaInicial=0;
	int KilosMasPesado;
	if(procesar!=NULL && tamProcesar>0)
	{
		for(int i=0; i<tamProcesar; i++)
		{
			if(procesar[i].isEmpty==1)
			{
				if((banderaInicial==0 || procesar[i].cantidadKilos>KilosMasPesado) && strcmp(procesar[i].estadoPedido,"Completado")==0 && procesar[i].idTipo==3)
				{
					KilosMasPesado=procesar[i].cantidadKilos;
					banderaInicial=1;
				}
			}
		}
	}
	return KilosMasPesado;
}

void mostrarPedidoProcesadoPPMasKilos(eProcesar procesar[], int tamProcesar, int kilosMasPesado)
{
	if(procesar!=NULL && tamProcesar>0)
	{
		for(int i=0; i<tamProcesar; i++)
		{
			if(procesar[i].isEmpty==1 && procesar[i].cantidadKilos==kilosMasPesado && procesar[i].idTipo==3)
			{
				mostrarProcesar(procesar[i]);
			}
		}
	}
}

int buscarClienteConMasPendiente(ePedido pedidos[], int tamPedido)
{
	int acumuladorCliente=0;
	int KilosMasPesado;
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].isEmpty==1 && strcmp(pedidos[i].estado,"Pendiente")==0)
			{
				contador++;
				/*
				 *
				if((banderaInicial==0 || pedidos[i].cantidadKilos>KilosMasPesado) && strcmp(pedidos[i].estado,"Pendiente")==0)
				{
					KilosMasPesado=pedidos[i].cantidadKilos;
					banderaInicial=1;
				}
				*/

			}
		}
	}
	return KilosMasPesado;
}

