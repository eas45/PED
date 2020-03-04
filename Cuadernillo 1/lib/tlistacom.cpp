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

// Devuelve el puntero que contiene el atributo 'pos'
TListaNodo*
TListaPos::Pos () const
{
  return pos;
}

/***********************
 * MÉTODOS Y FUNCIONES *
 ***********************/

// #############
// # TLISTACOM #
// #############

/******************
 * FORMA CANÓNICA *
 ******************/

/*********************
 * GETTERS Y SETTERS *
 *********************/

/***********************
 * MÉTODOS Y FUNCIONES *
 ***********************/