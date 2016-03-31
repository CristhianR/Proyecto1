/* 
 * File:   Animal.h
 * Author: cristhian
 *
 * Created on March 30, 2016, 9:49 PM
 */

#ifndef ANIMAL_H
#define	ANIMAL_H

#include <cstddef> // Size_t
#include <fstream>
#include <iostream>
#include <new>
#include <cstdio>
#include <cstdlib>
#include "xObject.h"

using namespace std;


class Animal : xObject {
    
public:
    Animal() { puts("Objeto creado."); };
    ~Animal() { puts("Objeto borrado"); }
    void* operator new(size_t, void*);
    void operator delete(void*);
};

#endif	/* ANIMAL_H */

