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

TListaNodo::TListaNodo (const TComplejo& complejo)
{
  siguiente = anterior = NULL;
  e = complejo;
}

// Constructor de copia
TListaNodo::TListaNodo (const TListaNodo& nodo)
{
  Copia(nodo);
}

// Destructor
TListaNodo::~TListaNodo ()
{
  anterior = NULL;
  siguiente = NULL;
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
  pos = nuevaPosicion.pos;
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
    pos = nuevaPosicion.pos;
  }
}

/********************
 * OTROS OPERADORES *
 ********************/

bool
TListaPos::operator== (const TListaPos& posicion) const
{
  if (pos == posicion.pos)
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
  TListaPos posicionAnterior;

  if (pos != NULL)
  {
    posicionAnterior = pos->anterior;
  }

  return posicionAnterior;
}

// Devuelve la posición siguiente
TListaPos
TListaPos::Siguiente () const
{
  TListaPos posicionSiguiente;

  if (pos != NULL)
  {
    posicionSiguiente = pos->siguiente;
  }

  return posicionSiguiente;
}

TListaNodo*
TListaPos::Pos () const
{
  return pos;
}

/***********************
 * MÉTODOS Y FUNCIONES *
 ***********************/

bool
TListaPos::EsVacia () const
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
  Inic();
}

// Constructor de copia
TListaCom::TListaCom (const TListaCom& lista)
{
  Copia(lista);
}

// Desctructor
TListaCom::~TListaCom ()
{
  Borra();
}

// Sobrecarga de operador asignación
TListaCom&
TListaCom::operator= (const TListaCom& lista)
{
  if (this != &lista)
  {
    // Se destruye la lista actual
    Borra();
    Copia(lista);
  }

  return (*this);
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
  TListaPos posicionLista1(primero);
  TListaPos posicionLista2(lista.primero);

  while (!posicionLista1.EsVacia() && !posicionLista2.EsVacia())
  {
    if (posicionLista1.pos->e != posicionLista2.pos->e)
    {
      return false;
    }
    posicionLista1 = posicionLista1.pos->siguiente;
    posicionLista2 = posicionLista2.pos->siguiente;
  }

  if (posicionLista1 == posicionLista2)
  {
    return true;
  }

  return false;
}

// Sobrecarga del operador desigualdad
bool
TListaCom::operator!= (const TListaCom& lista) const
{
  return !(*this == lista);
}

/* Sobrecarga del operador suma
    Une los elementos de dos listas en una nueva lista.
    Primero los elementos de la primera lista y acontinuación los de la segunda
*/
TListaCom
TListaCom::operator+ (const TListaCom& lista) const
{
  TListaCom resultado(lista);
  TListaPos posicion(ultimo);

  while (!posicion.EsVacia())
  {
    resultado.InsCabeza(posicion.pos->e);
    posicion = posicion.pos->anterior;
  }

  return resultado;
}

TListaCom
TListaCom::operator- (const TListaCom& lista) const
{
  TListaCom resultado;
  // Se recorrerá la lista desde el final
  TListaPos posicion(Ultima());

  while (!posicion.EsVacia())
  {
    if (!lista.Buscar(posicion.pos->e))
    { // Si el número complejo de la posición NO está en la lista
      // Se añade al resultado
      resultado.InsCabeza(posicion.pos->e);
    }
    // Se cambia a la posición anterior
    posicion = posicion.pos->anterior;
  }

  return resultado;
}

/*********************
 * GETTERS Y SETTERS *
 *********************/

// Devuelve la primera posición de la lista
TListaPos
TListaCom::Primera () const
{
  return TListaPos(primero);
}

// Devuelve la última posición de la lista
TListaPos
TListaCom::Ultima () const
{
  return TListaPos(ultimo);
}

/***********************
 * MÉTODOS Y FUNCIONES *
 ***********************/

// Inicializa la lista vacía
void
TListaCom::Inic ()
{
  primero = NULL;
  ultimo = NULL;
}

