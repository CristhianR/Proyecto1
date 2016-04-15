/*
 * Carro.h
 *
 *  Created on: Apr 6, 2016
 *      Author: allanchacon
 */

#ifndef CARRO_H_
#define CARRO_H_
#include "xMMa.h"
#include "xObject.h"
#include "xMemoryManagerFinal.h"


class Carro: public xObject{
public:
	Carro();
	int generacion=10;
	virtual ~Carro();
	void* operator new(size_t);
};

#endif /* CARRO_H_ */
