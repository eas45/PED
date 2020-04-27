#include "tabbcom.h"

/*
  Criterios de ordenación:
  Comprobar que se insertan los números complejos
  en el orden correcto
  1) Módulo
  2) Parte real
  3) Parte imaginaria
*/

int main ()
{
  // Ordenación por módulo
  TComplejo a(-3, 2), b(3, -2), c(-3, -2), d(3, 2), e(1, -2), f(7, 4);
  TVectorCom recorridoIn(2);
  recorridoIn[1] = e;
  recorridoIn[2] = a;
  TABBCom arbol1;
  //    a
  //   /
  //  e
  arbol1.Insertar(a);
  arbol1.Insertar(e);

  if (recorridoIn == arbol1.Inorden())
  {
    cout << "OK - Inserción arbol1\n";
  }
  else
  {
    cout << "ERROR - Inserción arbol1\n";
  }
  
  TABBCom arbol2;
  //    e
  //   /
  //  f
  recorridoIn[1] = e;
  recorridoIn[2] = f;
  arbol2.Insertar(e);
  arbol2.Insertar(f);

  if (recorridoIn == arbol2.Inorden())
  {
    cout << "OK - Inserción arbol2\n";
  }
  else
  {
    cout << "ERROR - Inserción arbol2\n";
  }

  // Comprobación de todos los elementos
  //            b
  //          /   \ 
  //         c     d
  //       /   \     \ 
  //      e     a     f
  TABBCom arbol3;
  arbol3.Insertar(b);
  arbol3.Insertar(c);
  arbol3.Insertar(d);
  arbol3.Insertar(f);
  arbol3.Insertar(e);
  arbol3.Insertar(a);

  TVectorCom inorden(6);
  inorden[1] = e;
  inorden[2] = c;
  inorden[3] = a;
  inorden[4] = b;
  inorden[5] = d;
  inorden[6] = f;

  if (arbol3.Inorden() == inorden)
  {
    cout << "OK - Inserción arbol3\n";
  }
  else
  {
    cout << "ERROR - Inserción arbol3\n";
  }

  return 0;
}