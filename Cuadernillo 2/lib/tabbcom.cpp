#include "tabbcom.h"

/************
 * TNODOABB *
 ************/

TNodoABB::TNodoABB ()
{
  Inic();
}

TNodoABB::TNodoABB (const TNodoABB& nodo)
{
  Copia(nodo);
}

TNodoABB::~TNodoABB ()
{
  item.~TComplejo();
  iz = NULL;
  de = NULL;
}

TNodoABB&
TNodoABB::operator= (const TNodoABB& nodo)
{
  Copia(nodo);

  return (*this);
}

void
TNodoABB::Inic ()
{
  iz = NULL;
  de = NULL;
}

void
TNodoABB::Copia (const TNodoABB& nodo)
{
  if (this != &nodo)
  {
    this->~TNodoABB();
    Inic();
    // Copia el valor del item del nodo
    item = nodo.item;
    // Copia ambos los subárboles hijo
    if (!nodo.iz.EsVacio())
    {
      iz.Copia(nodo.iz);
    }
    if (!nodo.de.EsVacio())
    {
      de.Copia(nodo.de);
    }
  }
}

bool
TNodoABB::EsHoja () const
{
  if (iz.EsVacio() && de.EsVacio())
  {
    return true;
  }
  return false;
}

/***********
 * TABBCOM *
 ***********/

TABBCom::TABBCom ()
{
  Inic();
}

TABBCom::TABBCom (const TABBCom& arbol)
{
  Copia(arbol);
}

TABBCom::~TABBCom ()
{
  if (!EsVacio())
  {
    delete nodo;
    nodo = NULL;
  }
}

void
TABBCom::Inic ()
{
  nodo = NULL;
}

void
TABBCom::Copia (const TABBCom& arbol)
{
  if (this != &arbol)
  {
    this->~TABBCom();
    Inic();
    nodo = arbol.nodo;
  }
}

/////////////
// MÉTODOS //
/////////////

bool
TABBCom::operator== (const TABBCom& arbol) const
{
  
}

bool
TABBCom::EsVacio () const
{
  return (nodo == NULL);
}

bool
TABBCom::Insertar (const TComplejo& complejo)
{

}

bool
TABBCom::Borrar (const TComplejo& complejo)
{
  
}

bool
TABBCom::Buscar (const TComplejo& complejo) const
{
  
}

TComplejo
TABBCom::Raiz () const
{
  if (!EsVacio())
  {
    return nodo->item;
  }

  return error;
}

int
TABBCom::Altura () const
{
  // Caso base
  if (EsVacio())
  { // Si está vacío, se ha llegado al final del árbol
    return 0;
  }

  // Caso general
  // Se suma uno por cada llamada que haga, ya que equivale a aumentar una altura
  //  y se queda con el mayor de las alturas entre los subárboles
  return (1 + max(nodo->iz.Altura(), nodo->de.Altura()));
}

int
TABBCom::Nodos () const
{
  // Caso base
  if (EsVacio())
  { // Si está vacío, ha terminado de recorrer el árbol
    return 0;
  }
  // Caso general
  // Suma un nodo más a la cuenta y continúa por sus hijos
  return (1 + nodo->iz.Nodos() + nodo->de.Nodos());
}

int
TABBCom::NodosHoja () const
{
  // Caso base
  if (EsVacio())
  { // Si está vacío, no contiene nodos
    return 0;
  }
  else if (nodo->EsHoja())
  { // El nodo es una hoja
    return 1;
  }
  // Caso general
  // Suma las hojas del subárbol izquierdo y el derecho
  return (nodo->iz.NodosHoja() + nodo->de.NodosHoja());
}

////////////////
// RECORRIDOS //
////////////////

TVectorCom
TABBCom::Inorden () const
{
  
}