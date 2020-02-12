#include "tvectorcom.h"

/******************
 * FORMA CANÓNICA *
 ******************/

// Constructor por defecto
TVectorCom::TVectorCom ()
{
  c = NULL;
  tamano = 0;
}

// Constructor a partir de un tamaño
TVectorCom::TVectorCom (const int& tam)
{
  if (tam > 0)
  {
    c = new TComplejo[tam];
    tamano = tam;
  }
  else
  {
    c = NULL;
    tamano = 0;
  }
}

// Constructor de copia
TVectorCom::TVectorCom (const TVectorCom& vector)
{
  // Se crea el vector del mismo tamaño
  c = new TComplejo[vector.Tamano()];
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
  // A un vector NO vacío
  // Se destruye inicial
  // Puede que se modifique el tamaño
}

/**************************
 * OPERADORES ARITMÉTICOS *
 **************************/



/********************
 * OTROS OPERADORES *
 ********************/

bool
TVectorCom::operator== (const TVectorCom& vector) const
{
  // TODO
}

TComplejo&
TVectorCom::operator[] (const int& pos)
{
  if (EstaDentro(pos))
  { // Está dentro del rango del vector
    return c[pos - 1];
  }
  else
  {
    return error;
  }
}

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
  // TODO
  for (int i = 0; i < tamano; i++)
  {
  }
}

/***********************
 * MÉTODOS Y FUNCIONES *
 ***********************/

void
TVectorCom::Copia (const TVectorCom& vector)
{

}

bool
TVectorCom::EstaDentro (const int& pos) const
{
  if (pos >= 1 && pos <= tamano)
  {
    return true;
  }
  
  return false;
}