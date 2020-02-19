#include "tvectorcom.h"

/******************
 * FORMA CANÓNICA *
 ******************/

// Constructor por defecto
TVectorCom::TVectorCom ()
{
  Inic();
}

// Constructor a partir de un tamaño
TVectorCom::TVectorCom (const int& tam)
{
  if (tam > 0)
  {
    Inic(tam);
  }
  else
  {
    Inic();
  }
}

// Constructor de copia
TVectorCom::TVectorCom (const TVectorCom& vector)
{
  // Se crea el vector del mismo tamaño
  Inic(vector.Tamano());
  Copia(vector);
}

// Destructor
TVectorCom::~TVectorCom ()
{
  if (c != NULL)
  {
    delete []c;
    c = NULL;
    tamano = 0;
  }
}

// Sobrecarga del operador asignación
TVectorCom&
TVectorCom::operator= (const TVectorCom& vector)
{
  // TODO
  if (this != &vector)
  {
    // Se destruye inicial
    this->~TVectorCom();
    // Se inicializa con la dimensión que se necesita
    Inic(vector.Tamano());
    Copia(vector);
  }

  return (*this);
}

/********************
 * OTROS OPERADORES *
 ********************/

bool
TVectorCom::operator== (const TVectorCom& vector) const
{
  if (tamano == vector.Tamano())
  {
    for (int i = 1; i <= tamano; i++)
    {
      if (c[i] != vector.c[i])
      {
        return false;
      }
    }
    return true;
  }

  return false;
}

bool
TVectorCom::operator!= (const TVectorCom& vector) const
{
  return !((*this) == vector);
}

// Parte IZQUIERDA
// Devuelve la referencia del objeto TComplejo
TComplejo&
TVectorCom::operator[] (const int& pos)
{
  if (EstaDentro(pos))
  {
    return c[pos - 1];
  }
  else
  {
    return error;
  }
}

// Parte DERECHA
// Devuelve el valor del objeto TComplejo
TComplejo
TVectorCom::operator[] (const int& pos) const
{
  if (EstaDentro(pos))
  {
    return c[pos - 1];
  }
  else
  {
    return error;
  }
}

/*********************
 * GETTERS Y SETTERS *
 *********************/

int
TVectorCom::Tamano () const
{
  return tamano;
}

int
TVectorCom::Ocupadas () const
{
  int nOcupadas = 0;    // Número de posiciones ocupadas

  for (int i = 1; i <= tamano; i++)
  {
    if (!PosVacia(c[i]))
    {
      nOcupadas++;
    }
  }

  return nOcupadas;
}

/***********************
 * MÉTODOS Y FUNCIONES *
 ***********************/

bool
TVectorCom::ExisteCom (const TComplejo& com) const
{
  for (int i = 1; i <= tamano; i++)
  {
    if (com == c[i])
    {
      return true;
    }
  }

  return false;
}

void
TVectorCom::MostrarComplejos (const double& d) const
{
  bool primero = true;    // Variable auxiliar para saber si es el primer elemento

  cout << "[";
  for (int i = 1; i <= tamano; i++)
  {
    if (c[i].Re() >= d)
    {
      if (!primero)
      {   // Si es el primer complejo no tiene que escribir ", " delante
        cout << ", ";
      }
      cout << c[i];
      if (primero)
      {
        primero = false;
      }
    }
  }
  cout << "]";
}

bool
TVectorCom::Redimensionar (const int& nuevoTamano)
{
  if (nuevoTamano > 0)
  {
    // Vector auxiliar para guardar los valores
    TVectorCom aux((*this));
    // Libero memoria
    this->~TVectorCom();
    Inic(nuevoTamano);
    Copia(aux);
    // Se destruye aux
    aux.~TVectorCom();
    return true;
  }

  return false;
}

void
TVectorCom::Inic (const int& nuevoTamano)
{
  tamano = nuevoTamano;
  if (tamano == 0)
  {
    c = NULL;
  }
  else
  {
    c = new TComplejo[tamano];
  }
  
}

// Copia cada elemento, uno a uno
void
TVectorCom::Copia (const TVectorCom& vector)
{
  for (int i = 1; i <= tamano && i <= vector.Tamano(); i++)
  {
    c[i] = vector[i];
  }
}

// Indica si la posición está dentro del vector
bool
TVectorCom::EstaDentro (const int& pos) const
{
  if (pos >= 1 && pos <= tamano)
  {
    return true;
  }
  
  return false;
}

// Indica si la posición del array está vacía
bool
TVectorCom::PosVacia (const TComplejo& com) const
{
  if (com.Re() == 0 && com.Im() == 0)
  {
    return true;
  }

  return false;
}