/*
 * xMemoryManager.h
 *
 *  Created on: Apr 6, 2016
 *      Author: allanchacon
 */

#ifndef XMMA_H_
#define XMMA_H_

#include"xObject.h"
#include<stdlib.h>
#include<iostream>

struct xSize
{
	xObject* dir;// Direccion en el heap donde va estar el objeto.
	int Id;// A esta variable apunta el xPointer.
	int referense;// Para saber cuantos xPointer estan apuntando al mismo sitio en memoria.
	bool reserved;// Para saber si el sitio ya esta ocupado.
};



class xMemoryManager {
public:

	xMemoryManager();
	virtual ~xMemoryManager();
	static void* xCalloc();
	static xSize lista[];
	static void display();
};


#endif /* XMMA_H_ */
