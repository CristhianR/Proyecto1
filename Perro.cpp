/*
 * Perro.cpp
 *
 *  Created on: Apr 15, 2016
 *      Author: allanchacon
 */

#include "Perro.h"

Perro::Perro() {
	// TODO Auto-generated constructor stub

}

Perro::~Perro() {
	// TODO Auto-generated destructor stub
}

void* Perro::operator new(size_t)
{
	return xMemoryManagerFinal::xCalloc(sizeof(Perro));
}
