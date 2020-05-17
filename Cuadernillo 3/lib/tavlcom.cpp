#include "tavlcom.h"

/************
 * TNODOAVL *
 ************/

/*
  La clase TNodoAVL utiliza el constructor y destructor por defecto.
  Por lo que no se ha visto necesario escribir una implementación de ambos métodos.
*/

// Constructor por defecto
TNodoAVL::TNodoAVL (const int& fe = 0)
{
  this->fe = fe;
}

// Constructor con el valor del item
TNodoAVL::TNodoAVL (const TComplejo& complejo, const int& fe = 0)
{
  item = complejo;
  this->fe = fe;
}

// Constructor de copia
TNodoAVL::TNodoAVL (const TNodoAVL& nodo)
{
  Copia(nodo);
}

// Destructor
TNodoAVL::~TNodoAVL ()
{
  fe = 0;
}

TNodoAVL&
TNodoAVL::operator= (const TNodoAVL& nodo)
{
  if (this != &nodo)
  {
    this->~TNodoAVL();
    Copia(nodo);
  }

  return (*this);
}

/////////////
// MÉTODOS //
/////////////

void
TNodoAVL::Copia (const TNodoAVL& nodo)
{
  // Copia el valor del item del nodo
  item = nodo.item;
  // Copia el valor de factor de equilibrio
  fe = nodo.fe;
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
TNodoAVL::EsHoja () const
{
  if (iz.EsVacio() && de.EsVacio())
  {
    return true;
  }
  return false;
}

// Devuelve el factor de equilibrio del nodo (hr - hl)
int
TNodoAVL::FactorEquilibrio () const
{
  return (de.Altura() - iz.Altura());
}

/***********
 * TAVLCOM *
 ***********/

TAVLCom::TAVLCom ()
{
  Inic();
}

TAVLCom::TAVLCom (const TAVLCom& arbol)
{
  Copia(arbol);
}

// Destructor
TAVLCom::~TAVLCom ()
{
  if (!EsVacio())
  {
    delete nodo;
    nodo = NULL;
  }
}

TAVLCom&
TAVLCom::operator= (const TAVLCom& arbol)
{
  if (this != &arbol)
  {
    this->~TAVLCom();
    Copia(arbol);
  }

  return (*this);
}

void
TAVLCom::Inic ()
{
  nodo = NULL;
}

void
TAVLCom::Copia (const TAVLCom& arbol)
{
  Inic();
  if (!arbol.EsVacio())
  {
    nodo = new TNodoAVL(arbol.nodo->item);
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
TAVLCom::operator== (const TAVLCom& arbol) const
{
  return (Inorden() == arbol.Inorden());
}

bool
TAVLCom::operator!= (const TAVLCom& arbol) const
{
  return !(Inorden() == arbol.Inorden());
}

bool
TAVLCom::EsVacio () const
{
  return (nodo == NULL);
}

bool
TAVLCom::InsertarAux (const TComplejo& complejo, bool& crece)
{
  // Devuelve si se ha podido insertar o no
  bool ok, creceIz, creceDe = false;

  if (EsVacio())
  { // Si el árbol está vacío
    // Se inserta
    nodo = new TNodoAVL(complejo);
    ok = crece = true;
  }
  else if (complejo != Raiz())
  {
    if (complejo < Raiz())
    {
      ok = nodo->iz.InsertarAux(complejo, crece);
      creceIz = crece;
    }
    else
    {
      ok = nodo->de.InsertarAux(complejo, crece);
      creceDe = crece;
    }

    if (creceIz || creceDe)
    { // Si alguno de los dos subárboles crece
      if (creceIz && (nodo->fe == -1))
      {
        // Se rota
        cout << "Debería hacer una rotación por la izquierda\n";
      }
      else if (creceDe && (nodo->fe == 1))
      {
        // Se rota
        cout << "Debería hacer una rotación por la derecha\n";
      }
      else
      {
        // Se actualiza FE
        nodo->fe = nodo->FactorEquilibrio();
        cout << "Factor de equilibrio del nodo " << nodo->item << " actualizado a " << nodo->fe << endl;
      }
    }
  }
  // Si ya existe, no se inserta
  return ok;
}

bool
TAVLCom::Insertar (const TComplejo& complejo)
{
  bool crece = false;

  return InsertarAux(complejo, crece);
}

// Busca el nodo mayor del árbol moviéndose hacia la derecha
TComplejo
TAVLCom::Mayor ()
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
TAVLCom::BorrarAux (TAVLCom* padre, const TComplejo& complejo)
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
          padre->nodo->iz.~TAVLCom();
        }
        else
        { // Si es el hijo de la derecha
          // Lo elimina
          padre->nodo->de.~TAVLCom();
        }
      }
      else
      { // Si no tiene padre (es un árbol hoja)
        // Se elimina sin más
        this->~TAVLCom();
      }
    }
    else if (nodo->iz.EsVacio())
    { // Si el árbol izdo es vacío, tiene un árbol dcho
      // Se copia el hijo dcho
      TAVLCom arbolAux(nodo->de);
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
      TAVLCom arbolAux(nodo->iz);
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
TAVLCom::Borrar (const TComplejo& complejo)
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
TAVLCom::Buscar (const TComplejo& complejo) const
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
TAVLCom::Raiz () const
{
  if (!EsVacio())
  {
    return nodo->item;
  }

  return error;
}

int
TAVLCom::Altura () const
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
TAVLCom::Nodos () const
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
TAVLCom::NodosHoja () const
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
TAVLCom::InordenAux (TVectorCom& recorrido, int& posicion) const
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
TAVLCom::Inorden () const
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
TAVLCom::PreordenAux (TVectorCom& recorrido, int& posicion) const
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
TAVLCom::Preorden () const
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
TAVLCom::PostordenAux (TVectorCom& recorrido, int& posicion) const
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
TAVLCom::Postorden () const
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
TAVLCom::Niveles () const
{
  // Se crea un vector donde guardar el resultado del recorrido
  TVectorCom recorrido(Nodos());
  // Posición inicial del recorrido
  int posicion = 1;
  // Crea la cola
  queue<TAVLCom*> colaArboles;
  // Variable auxiliar que contiene el primer árbol de la cola
  TAVLCom* arbolAux;

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

ostream& operator<< (ostream& os, const TAVLCom& arbol)
{
  os << arbol.Inorden();

  return os;
}