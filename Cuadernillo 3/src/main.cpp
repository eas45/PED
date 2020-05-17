#include "tavlcom.h"

int main ()
{
  TAVLCom a;
  TComplejo c1(1), c2(2), c3(3), c4(4), c5(5);

  cout << "- Inserción 2" << endl;
  a.Insertar(c2);
  cout << "- Inserción 1" << endl;
  a.Insertar(c1);
  cout << "- Inserción 3" << endl;
  a.Insertar(c3);
  cout << "- Inserción 4" << endl;
  a.Insertar(c4);
  cout << "- Inserción 5" << endl;
  a.Insertar(c5);

  return 0;
}