/*
 * xMemoryManagerFinal.h
 *
 *  Created on: Apr 13, 2016
 *      Author: allanchacon
 */
#ifndef XMEMORYMANAGERFINAL_H_
#define XMEMORYMANAGERFINAL_H_
#include"ListaSimple.h"
#include<iostream>
#include"xObject.h"
using namespace std;



class xMemoryManagerFinal {
public:
	static bool espacioLibre();//Verifica si existe algun nodo con memoria libre.
	static void eliminar(int identificador,xObject* eliminar);//Sin completar.
	static void mostrarUltimo(int cantidad);//Muestra el contenido del ultimo nodo de ListaMemoria.
	static int contador;//Lleva la cuenta de cuantos nodos hay en la lista para asignar el id;
	static void* inicio;//Indica donde inicia el bloque de memoria solicitado.
	static void* final;//Indica donde termina el bloque de memoria solicitado.
	static ListaSimple ListaMemoria;//Lleva el control de donde esta almacenado cada objeto;
	static void* xCalloc(int cantidad);//Hace la solicitud de un espacio en memoria.
	static void solicitarMemoria(int cantidad);//Solicita memoria al heap;
	xMemoryManagerFinal();
	virtual ~xMemoryManagerFinal();
};

#endif /* XMEMORYMANAGERFINAL_H_ */
