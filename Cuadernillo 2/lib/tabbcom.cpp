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
  // Inic();
  // Copia el valor del item del nodo
  item = nodo.item;
  // Copia ambos los subárboles hijo
  if (!nodo.iz.EsVacio())
  {
    //iz.Copia(nodo.iz);
    iz = nodo.iz;
  }
  if (!nodo.de.EsVacio())
  {
    //de.Copia(nodo.de);
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

bool
TABBCom::Borrar (const TComplejo& complejo)
{
  if (Buscar(complejo))
  { // Si está en el árbol
    TVectorCom inorden(Inorden());
    TVectorCom preorden(Preorden());
    int posicion = 0;
    TComplejo intercambiar;
    bool encontrado = false;

    // Cuando es un árbol hoja
    if (nodo->EsHoja())
    {
      this->~TABBCom();
      return true;
    }
    // Cuando no es un árbol hoja
    // Busco en inorden el elemento
    for (int i = 1; i <= inorden.Tamano() && posicion == 0; i++)
    {
      if (inorden[i] == complejo)
      {
        posicion = i;
      }
    }

    if (posicion == 1)
    {
      // Eliminar el nodo con un hijo a la derecha
      for (int i = 1; i <= preorden.Tamano() && !encontrado; i++)
      {
        if (complejo == preorden[i])
        { // Cuando encuentra el elemento en el recorrido preorden
          // Se guarda el siguiente para ser intercambiado
          intercambiar = preorden[i+1];
          encontrado = true;
        }
      }
    }
    else
    {
      intercambiar = inorden[posicion - 1];
    }
    
    // Se destruye
    this->~TABBCom();
    // Se reconstruye
    for (int i = 1; i <= preorden.Tamano(); i++)
    {
      if (preorden[i] != complejo && preorden[i] != intercambiar)
      { // Es un nodo más, se debe añadir
        Insertar(preorden[i]);
      }
      else if (preorden[i] == complejo)
      { // Es el elemento que se debe intercambiar
        Insertar(intercambiar);
      }
    }

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
  TVectorCom v(arbol.Niveles());
  os << v;

  return os;
}