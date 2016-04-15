/*
 * xMemoryManagerFinal.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: allanchacon
 */

#include "xMemoryManagerFinal.h"

xMemoryManagerFinal::xMemoryManagerFinal() {
	// TODO Auto-generated constructor stub

}

xMemoryManagerFinal::~xMemoryManagerFinal() {
	// TODO Auto-generated destructor stub
}

void* xMemoryManagerFinal::inicio=NULL;
void* xMemoryManagerFinal::final=NULL;
ListaSimple xMemoryManagerFinal::ListaMemoria;
int xMemoryManagerFinal::contador=0;

bool xMemoryManagerFinal::espacioLibre()
{

	bool respuesta=false;
	Nodo* temp=ListaMemoria.primero;
	while(temp!=NULL)
	{

		if(temp->info.reserved=false)
		{
			respuesta=true;
			break;

		}
		temp=temp->sig;
	}
	return respuesta;

}

void xMemoryManagerFinal::mostrarUltimo(int cantidad)
{
	cout<<"Se creó un nuevo nodo en ListaMemoria de "<<cantidad<<" bytes\nCon el identificador: "
			<<ListaMemoria.ultimo->info.Id<<endl;
	cout<<"Empieza en "<<ListaMemoria.ultimo->info.inicio<<endl;
	cout<<"Termina en "<<ListaMemoria.ultimo->info.final<<"\n"<<endl;
}

/*void xMemoryManagerFinal::eliminar(int identificador, xObject* eliminar)
{
	eliminar->~xObject();

	Nodo* temp=ListaMemoria.primero;
	bool encontrado=false;
	while(encontrado!=true)
	{

		if(temp->info.Id==identificador)
		{
			ListaMemoria.primero->info.reserved=false;

			encontrado=true;

		}

		temp=temp->sig;

	}

}*/

void* xMemoryManagerFinal::xCalloc(int cantidad)
{
	void* dir;

	if(ListaMemoria.vacio())
	{
		contador++;
		ListaMemoria.meter(inicio,inicio+cantidad,cantidad,contador);
		mostrarUltimo(cantidad);
		dir=inicio;

	}
	else if(espacioLibre())
	{
		cout<<"Estoy aqui"<<endl;
		Nodo* temp=ListaMemoria.primero;
		while(temp!=NULL)
		{

			if(temp->info.reserved=false && temp->info.cantidad==cantidad)
				{

					dir=temp->info.inicio;
					temp->info.reserved=true;
					temp=NULL;
				}
			temp=temp->sig;
		}
	}

	else
	{
		if(ListaMemoria.ultimo->info.final+1+cantidad > final)
			{
			cout<<"Memoria insuficiente para almacenar "<<cantidad<<" bytes"<<endl;
			}
		else
		{
			dir=ListaMemoria.ultimo->info.final+1;
			contador++;
			ListaMemoria.meter(ListaMemoria.ultimo->info.final+1,ListaMemoria.ultimo->info.final+cantidad+1,cantidad,contador);
			mostrarUltimo(cantidad);

		}

	}
	return dir;
}

void xMemoryManagerFinal::solicitarMemoria(int cantidad)
 {
	 void* inicio = calloc(1,cantidad);
	 xMemoryManagerFinal::inicio=inicio;
	 xMemoryManagerFinal::final=inicio+cantidad;


 }



