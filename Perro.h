/*
 * Perro.h
 *
 *  Created on: Apr 15, 2016
 *      Author: allanchacon
 */

#ifndef PERRO_H_
#define PERRO_H_
#include "xObject.h"
#include "xMemoryManagerFinal.h"

class Perro: public xObject {
public:
	int raza;
	char* nombre;
	Perro();
	virtual ~Perro();
	void* operator new(size_t);
};

#endif /* PERRO_H_ */
