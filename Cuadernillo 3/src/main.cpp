#include "tavlcom.h"

int main ()
{
  TAVLCom a;
  TComplejo c0(0), c1(1), c2(2), c3(3), c4(4), c5(5), c6(6), c7(7), c8(8), c9(9);

  cout << "- Inserción 8" << endl;
  a.Insertar(c8);
  cout << "+ Árbol resultado : " << a << endl;
  cout << "- Inserción 9" << endl;
  a.Insertar(c9);
  cout << "+ Árbol resultado : " << a << endl;
  cout << "- Inserción 3" << endl;
  a.Insertar(c3);
  cout << "+ Árbol resultado : " << a << endl;
  cout << "- Inserción 4" << endl;
  a.Insertar(c4);
  cout << "+ Árbol resultado : " << a << endl;
  cout << "- Inserción 2" << endl;
  a.Insertar(c2);
  cout << "+ Árbol resultado : " << a << endl;
  cout << "- Inserción 1" << endl;
  a.Insertar(c1);

  cout << "Resultado rotación II : " << a << endl << endl;

  TAVLCom b;
  cout << "- Inserción 4" << endl;
  b.Insertar(c4);
  cout << "+ Árbol resultado : " << b << endl;
  cout << "- Inserción 1" << endl;
  b.Insertar(c1);
  cout << "+ Árbol resultado : " << b << endl;
  cout << "- Inserción 5" << endl;
  b.Insertar(c5);
  cout << "+ Árbol resultado : " << b << endl;
  cout << "- Inserción 0" << endl;
  b.Insertar(c0);
  cout << "+ Árbol resultado : " << b << endl;
  cout << "- Inserción 2" << endl;
  b.Insertar(c2);
  cout << "+ Árbol resultado : " << b << endl;
  cout << "- Inserción 3" << endl;
  b.Insertar(c3);

  cout << "Resultado rotación ID : " << b << endl;

  return 0;
}