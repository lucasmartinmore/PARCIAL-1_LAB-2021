/*
 * clientes.c
 *
 *  Created on: 9 oct. 2021
 *      Author: ACantarini
 */
#include "clientes.h"

int menu()
{
    system("cls");
	int opcion;
	opcion=validarEntero("1)ALTA CLIENTE\n2)MODIFICAR CLIENTE\n3)BAJA CLIENTE\n4)CREAR PEDIDO\n5)PROCESAR RESIDUO\n6)IMPRIMIR CLIENTE\n7)IMPRIMIR PEDIDOS PEND\n8)IMPRIMIR PEDIDOS PROC\n9)IMP PED PEND POR LOC\n10)CANT POL REC\n\n\nIngrese opcion: \n", "Opcion invalidad, reingrese opcion: \n", 1, 10);
	return opcion;
}

void inicializarCliente(eCliente clientes[], int tamCliente)
{
    if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			clientes[i].isEmpty=0;
		}
	}
}

int buscarPosicionVaciaCliente(eCliente clientes[], int tamCliente, int* posicion)
{
    int error;
	error=-1;
	*posicion=-1;
	if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==0)
			{
				*posicion=i;
				error=0;
				break;
			}
		}
	}
	return error;
}

int altaCliente(eCliente clientes[], int posicion, int id)
{
	system("cls");
	printf("*****MENU ALTA*****\n");
    int error;
    error=1;
	if(clientes!=NULL && posicion!=-1)
	{
		validarCadena("Ingrese nombre de la empresa: \n","Nombre invalido, reingrese nuevamente: \n", 50,clientes[posicion].nombreEmpresa);
		validarCadena("Ingrese direccion de la empresa: \n","Direccion invalida, reingrese nuevamente: \n", 50,clientes[posicion].direccion);
		validarCadena("Ingrese localidad de la empresa: \n","Localidad invalida, reingrese nuevamente: \n", 50,clientes[posicion].localidad);
		clientes[posicion].cuil=validarEntero("Ingrese CUIT de la empresa: \n","CUIT invalido, reingrese nuevamente: \n", 1, 99999);
		clientes[posicion].idCliente=id;
		clientes[posicion].isEmpty=1;
		error=0;
    }
	return error;
}

int buscarCliente(eCliente clientes[], int tamCliente, int id)
{
	int posicion=-1;
	if(clientes!=NULL && tamCliente>0 && id>99)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].idCliente==id && clientes[i].isEmpty==1)
			{
				posicion=i;
				break;
			}
		}
	}
	return posicion;
}

void mostrarCliente(eCliente cliente)
{
	printf("------------------------------------------\n");
	printf("ID   NOMBRE   CUIT   DIRECCION   LOCALIDAD\n");
	printf("------------------------------------------\n");
	printf("%3d %8s %6d %12s %10s\n",cliente.idCliente,cliente.nombreEmpresa,
	cliente.cuil,cliente.direccion,cliente.localidad);
}

int mostrarClientes(eCliente clientes[], int tamCliente)
{
	int error=-1;
	if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarCliente(clientes[i]);
				error=0;
			}
		}
	}
	return error;
}

int bajaCliente(eCliente clientes[], int tamCliente)
{
	system("cls");
	printf("*****MENU BAJA*****\n");
	int id;
	int posicion;
	int confirmar;
	int error;
	error=-1;

	if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarCliente(clientes[i]);
			}
		}
	}

	id=validarEntero("\nIngrese numero de id: \n", "Error, reingrese id: \n", 100, 999);
	posicion=buscarCliente(clientes, tamCliente, id);

	if(posicion!=-1)
	{
		confirmar=validarEntero("\nDesea confirmar eliminacion del cliente (1)SI 2)NO: \n", "Opcion invalida, reingrese: \n", 1, 2);
		if(confirmar==1)
		{
			clientes[posicion].isEmpty=0;
			clientes[posicion].idCliente=' ';
			error=0;
		}
		else
		{
			printf("BAJA CANCELADA\n");
		}

	}
	else
	{
		printf("ID NO ENCONTRADO\n");
	}
	return error;

}

int subMenuModificarCliente()
{
	system("cls");
	int opcion;
	printf("*****MENU MODIFICAR*****\n");
	opcion=validarEntero("1)Direccion\n2)Localidad\n\nIngrese opcion a modificar: \n", "Opcion invalidad, reingrese opcion: \n", 1, 2);
	return opcion;
}

int modificarCliente(eCliente clientes[], int tamCliente)
{
	system("cls");
	printf("*****MENU MODIFICAR*****\n");
	int error;
	int id;
	int posicion;
	char auxDireccion[50];
	char auxLocalidad[50];
	error=-1;

	if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarCliente(clientes[i]);
			}
		}

		id=validarEntero("\nIngrese numero de id: \n", "Error, reingrese id: \n", 100, 999);
		posicion=buscarCliente(clientes, tamCliente, id);

		if(posicion!=-1)
		{
			switch(subMenuModificarCliente())
			{
			case 1:
				validarCadena("Ingrese nueva direccion: \n","Error, reingrese nueva direccion: \n", 50, auxDireccion);
				strcpy(clientes[posicion].direccion,auxDireccion);
				break;
			case 2:
				validarCadena("Ingrese nueva localidad: \n","Error, reingrese nueva localidad: \n", 50, auxLocalidad);
				strcpy(clientes[posicion].localidad,auxLocalidad);
				break;
			}
			error=0;
		}
		else
		{
			printf("ID NO ENCONTRADO\n");
		}
	}
	return error;
}
