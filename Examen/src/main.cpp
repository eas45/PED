#include "tabbcom.h"

int main ()
{
  TABBCom a; TListaCom L; TComplejo *x;
  L.InsCabeza(TComplejo(26));
  L.InsCabeza(TComplejo(83));
  L.InsCabeza(TComplejo(74));
  L.InsCabeza(TComplejo(68));
  L.InsCabeza(TComplejo(25));
  L.InsCabeza(TComplejo(42));
  L.InsCabeza(TComplejo(75));
  L.InsCabeza(TComplejo(23));
  L.InsCabeza(TComplejo(50));
  x = a.MostrarNiveles(L);
  if (x==NULL) cout << "CORRECTO" << endl;

  // -----


  return 0;
}