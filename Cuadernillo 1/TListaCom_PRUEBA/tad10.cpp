/* Prueba:
    - De todo
*/
#include "tlistacom.h"

int
main(void)
{
  TListaCom tl1;
  TComplejo c1;
  TComplejo c2(1, 2);

  // Prueba la inserción en cabeza
  tl1.InsCabeza(c2);
  tl1.InsCabeza(c1);
  tl1.InsCabeza(c2);
  tl1.InsCabeza(c1);
  tl1.InsCabeza(c2);
  tl1.InsCabeza(c1);
  cout << tl1 << endl;

  // Prueba el constructor de copia
  TListaCom tl2(tl1);
  cout << tl2 << endl;

  // Prueba el operador asignación
  TListaCom tl3;
  tl3 = tl2;
  cout << tl3 << endl;

  // Prueba la inserción a la izquierda
  TListaCom* tl4 = new TListaCom();
  tl4->InsCabeza(c2);
  cout << *tl4 << endl;
  tl4->InsertarI(c2, tl4->Primera());
  tl4->InsertarI(c1, tl4->Ultima());
  tl4->InsertarI(c1, tl4->Primera().Siguiente());
  cout << *tl4 << endl;

  // Prueba la inserción a la derecha
  TListaCom* tl5 = new TListaCom();
  tl5->InsCabeza(c2);
  cout << *tl5 << endl;
  tl5->InsertarD(c2, tl5->Primera());
  tl5->InsertarD(c1, tl5->Ultima());
  tl5->InsertarD(c1, tl5->Primera().Siguiente());
  cout << *tl5 << endl;

  // Prueba la función borrar posición
  TListaPos pos = tl4->Primera();
  if (tl4->Borrar(pos))
  {
    cout << "Borrado 1" << endl;
  }
  cout << *tl4 << endl;
  pos = tl5->Primera();
  if (tl4->Borrar(pos))
  {
    cout << "Borrado 2" << endl;
  }

  tl4->~TListaCom();
  tl5->~TListaCom();

  return 0;
}