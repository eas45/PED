#include "tabbcom.h"

/*
  -Función Raiz
    1) Devolver valor de la raíz
    2) Si está vacío, TComplejo vacío
*/

int main ()
{
  TComplejo a(-3, 2), b(3, -2), c(-3, -2), d(3, 2), e(1, -2), f(7, 4);
  TABBCom arbol1;
  // Estructura árbol1
  arbol1.Insertar(b);
  arbol1.Insertar(c);
  arbol1.Insertar(d);
  arbol1.Insertar(f);
  arbol1.Insertar(e);
  arbol1.Insertar(a);
  // arbol1:
  //            b
  //          /   \ 
  //         c     d
  //       /   \     \ 
  //      e     a     f


  return 0;
}