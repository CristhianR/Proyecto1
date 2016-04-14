/*
 * xMemoryManager.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: allanchacon
 */

#include "xMMa.h"

xMemoryManager::xMemoryManager() {

}
//Este metodo inicializa el arreglo pool para que esten listos para utilizar sus elemetos.

xMemoryManager::~xMemoryManager() {
	// TODO Auto-generated destructor stub
}

xSize xMemoryManager::lista[]={{(xObject*)calloc(1,sizeof(xObject)),1,0,false},
							{(xObject*)calloc(1,sizeof(xObject)),2,0,false},
							{(xObject*)calloc(1,sizeof(xObject)),3,0,false},
							{(xObject*)calloc(1,sizeof(xObject)),4,0,false},
							{(xObject*)calloc(1,sizeof(xObject)),5,0,false},
							{(xObject*)calloc(1,sizeof(xObject)),6,0,false},
							{(xObject*)calloc(1,sizeof(xObject)),7,0,false},
							{(xObject*)calloc(1,sizeof(xObject)),8,0,false},
							{(xObject*)calloc(1,sizeof(xObject)),9,0,false},
							{(xObject*)calloc(1,sizeof(xObject)),10,0,false}};

void* xMemoryManager::xCalloc()
{
	void* temp=NULL;
	for(int i=0;i<10;i++)
	{
		if(xMemoryManager::lista[i].reserved==false)
		{
			lista[i].reserved=true;
			temp=lista[i].dir;
			break;
		}
	}
	return temp;
}


void xMemoryManager::display()
{
	for(int i=0;i<10;i++)
	{
		std::cout<<i<<":"<<lista[i].dir<<std::endl;
	}
}


