/*
 * Nodo.h
 *
 *  Created on: Apr 14, 2016
 *      Author: allanchacon
 */

#ifndef NODO_H_
#define NODO_H_
#include<stdlib.h>

struct xSize
{
	void* inicio;// Direccion en el heap donde va estar el objeto.
	void* final;
	int cantidad;
	int Id;// A esta variable apunta el xPointer.
	int referense;// Para saber cuantos xPointer estan apuntando al mismo sitio en memoria.
	bool reserved;// Para saber si el sitio ya esta ocupado.
};
class Nodo
{


public:
	xSize info;
	Nodo* sig;
	void swap()
	{
		if(info.reserved==false)
		{
			info.reserved=true;
		}
		else
		{
			info.reserved=false;

		}
	}

	Nodo(void* inicio, void* final, int cantidad, int id)
	{
		sig=NULL;
		info.Id=id;
		info.cantidad=cantidad;
		info.final=final;
		info.inicio=inicio;
		info.referense=1;
		info.reserved=true;


	}
};







#endif /* NODO_H_ */
