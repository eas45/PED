#include "tlistacom.h"

// ##############
// # TLISTANODO #
// ##############

/******************
 * FORMA CANÓNICA *
 ******************/

// Constructor por defecto
TListaNodo::TListaNodo ()
{
  anterior = NULL;
  siguiente = NULL;
}

// Constructor de copia
TListaNodo::TListaNodo (const TListaNodo& nodo)
{
  Copia(nodo);
}

// Destructor
TListaNodo::~TListaNodo ()
{
  if (anterior != NULL || siguiente != NULL)
  {
    anterior = NULL;
    siguiente = NULL;
  }
}

// Operador asignación
TListaNodo&
TListaNodo::operator= (const TListaNodo& nodo)
{
  if (this != &nodo)
  {
    this->~TListaNodo();
    Copia(nodo);
  }
}

/*********************
 * GETTERS Y SETTERS *
 *********************/

TComplejo
TListaNodo::Elemento () const
{
  return e;
}

TListaNodo*
TListaNodo::Anterior () const
{
  return anterior;
}

TListaNodo*
TListaNodo::Siguiente () const
{
  return siguiente;
}

/***********************
 * MÉTODOS Y FUNCIONES *
 ***********************/

void
TListaNodo::Copia (const TListaNodo& nodo)
{
  e = nodo.Elemento();
  anterior = nodo.Anterior();
  siguiente = nodo.Siguiente();
}

// #############
// # TLISTAPOS #
// #############

/******************
 * FORMA CANÓNICA *
 ******************/

// Constructor por defecto
TListaPos::TListaPos ()
{
  pos = NULL;
}

// Constructor a partir de un nodo
TListaPos::TListaPos (TListaNodo* posNodo)
{
  pos = posNodo;
}

// Constructor de copia
TListaPos::TListaPos (const TListaPos& nuevaPosicion)
{
  pos = nuevaPosicion.Pos();
}

// Destructor
TListaPos::~TListaPos ()
{
  pos = NULL;
}

// Operador asignación
TListaPos&
TListaPos::operator= (const TListaPos& nuevaPosicion)
{
  if (this != &nuevaPosicion)
  {
    this->~TListaPos();
    pos = nuevaPosicion.Pos();
  }
}

/********************
 * OTROS OPERADORES *
 ********************/

bool
TListaPos::operator== (const TListaPos& posicion) const
{
  if (pos == posicion.Pos())
  {
    return true;
  }

  return false;
}

bool
TListaPos::operator!= (const TListaPos& posicion) const
{
  return !((*this) == posicion);
}

/*********************
 * GETTERS Y SETTERS *
 *********************/

// Devuelve la posición anterior
TListaPos
TListaPos::Anterior () const
{
  return TListaPos(pos->anterior);
}

// Devuelve la posición siguiente
TListaPos
TListaPos::Siguiente () const
{
  return TListaPos(pos->siguiente);
}

// Devuelve el puntero que contiene el atributo 'pos'
TListaNodo*
TListaPos::Pos () const
{
  return pos;
}

/***********************
 * MÉTODOS Y FUNCIONES *
 ***********************/

bool
TListaPos::esVacia () const
{
  if (pos == NULL)
  {
    return true;
  }
  
  return false;
}

// #############
// # TLISTACOM #
// #############

/******************
 * FORMA CANÓNICA *
 ******************/

// Constructor por defecto
TListaCom::TListaCom ()
{
  primero = NULL;
  ultimo = NULL;
}

// Constructor de copia
TListaCom::TListaCom (const TListaCom& lista)
{
  // TODO
}

// Desctructor
TListaCom::~TListaCom ()
{
  // TODO
}

// Sobrecarga de operador asignación
TListaCom&
TListaCom::operator= (const TListaCom& lista)
{
  // TODO
}

/********************
 * OTROS OPERADORES *
 ********************/
/* Sobrecarga del operador igualdad
    Dos listas son iguales si poseen los mismos elementos en el mismo orden
*/
bool
TListaCom::operator== (const TListaCom& lista) const
{
  // TODO
}

// Sobrecarga del operador desigualdad
bool
TListaCom::operator!= (const TListaCom& lista) const
{

}

/* Sobrecarga del operador suma
    Une los elementos de dos listas en una nueva lista.
    Primero los elementos de la primera lista y acontinuación los de la segunda
*/
TListaCom
TListaCom::operator+ (const TListaCom& lista) const
{

}

/*********************
 * GETTERS Y SETTERS *
 *********************/

/***********************
 * MÉTODOS Y FUNCIONES *
 ***********************/