/* Realiza la copia exacta de los elementos de los nodos de la lista
*/
void
TListaCom::Copia (const TListaCom& lista)
{
  Inic();
  // Se crea un nodo auxiliar para recorrer la lista que se quiere copiar
  TListaPos posicion(lista.ultimo);

  while (!posicion.EsVacia() && InsCabeza(posicion.pos->e))
  { // Inserta el número complejo que tiene ese nodo en la cabeza
    // Comprueba el siguiente nodo
    posicion = posicion.Anterior();
  }
}

void
TListaCom::Borra ()
{
  TListaPos posicionAborrar;

  while (primero != NULL)
  {
    posicionAborrar = primero;
    primero = primero->siguiente;
    delete posicionAborrar.pos;
  }
  Inic();
}

// Devuelve TRUE si la lista está vacía, FALSE en caso contrario
bool
TListaCom::EsVacia () const
{
  if (primero == NULL && ultimo == NULL)
  {
    return true;
  }

  return false;
}

/* Recorre la lista y comprueba si la posición pertenece a la lista
    Devolverá TRUE si la posición pertenece a la lista y
    FALSE en el caso contrario
*/
bool
TListaCom::Pertenece (const TListaPos& posicion) const
{
  TListaPos posLista = primero;

  while (posLista != NULL)
  {
    if (posLista == posicion)
    {
      return true;
    }
    posLista = posLista.pos->siguiente;
  }
  return false;
}

/* Inserta el elemento en la cabeza de la lista
    Devuelve TRUE si la inserción es llevada a cabo correctamente
    y FALSE en caso de no poder reservar memoria
*/
bool
TListaCom::InsCabeza (const TComplejo& complejo)
{
  // Se reserva memoria para el nuevo nodo
  TListaNodo* nuevoNodo = new TListaNodo;

  if (nuevoNodo != NULL)
  {
    // Se le da valor al número complejo del nuevo nodo
    nuevoNodo->e = complejo;
    if (primero != NULL)
    { // Si había un primer nodo antes
      // El nodo que ahora es primero tendrá como anterior al nuevo nodo
      primero->anterior = nuevoNodo;
    }
    // El siguiente nodo al nuevo nodo será el que antes era el primer nodo
    nuevoNodo->siguiente = primero;
    // Ahora el primer nodo es el nuevo nodo
    primero = nuevoNodo;
    if (ultimo == NULL)
    { // Si no había último nodo
      // El nuevo nodo es también el último nodo
      ultimo = primero;
    }

    return true;
  }

  return false;
}

// Inserta el elemento a la izquierda de la posición indicada
bool
TListaCom::InsertarI (const TComplejo& complejo, const TListaPos& posicion)
{
  if (!posicion.EsVacia())
  {
    if (posicion.pos == primero)
    { // Si es el primer nodo
      // Será como insertar un nodo a la cabeza de la lista
      return InsCabeza(complejo);
    }
    else
    { // Si no, se hace una inserción normal a la izquierda
      TListaNodo* nuevoNodo = new TListaNodo;
      if (nuevoNodo != NULL)
      {
        nuevoNodo->e = complejo;
        // El nodo en esta posición pasará a ser el siguiente del nuevo nodo
        nuevoNodo->siguiente = posicion.pos;
        // El nodo anterior del nuevo nodo será el nodo anterior de su siguiente nodo
        nuevoNodo->anterior = posicion.pos->anterior;
        // El nodo siguiente del anterior a la posición será el nuevo nodo
        posicion.pos->anterior->siguiente = nuevoNodo;
        // El nodo anterior de la posición será el nuevo nodo
        posicion.pos->anterior = nuevoNodo;
        return true;
      }
    }
    return true;
  }
  return false;
}

