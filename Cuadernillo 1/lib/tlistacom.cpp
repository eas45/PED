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
  return TListaPos(pos->anterior);
}

// Devuelve la posición siguiente
TListaPos
TListaPos::Siguiente () const
{
  return TListaPos(pos->siguiente);
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
  Inic();
}

// TODO
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
  // TODO
}

// Sobrecarga del operador desigualdad
bool
TListaCom::operator!= (const TListaCom& lista) const
{
  // TODO
}

/* Sobrecarga del operador suma
    Une los elementos de dos listas en una nueva lista.
    Primero los elementos de la primera lista y acontinuación los de la segunda
*/
TListaCom
TListaCom::operator+ (const TListaCom& lista) const
{
  // TODO
}

TListaCom
TListaCom::operator- (const TListaCom& lista) const
{
  // TODO
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

TListaNodo*
TListaPos::Pos () const
{
  return pos;
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
  bool insercionOK = true;  // Variable que controla que la inserción haya ido bien

  Inic();
  // Se crea un nodo auxiliar para recorrer la lista que se quiere copiar
  TListaPos posicion(lista.ultimo);

  while (!posicion.esVacia() && InsCabeza(posicion.pos->e))
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
TListaCom::esVacia () const
{
  if (primero == NULL && ultimo == NULL)
  {
    return true;
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
  if (!posicion.esVacia())
  {
    if (posicion.pos == primero)
    { 
      /* Si es primero, al insertarse a la izquierda, será como insertar un nodo a la
          cabeza de la lista */
      return InsCabeza(complejo);
    }
    else
    {
      TListaNodo* nuevoNodo = new TListaNodo;
      nuevoNodo->e = complejo;
    }
    
    return true;
  }

  return false;
}

// Inserta el elemento a la derecha de la posición indicada
bool
TListaCom::InsertarD (const TComplejo& complejo, const TListaPos& posicion)
{
  // TODO
}

// Busca y borra LA PRIMERA ocurrencia del elemento
bool
TListaCom::Borrar (const TComplejo& complejo)
{
  // TODO
}

// Busca y borra TODAS las ocurrencias del elemento
bool
TListaCom::BorrarTodos (const TComplejo& complejo)
{
  // TODO
}

// Borra el elemento que ocupa la posición indicada
bool
TListaCom::Borrar (const TListaPos& posicion)
{
  // TODO
}

// Obtiene el elemento que ocupa la posición indicada
TComplejo
TListaCom::Obtener (const TListaPos& posicion) const
{
  
}

// Devuelve TRUE si el elemento está en la lista, FALSE en caso contrario
bool
TListaCom::Buscar (const TComplejo& complejo) const
{
  // TODO
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

  os << "{";
  while (posicion != NULL)
  {
    os << posicion.Pos()->Elemento();
    posicion = posicion.Siguiente();
  }
  os << "}";

  return os;
}