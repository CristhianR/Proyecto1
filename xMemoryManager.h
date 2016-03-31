/* 
 * File:   xMemoryManager.h
 * Author: cristhian
 *
 * Created on March 28, 2016, 6:32 PM
 */

#ifndef XMEMORYMANAGER_H
#define	XMEMORYMANAGER_H


#include <cstdlib>

// Local overloaded new & delete
#include <cstddef> // Size_t
#include <fstream>
#include <iostream>
#include <new>

using namespace std;
ofstream out("Framis.out");

// La idea de esta clase es manejar la memoria "virtual" de un programa

class xMemoryManager {
public:
  enum { sz = 10 };
  char c[sz]; // To take up space, not used
  static unsigned char pool[];
  static bool alloc_map[];
public:
  enum { malloc = 10};  // frami allowed
  xMemoryManager() { out << "Framis()\n"; }
  ~xMemoryManager() { out << "~Framis() ... "; }
  void* operator new(size_t) throw(bad_alloc);
  void operator delete(void*);
};


#endif	/* XMEMORYMANAGER_H */