// Inserta el elemento a la derecha de la posición indicada
bool
TListaCom::InsertarD (const TComplejo& complejo, const TListaPos& posicion)
{
  TListaNodo* nuevoNodo = new TListaNodo;

  if (!posicion.EsVacia() && nuevoNodo != NULL)
  { // Si no es una posición vacía y se ha podido reservar memoria
    nuevoNodo->e = complejo;
    // El nodo en esta posición pasará a ser el anterior del nuevo nodo
    nuevoNodo->anterior = posicion.pos;
    // El nodo siguiente del nuevo nodo será el nodo siguiente de la posición
    nuevoNodo->siguiente = posicion.pos->siguiente;
    if (posicion.pos == ultimo)
    { // Si es el último nodo
      // Se actualiza el puntero de la lista
      ultimo = nuevoNodo;
    }
    else
    { // Si no es el último nodo
      // El nodo anterior del siguiente nodo a la posición es el nuevo nodo
      posicion.pos->siguiente->anterior = nuevoNodo;
    }
    // El nodo siguiente de la posición será el nuevo nodo
    posicion.pos->siguiente = nuevoNodo;
    
    return true;
  }

  return false;
}

// Busca y borra LA PRIMERA ocurrencia del elemento
bool
TListaCom::Borrar (const TComplejo& complejo)
{
  TListaPos posicion(primero);

  while (!posicion.EsVacia())
  {
    if (posicion.pos->e == complejo)
    {
      return Borrar(posicion);
    }
    posicion = posicion.pos->siguiente;
  }

  return false;
}

// Busca y borra TODAS las ocurrencias del elemento
bool
TListaCom::BorrarTodos (const TComplejo& complejo)
{
  TListaPos posicion(primero);
  TListaPos posicionAborrar;

  while (!posicion.EsVacia())
  {
    if (posicion.pos->e == complejo)
    {
      posicionAborrar = posicion;
      posicion = posicion.pos->siguiente;
      Borrar(posicionAborrar);
    }
    else
    {
      posicion = posicion.pos->siguiente;
    }
  }

  return !posicionAborrar.EsVacia();
}

// Borra el elemento que ocupa la posición indicada
bool
TListaCom::Borrar (TListaPos& posicion)
{
  if (Pertenece(posicion))
  { // Si la posición pertenece a la lista, se puede borrar
    // Se enlaza los nodos adyacentes entre sí
    if (!posicion.Anterior().EsVacia())
    { // Si tiene una posición anterior
      // El nodo siguiente del anterior a la posición será el siguiente
      posicion.pos->anterior->siguiente = posicion.pos->siguiente;
    }
    else
    { // Si no tiene, es que es primero
      // Primero apuntará al siguiente nodo
      primero = posicion.pos->siguiente;
    }
    
    if (!posicion.Siguiente().EsVacia())
    { // Si tiene un posición siguiente
      // El nodo anterior del siguiente a la posición será el anterior
      posicion.pos->siguiente->anterior = posicion.pos->anterior;
    }
    else
    { // Sino tiene, es que es último
      ultimo = posicion.pos->anterior;
    }
    
    // Se borra la posición actual
    delete posicion.pos;
    posicion.~TListaPos();

    return posicion.EsVacia();
  }

  return false;
}

// Obtiene el elemento que ocupa la posición indicada
TComplejo
TListaCom::Obtener (const TListaPos& posicion) const
{
  if (!posicion.EsVacia())
  {
    return posicion.pos->e;
  }

  return TComplejo();
}

// Devuelve TRUE si el elemento está en la lista, FALSE en caso contrario
bool
TListaCom::Buscar (const TComplejo& complejo) const
{
  TListaPos posicion(primero);

  while (!posicion.EsVacia())
  {
    if (posicion.pos->e == complejo)
    {
      return true;
    }
    posicion = posicion.pos->siguiente;
  }

  return false;
}

// Devuelve el número de nodos de la lista
int
TListaCom::Longitud () const
{
  int longitud = 0;
  TListaPos posicion(primero);

  while (posicion != NULL)
  {
    longitud++;
    posicion = posicion.Siguiente();
  }

  return longitud;
}

// Sobrecarga del operador salida
ostream&
operator<< (ostream& os, const TListaCom& lista)
{
  TListaPos posicion = lista.primero;
  bool primero = true;

  os << "{";
  while (posicion != NULL)
  {
    if (!primero)
    {
      os << " ";
    }
    else
    {
      primero = false;
    }
    
    os << posicion.Pos()->Elemento();
    posicion = posicion.Siguiente();
  }
  os << "}";

  return os;
}