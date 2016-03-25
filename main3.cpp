/* 
 * File:   main.cpp
 * Author: cristhian
 *
 * Created on March 22, 2016, 12:05 AM
 */

#include<iostream>
#include <cstddef> // Size_t
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <new>

using namespace std;

// Esta es la clase padre de todas las demás clases.
/*
 * Tiene como método el serialize para generar la representacion del objeto en JSON.
 * Además cuenta con un deseralize y dos métodos más para obtener el nombre de la clase a la cual pertenece el 
 * xObject y otro similar pero para obtener el ID.
 */
class xObject{
public:
    void* serialize();
    bool deserialize();
    char* getClassName();
    long getId();
};


/*
 * Esta clase sirve para llevar un conteo de las veces que se construye o destruye un objeto con los xPointer.
 * Este conteo evita que se apunte a un objeto inexistente.
 */
class RC
{
    private:
    int count; // Reference count

    public:
    void AddRef()
    {
        // Incrementa el reference count
        count++;
    }

    int Release()
    {
        // Decrementa el reference count y
        // retorna el reference count.
        return --count;
    }
};

 
// Esta es la clase genérica para los Smarts Pointer (SP) o xPointers.
template < typename T > class xPointer
{
private:
    int a;
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


 


// Este es un ejemplo de un  clase que hereda de xObject.
class Person: xObject
{
    int age;
    char* pName;

    public:
        Person(): pName(0),age(0)
        {
        }
        Person(char* pName, int age): pName(pName), age(age)
        {
        }
        ~Person()
        {
        }
        // Se sobrecarga el operador new. La idea es hacer un placement new
        
        void Display()
        {
            printf("Name = %s Age = %d \n", pName, age);
        }
        void Shout()
        {
            printf("Ooooooooooooooooo");
        } 
};







int main()
{
    xPointer<Person> p(new Person("Scott", 25));
    p->Display();
    
    if (p == p){
        cout << "ok" << endl;
    }
    
    {
        xPointer<Person> q = p;
        q->Display();
        // Destructor of q will be called here..

        xPointer<Person> r;
        r = p;
        r->Display();
        // Destructor of r will be called here..
    }
    p->Display();
    // Destructor of p will be called here 
    // and person pointer will be deleted
    
    return 0;
}




