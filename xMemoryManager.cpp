
#include "xMemoryManager.h"
#include "Pelota.h"
#include "xObject.h"
#include "Animal.h"
#include "RC.h"
#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

/*
 * Antes de empezar:
 * La diferencia del Templade con la forma común de la clase, es que le va agregar el Smart Pointer a la clase.
 * Como consecuencia se tiene que al crearce el objeto y terminar alguna intrucción, el SmartPointer se borra.
 * Por lo que borra el objeto, por esa razón si usan el Templade del Xpointer para las clases, a la hora
 * de instanciar en el main,  aparecerá:
 * 
 * Objeto creado.
 * Obeto borrado.
 * 
 * Pero eso de momento no afecta, pues la funciones del SP aun no son del todo funcional.
 * Por lo tanto el delete de la clase solo esta de adorno, el que manda es el del xMemory.
 */

unsigned char xMemoryManager::pool[malloc * sizeof(xMemoryManager)]; 
bool xMemoryManager::alloc_map[malloc] = {false};

int ID = 0;
void* xMemoryManager::operator new(size_t) throw(bad_alloc) {
    
  for(int i = 0; i < malloc; i++)
    if(!alloc_map[i]) { 
      cout << "using block " << i << " ... " << endl;
      alloc_map[i] = true; // Mark it used
      ID += 1;
      //cout << ID << endl;
      void* ptrID = &ID;
      return pool + (i * sizeof(xMemoryManager));
    }
  
  out << "out of memory" << endl;
  throw bad_alloc();
}


// OJO: ACÁ SE CAMBIA EL VALOR DE P.
// Los valores comunes son: para el for (6301824) y la forma de uno a uno es (6301440).
// Lo que se hace es asignarle el valor de memoria del new xMemori, al xPointer para que funcione el delete.
unsigned long p = 6301824;
bool flag = false;
void xMemoryManager::operator delete(void* m) { 
    
  if(!m) return; // Check for null pointer
  if(flag == false){
  unsigned long block = p - (unsigned long)pool; // Vean el valor del pool en consola, con eso pueden manipular las direcciones.
  cout << (unsigned long)m << " - " << (unsigned long)pool << " = " << block << endl;
  //cout << sizeof(xMemoryManager) << endl;
  block /= sizeof(xMemoryManager);
  cout << "freeing block " << block << endl;
  // Mark it free:
  cout << "Objeto borrado." << endl;
  alloc_map[block] = false;
  flag = true;
  }
  else {
      p += 10;
      unsigned long block = p - (unsigned long)pool;
  cout << (unsigned long)m << " - " << (unsigned long)pool << " = " << block << endl;
  block /= sizeof(xMemoryManager);
  cout << "freeing block " << block << endl;
  // Mark it free:
  cout << "Objeto borrado." << endl;
  alloc_map[block] = false;
  }
}


// Apartir de aca van los new y delete de las clases.


void* Animal::operator new(size_t,void* pos) {
    pos = new xMemoryManager;
        return pos;
    
}
    

void Animal::operator delete(void*) {
    
}


void* Pelota::operator new(size_t,void* loc) {
    loc = new xMemoryManager;
        return loc;
    
}
    

void Pelota::operator delete(void*) {
    
}


// templade para los smart pointer.
template < typename T > class xPointer
{
private:
    T*    pData;       // pointer
    RC* reference; // Reference count

public:
    xPointer() : pData(0), reference(0) // constructor base.
    {
        // Crea una nueva referencia 
        reference = new RC();
        // Incrementa el reference count
        reference->AddRef();
    }

    xPointer(T* pValue) : pData(pValue), reference(0)
    {
        // Crea una nueva referencia 
        reference = new RC();
        // Incrementa el reference count
        reference->AddRef();
    }

    xPointer(const xPointer<T>& sp) : pData(sp.pData), reference(sp.reference)
    {
        // Copia del constructor
        // Copia el data y el puntero de referencia
        // e incrementa el reference count
        reference->AddRef();
    }

    ~xPointer()
    {
        // Destructor
        // Decrementa el reference count
        // si la referencia llega a cero borra el dato
        if(reference->Release() == 0)
        {
            delete pData;
            delete reference;
        }
    } 
    
    // Se sobrecargan los operadores de los SP.
    T& operator* ()
    {
        return *pData;
    }

    T* operator-> ()
    {
        return pData;
    }
    
    T& operator ++ ()
    {
        this->pData ++;
        return *this;
    }
    
    T& operator -- ()
    {
        this->pData --;
        return *this;
    }
    
    
    T& operator + (const T &p)
    {
    this->pData += p.pData;
    return *this;
    }
    
    T& operator - (const T &p)
    {
    this->pData -= p.pData;
    return *this;
    }
    
    
    bool operator== (const xPointer<T> &x) const
    {
        cout << "me llamaron" << endl;
        return this->pData == x.pData;
    }
    
    xPointer<T>& operator = (const xPointer<T>& sp)
    {
        // Assignment operator
        if (this != &sp) // Evita su auto asignación
        {
            // Decrementa el viejo reference count
            // si la referencia llega a cero borra el dato pasado.
            if(reference->Release() == 0)
            {
                delete pData;
                delete reference;
            }

            // Copia el dato y el puntero de referencia
            // e incrementa el reference count
            pData = sp.pData;
            reference = sp.reference;
            reference->AddRef();
        }
        return *this;
    }
};

// Son dos pruebas: Una de uno a uno y la otra con ciclo for.

int main() {
    
  cout << "Solicitando espacio de memoria virtual...hecho" << endl;
  xMemoryManager* f[xMemoryManager::malloc];
  
  // Acá se prueban una a una los new y delete de cada clase
  // OJO: CAMBIAR EL VALOR DE P EN: 6301440
  // Esto quiere decir que solo se puede hacer una prueba a la vez, no las dos al mismo tiempo, por eso deben 
  // documentar una de las dos primeros.
  //NOTA: EN CASO DE QUE LES DE SEGMENTATION FAULD, NADA MÁS VEAN EL VALOR DEL POOL Y PONGASELON A P.
  // EL VALOR DEL POOL ES EL QUE SE ESTÁ RESTANDO (¡¡¡EN CONSOLA!!!)
  
  /*Pelota* pelota1 = new(0) Pelota;
  Animal* animal = new(0) Animal;
  Pelota* pelota3 = new(0) Pelota;
  delete f[0];
  delete f[1];
  delete f[2];*/
 
  
  // Acá es para crear varios objetos hasta llenar memoria.
  try {
      
    for (int i = 0; i < xMemoryManager::malloc; i++){
        //Pelota* pelota = new(0) Pelota;
        //xPointer <Pelota> pelota(new(0) Pelota);
        Pelota* pelota3 = new(0) Pelota;
        //xPointer <Animal> animal(new(0) Animal);
    }
  
     Pelota* pelota = new(0) Pelota; // esta linea hace que lance la excepsión, pues la memoria ya está llena.
  } catch (bad_alloc){
      cerr << "¡Memoria Agotada!" << endl;
  }
  
  // Acá se borran los objetos.
  for(int j = 0; j < xMemoryManager::malloc; j++){
      cout << j << endl;
      delete f[j];
  } // Delete f[10] OK 
  
  
} ///:~


