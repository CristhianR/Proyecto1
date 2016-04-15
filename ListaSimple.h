/*
 * Lista.h
 *
 *  Created on: Apr 14, 2016
 *      Author: allanchacon
 */

#ifndef LISTASIMPLE_H_
#define LISTASIMPLE_H_
#include<stdlib.h>
#include"Nodo.h"
#include<iostream>
using namespace std;

class ListaSimple
{


public:
	Nodo* primero;
	Nodo* ultimo;
	ListaSimple()
	{
		primero=ultimo=NULL;
	}

	bool vacio()
	{
		return (primero==NULL);
	}


	void meter(void* inicio, void* final, int cantidad, int id)
	{
		Nodo* temp = new Nodo(inicio, final, cantidad, id);
		if (vacio()==true)
		{
			primero=ultimo=temp;
		}
		else
		{
			ultimo->sig=temp;
			ultimo=temp;
		}


	}

	void borrarPrimero()
	{
		if (vacio()==true)
		{
			cout<<"No se puede eliminar.Lista vacia"<<endl;

		}
		else
		{
			if(primero=ultimo)
			{
				primero=ultimo=NULL;
				cout<<"Elememto eliminado"<<endl;
			}
			else
			{
				Nodo* temp = primero;
				primero=primero->sig;
				delete temp;
				cout<<"Elemento eliminado"<<endl;
			}
		}
	}

	void eliminarFinal()
	{
		if(vacio()==true)
		{
			cout<<"No se puede eliminar.Lista vacia"<<endl;
		}
		else
		{
			Nodo* aux=primero;
			while(aux!=NULL)
			{
				if(primero==ultimo)
				{
					primero=ultimo=NULL;
					cout<<"Elemento eliminado"<<endl;
				}
				else if(aux->sig==ultimo)
				{
					Nodo* temp=ultimo;
					ultimo=aux;
					ultimo->sig=NULL;
					delete temp;
					cout<<"Elemento eliminado"<<endl;
				}
				aux=aux->sig;
			}

		}
	}
};



#endif /* LISTASIMPLE_H_ */
