/*
 * Main.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: allanchacon
 */

#include<iostream>
#include"Carro.h"
#include"ListaSimple.h"
#include"xMemoryManagerFinal.h"
#include"Perro.h"
using namespace std;

int main()
{
	int n=150;
	xMemoryManagerFinal::solicitarMemoria(n);//Solicita el bloque de memoria.
	cout<<"Espacio de "<<n<<" bytes solicitado al heap"<<endl;
	cout<<"Comienza en la dirección: "<<xMemoryManagerFinal::inicio<<endl;
	cout<<"Termina en la dirección: "<<xMemoryManagerFinal::final<<"\n\n\n";

	Carro* miCarro1 = new Carro();
	Carro* miCarro2 = new Carro();
	Carro* miCarro3 = new Carro();
	//xMemoryManagerFinal::eliminar(1,miCarro1);
	Carro* miCarro4 = new Carro();
	Perro* miPerro1 = new Perro();
	Perro* miPerro2 = new Perro();
	Perro* miPerro3 = new Perro();
	Perro* miPerro4 = new Perro();//Aqui se acaba la memoria











}



