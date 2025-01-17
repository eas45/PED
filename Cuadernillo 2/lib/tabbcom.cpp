#include "tabbcom.h"

/************
 * TNODOABB *
 ************/

/*
  La clase TNodoABB utiliza el constructor y destructor por defecto.
  Por lo que no se ha visto necesario escribir una implementación de ambos métodos.
*/

// Constructor por defecto
TNodoABB::TNodoABB ()
{
  // Sin implementación
}

// Constructor con el valor del item
TNodoABB::TNodoABB (const TComplejo& complejo)
{
  item = complejo;
}

// Constructor de copia
TNodoABB::TNodoABB (const TNodoABB& nodo)
{
  Copia(nodo);
}

// Destructor
TNodoABB::~TNodoABB ()
{
  // Sin implementación
}

TNodoABB&
TNodoABB::operator= (const TNodoABB& nodo)
{
  if (this != &nodo)
  {
    this->~TNodoABB();
    Copia(nodo);
  }

  return (*this);
}

void
TNodoABB::Copia (const TNodoABB& nodo)
{
  // Copia el valor del item del nodo
  item = nodo.item;
  // Copia ambos los subárboles hijo
  if (!nodo.iz.EsVacio())
  {
    iz = nodo.iz;
  }
  if (!nodo.de.EsVacio())
  {
    de = nodo.de;
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

// Destructor
TABBCom::~TABBCom ()
{
  if (!EsVacio())
  {
    delete nodo;
    nodo = NULL;
  }
}

TABBCom&
TABBCom::operator= (const TABBCom& arbol)
{
  if (this != &arbol)
  {
    this->~TABBCom();
    Copia(arbol);
  }

  return (*this);
}

void
TABBCom::Inic ()
{
  nodo = NULL;
}

void
TABBCom::Copia (const TABBCom& arbol)
{
  Inic();
  if (!arbol.EsVacio())
  {
    nodo = new TNodoABB(arbol.nodo->item);
    // aux->item = arbol.nodo->item;
    // nodo = aux;
    if (!arbol.nodo->iz.EsVacio())
    {
      nodo->iz = arbol.nodo->iz;
    }
    if (!arbol.nodo->de.EsVacio())
    {
      nodo->de = arbol.nodo->de;
    }
  }
}

/////////////
// MÉTODOS //
/////////////

/* Compara ambos recorridos inorden, ya que no depende de la
    estructura del árbol si no de que tenga los mismos elementos
*/
bool
TABBCom::operator== (const TABBCom& arbol) const
{
  return (Inorden() == arbol.Inorden());
}

bool
TABBCom::EsVacio () const
{
  return (nodo == NULL);
}

bool
TABBCom::Insertar (const TComplejo& complejo)
{
  if (EsVacio())
  { // Si el árbol está vacío
    // Se inserta
    nodo = new TNodoABB(complejo);
    return true;
  }
  if (complejo != Raiz())
  {
    if (complejo < Raiz())
    {
      return nodo->iz.Insertar(complejo);
    }
    return nodo->de.Insertar(complejo);
  }
  // Si ya existe, no se inserta
  return false;
}

// Busca el nodo mayor del árbol moviéndose hacia la derecha
TComplejo
TABBCom::Mayor ()
{
  if (!nodo->de.EsVacio())
  { // Si se puede ir más hacia la derecha
    // Se sigue buscando 
    return nodo->de.Mayor();
  }
  // Si no, se está en el nodo mayor
  return nodo->item;
}

void
TABBCom::BorrarAux (TABBCom* padre, const TComplejo& complejo)
{
  if (complejo != Raiz())
  { // Si no es
    if (complejo < Raiz())
    { // Si es menor, va por la izquierda
      nodo->iz.BorrarAux(this, complejo);
    }
    else
    { // Si no, por la derecha
      nodo->de.BorrarAux(this, complejo);
    }
  }
  else
  { // Si es ese
    if (nodo->EsHoja())
    { // Comprueba si es hoja
      if (padre != NULL)
      { // Si tiene padre
        if (&padre->nodo->iz == this)
        { // Comprueba si es el hijo de la izquierda
          // Lo elimina
          padre->nodo->iz.~TABBCom();
        }
        else
        { // Si es el hijo de la derecha
          // Lo elimina
          padre->nodo->de.~TABBCom();
        }
      }
      else
      { // Si no tiene padre (es un árbol hoja)
        // Se elimina sin más
        this->~TABBCom();
      }
    }
    else if (nodo->iz.EsVacio())
    { // Si el árbol izdo es vacío, tiene un árbol dcho
      // Se copia el hijo dcho
      TABBCom arbolAux(nodo->de);
      if (padre != NULL)
      { // Si tiene padre
        if (&padre->nodo->iz == this)
        { // Comprueba si es el hijo de la izquierda
          // Lo intercambia
          padre->nodo->iz = arbolAux;
        }
        else
        { // Si es el hijo de la derecha
          // Lo intercambia
          padre->nodo->de = arbolAux;
        }
      }
      else
      { // Si no tiene padre
        // Se intercambia por su hijo
        (*this) = arbolAux;
      }
    }
    else if (nodo->de.EsVacio())
    { // Si el árbol decho es vacío, tiene un árbol izdo
      // Se copia el hijo izdo
      TABBCom arbolAux(nodo->iz);
      if (padre != NULL)
      { // Si tiene padre
        if (&padre->nodo->iz == this)
        { // Comprueba si es el hijo de la izquierda
          // Lo intercambia
          padre->nodo->iz = arbolAux;
        }
        else
        { // Si es el hijo de la derecha
          // Lo intercambia
          padre->nodo->de = arbolAux;
        }
      }
      else
      { // Si no tiene padre
        // Se intercambia por su hijo
        (*this) = arbolAux;
      }
    }
    else
    { // Si tiene 2 hijos
      // Busca el mayor nodo del hijo izquierdo
      TComplejo itemAux = nodo->iz.Mayor();
      // Se elimina el mayor nodo del hijo izquierdo
      BorrarAux(this, itemAux);
      // Se guarda el valor del mayor en el nodo actual
      nodo->item = itemAux;
    }
  }
}

bool
TABBCom::Borrar (const TComplejo& complejo)
{
  if (Buscar(complejo))
  { // Si está en el árbol
    // Se busca con una función auxiliar recursiva
    BorrarAux(NULL, complejo);

    return true;
  }

  return false;
}

// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool
TABBCom::Buscar (const TComplejo& complejo) const
{
  if (!EsVacio())
  {
    if (complejo == Raiz())
    {
      return true;
    }
    // Comprueba si es menor que el item y si puede moverse hacia el hijo izquierdo
    if (complejo < Raiz())
    {
      if (!nodo->iz.EsVacio())
      {
        return nodo->iz.Buscar(complejo);
      }
      return false;
    }
    else
    { // Comprueba si puede moverse hacia el hijo derecho
      if (!nodo->de.EsVacio())
      {
        return nodo->de.Buscar(complejo);
      }
      return false;
    }
  }
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

/* Recorrido inorden:
    IRD
*/
void
TABBCom::InordenAux (TVectorCom& recorrido, int& posicion) const
{
  // Llama al hijo izquierdo
  if (!nodo->iz.EsVacio())
  {
    nodo->iz.InordenAux(recorrido, posicion);
  }
  // Escribe
  recorrido[posicion] = Raiz();
  posicion++;
  // Llama al hijo derecho
  if (!nodo->de.EsVacio())
  {
    nodo->de.InordenAux(recorrido, posicion);
  }
}

TVectorCom
TABBCom::Inorden () const
{
  if (EsVacio())
  {
    return TVectorCom();
  }
  // Se crea un vector donde guardar el resultado del recorrido
  TVectorCom recorrido(Nodos());
  // Posición inicial del recorrido
  int posicion = 1;
  // Llamada a la implementación del recorrido
  if (!EsVacio())
  {
    InordenAux(recorrido, posicion);
  }

  return recorrido;
}

/* Recorrido preorden
    RID
*/
void
TABBCom::PreordenAux (TVectorCom& recorrido, int& posicion) const
{
  // Escribe
  recorrido[posicion] = Raiz();
  posicion++;
  // Llama al hijo izquierdo
  if (!nodo->iz.EsVacio())
  {
    nodo->iz.PreordenAux(recorrido, posicion);
  }
  // Llama al hijo derecho
  if (!nodo->de.EsVacio())
  {
    nodo->de.PreordenAux(recorrido, posicion);
  }
}

TVectorCom
TABBCom::Preorden () const
{
  if (EsVacio())
  {
    return TVectorCom();
  }

  // Se crea un vector donde guardar el resultado del recorrido
  TVectorCom recorrido(Nodos());
  // Posición inicial del recorrido
  int posicion = 1;
  // Llamada a la implementación del recorrido con l
  PreordenAux(recorrido, posicion);

  return recorrido;
}

/* Recorrido postorden
    IDR
*/
void
TABBCom::PostordenAux (TVectorCom& recorrido, int& posicion) const
{
  // Llama al hijo izquierdo
  if (!nodo->iz.EsVacio())
  {
    nodo->iz.PostordenAux(recorrido, posicion);
  }
  // Llama al hijo derecho
  if (!nodo->de.EsVacio())
  {
    nodo->de.PostordenAux(recorrido, posicion);
  }
  // Escribe
  recorrido[posicion] = Raiz();
  posicion++;
}

TVectorCom
TABBCom::Postorden () const
{
  if (EsVacio())
  {
    return TVectorCom();
  }
  // Se crea un vector donde guardar el resultado del recorrido
  TVectorCom recorrido(Nodos());
  // Posición inicial del recorrido
  int posicion = 1;
  // Llamada a la implementación del recorrido con l
  PostordenAux(recorrido, posicion);

  return recorrido;
}

// Recorrido por niveles
TVectorCom
TABBCom::Niveles () const
{
  // Se crea un vector donde guardar el resultado del recorrido
  TVectorCom recorrido(Nodos());
  // Posición inicial del recorrido
  int posicion = 1;
  // Crea la cola
  queue<TABBCom*> colaArboles;
  // Variable auxiliar que contiene el primer árbol de la cola
  TABBCom* arbolAux;

  if (EsVacio())
  {
    return TVectorCom();
  }
  // Escribe la raíz
  recorrido[posicion] = Raiz();
  posicion++;
  // Encola los árboles iz y de
  if (!nodo->iz.EsVacio())
  {
    colaArboles.push(&(nodo->iz));
  }
  if (!nodo->de.EsVacio())
  {
    colaArboles.push(&(nodo->de));
  }
  while (!colaArboles.empty())
  { // Mientras la cola no esté vacía
    // Saca el primer árbol
    arbolAux = colaArboles.front();
    // Desencola el primer árbol
    colaArboles.pop();
    // Escribe la raíz
    recorrido[posicion] = arbolAux->Raiz();
    posicion++;
    // Encola los árboles iz y de
    if (!arbolAux->nodo->iz.EsVacio())
    {
      colaArboles.push(&(arbolAux->nodo->iz));
    }
    if (!arbolAux->nodo->de.EsVacio())
    {
      colaArboles.push(&(arbolAux->nodo->de));
    }
  }

  return recorrido;
}

// OPERADOR SALIDA

ostream& operator<< (ostream& os, const TABBCom& arbol)
{
  os << arbol.Niveles();

  return os;
}