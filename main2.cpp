/* 
 * File:   main.cpp
 * Author: cristhian
 *
 * Created on March 24, 2016, 12:45 AM
 */

#include <cstdlib>

//: C13:PlacementOperatorNew.cpp
// Placement with operator new()
#include <cstddef> // Size_t
#include <iostream>
using namespace std;


// Maes esta clase es una idea de lo que tiene que hacer los SP
// Basicamente toma la posición del puntero de int L y pasa al objeto X a esa posición.
class X {
  int i;
public:
    // Constructor base
  X(int ii = 0) : i(ii) {
    cout << "this = " << this << endl;
  }
  // Destructor
  ~X() {
    cout << "X::~X(): " << this << endl;
  }
  // Operador sobrecargado.
  void* operator new(size_t, void* loc) {
    return loc;
  }
};

int main() {
  int l[10];
  cout << "l = " << l << endl;
  X* xp = new(l) X(47); // X at location l
  xp->X::~X(); // Explicit destructor call
  // ONLY use with placement!
} ///:~

