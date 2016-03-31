/* 
 * File:   Pelota.h
 * Author: cristhian
 *
 * Created on March 28, 2016, 8:33 PM
 */

#ifndef PELOTA_H
#define	PELOTA_H

#include <cstddef> // Size_t
#include <fstream>
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include "xObject.h"

using namespace std;


class Pelota : xObject {
    
public:
    Pelota() { puts("Objeto creado."); };
    ~Pelota() { puts("Objeto borrado."); }
    void* operator new(size_t, void*);
    void operator delete(void*);
};


#endif	/* PELOTA_H */

