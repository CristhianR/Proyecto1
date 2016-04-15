/*
 * Carro.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: allanchacon
 */

#include "Carro.h"
#include<new>
#include"iostream";
#include "xMMa.h"


Carro::Carro() {
	// TODO Auto-generated constructor stub

}

Carro::~Carro() {
	// TODO Auto-generated destructor stub
}

void* Carro::operator new(size_t)
{

	return xMemoryManagerFinal::xCalloc(sizeof(Carro));
}

