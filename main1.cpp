/* 
 * File:   main.cpp
 * Author: cristhian
 * Manejador de memoria.
 * Created on March 24, 2016, 12:58 AM
 */

#include <cstdlib>

// Local overloaded new & delete
#include <cstddef> // Size_t
#include <fstream>
#include <iostream>
#include <new>
using namespace std;
ofstream out("Framis.out");

// La idea de esta clase es manejar la memoria "virtual" de un programa
/*
 * Basicamente crea una fuente (como las que se crean para hilos) pero en este caso de memoria.
 * Utiliza una variable booleana para mapear esa fuente (realmente es un arreglo).
 * Se utliza la condición false para representar memoria libre y true para ocupada
 * La vara es agarrar de acá ideas para el manejador que tenemos que hacer.
 */

class xMemoryManager {
    
  enum { sz = 10 };
  char c[sz]; // To take up space, not used
  static unsigned char pool[]; // aca va el "mar" de memoria
  static bool alloc_map[]; // Esta variable busca espacios desocupados.
  
public:
  enum { malloc = 100 };  // capacidad permitida para la clase.
  xMemoryManager() { out << "Framis()\n"; } 
  ~xMemoryManager() { out << "~Framis() ... "; }
  void* operator new(size_t) throw(bad_alloc); // Operador sobrecargado y una excepción por si no hay memoria.
  void operator delete(void*); 
};

// Se implementan las funciones de la clase.
unsigned char xMemoryManager::pool[malloc * sizeof(xMemoryManager)];
bool xMemoryManager::alloc_map[malloc] = {false};

// Size is ignored -- assume a Framis object
void* 
xMemoryManager::operator new(size_t) throw(bad_alloc) {
    //Recorre el arreglo de memoria a ver si hay campo
  for(int i = 0; i < malloc; i++)
      // si no es falso, es porque está ocupado.
    if(!alloc_map[i]) {
      out << "using block " << i << " ... ";
      alloc_map[i] = true; // Lo ocupa y lo marca como usado
      return pool + (i * sizeof(xMemoryManager));
    }
  
  // En caso de no haya campo, se lanza la excepción.
  out << "out of memory" << endl;
  throw bad_alloc();
}

// Acá el destructor hace algo parecido solo que cambia el espacio a false.
void xMemoryManager::operator delete(void* m) {
  if(!m) return; // Check for null pointer
  // Assume it was created in the pool
  // Calculate which block number it is:
  unsigned long block = (unsigned long)m
    - (unsigned long)pool;
  block /= sizeof(xMemoryManager);
  out << "freeing block " << block << endl;
  // Mark it free:
  alloc_map[block] = false;
}

int main() {
  xMemoryManager* f[xMemoryManager::malloc];
  try {
    for(int i = 0; i < xMemoryManager::malloc; i++)
      f[i] = new xMemoryManager;
    // Si comentan esta linea que sigue, pueden probar el código hasta llenarlo de una manera distinta.
    new xMemoryManager; // Out of memory
  } catch(bad_alloc) {
    cerr << "Out of memory!" << endl;
  }
  delete f[10];
  f[10] = 0;
  // Use released memory:
  xMemoryManager* x = new xMemoryManager;
  delete x;
  for(int j = 0; j < xMemoryManager::malloc; j++)
    delete f[j]; // Delete f[10] OK
} ///:~

