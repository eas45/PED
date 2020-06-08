#include "tlistacom.h"
#include "tabbcom.h"

int main ()
{
  TListaCom lista;
  lista.InsCabeza(84);
  lista.InsCabeza(92);
  lista.InsCabeza(84);

  TABBCom arbol;
  arbol.Insertar(68);
  arbol.Insertar(56);
  arbol.Insertar(84);
  arbol.Insertar(35);
  arbol.Insertar(60);
  arbol.Insertar(80);
  arbol.Insertar(98);
  arbol.Insertar(11);
  arbol.Insertar(55);
  arbol.Insertar(64);
  arbol.Insertar(70);
  arbol.Insertar(82);
  arbol.Insertar(92);
  arbol.Insertar(40);
  arbol.Insertar(83);

  return 0;
}