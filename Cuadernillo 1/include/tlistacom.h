/*
* Lista DOBLEMENTE ENLAZADA y NO ORDENADA
* Se permiten elementos repetidos
*/

#ifndef _TLISTACOM_
#define _TLISTACOM_

#include "tcomplejo.h"

// Representa cada NODO de la lista
class TListaNodo
{
  friend class TListaCom;
  friend class TListaPos;

  private:
  // El elemento del nodo
  TComplejo e;
  // El nodo anterior
  TListaNodo *anterior;
  // El nodo siguiente
  TListaNodo *siguiente;

  // Copia los datos de un nodo en el actual
  void Copia (const TListaNodo&);

  public:
  // Constructor por defecto
  TListaNodo ();
  // Constructor de copia
  TListaNodo (const TListaNodo&);
  // Destructor
   ~TListaNodo ();
  // Sobrecarga operador asignación
  TListaNodo& operator= (const TListaNodo&);

  TComplejo Elemento () const;
  TListaNodo* Anterior () const;
  TListaNodo* Siguiente () const;
};

class TListaPos
{
  friend class TListaCom;

  private:
  // Puntero a un nodo de la lista
  TListaNodo *pos;

  public:
  // Constructor por defecto
  TListaPos ();
  // Constructor a partir de un nodo
  TListaPos (TListaNodo*);
  // Constructor de copia
  TListaPos (const TListaPos&);
  // Destructor
  ~TListaPos ();
  // Operador asignación
  TListaPos& operator= (const TListaPos&);

  // Sobrecarga del operador igualdad
  bool operator== (const TListaPos&) const;
  // Sobrecarga del operador desigualdad
  bool operator!= (const TListaPos&) const;
  
  // Devuelve la posición anterior
  TListaPos Anterior () const;
  // Devuelve la posición siguiente
  TListaPos Siguiente () const;
  // Devuelve el puntero que contiene el atributo 'pos'
  TListaNodo* Pos () const;

  // Devuelve TRUE si la posición no apunta a una lista,
  // FALSE en caso contrario
  bool esVacia () const;
};

#endif