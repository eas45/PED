#include "tcomplejo.h"

/******************
 * FORMA CANÓNICA *
 ******************/

// Constructor
TComplejo::TComplejo (const double& re, const double& im)
{
  this->re = re;
  this->im = im;
  corregirCero();
}

// Constructor de copia
TComplejo::TComplejo (const TComplejo& com)
{
  Copia(com);
}

// Destructor
TComplejo::~TComplejo ()
{
  re = im = 0;
}

// Operador asignación
TComplejo&
TComplejo::operator= (const TComplejo& com)
{
  // Se comprueba que no sea el mismo objeto
  if (this != &com) {
    // Primero se liberan los recursos
    this->~TComplejo();
    // Se asignan los nuevos valores
    Copia(com);
  }

  return (*this);
}

// Lleva a cabo la copia de los valores de un objeto a otro
void
TComplejo::Copia (const TComplejo& com)
{
  re = com.Re();
  im = com.Im();
}

// OPERADORES ARITMÉTICOS
// Suma
TComplejo
TComplejo::operator+ (const TComplejo& com) const
{
  TComplejo res(re + com.Re(), im + com.Im());

  res.corregirCero();

  return res;
}

TComplejo
TComplejo::operator+ (const double& d) const
{
  TComplejo com(d);

  return (*this) + com;
}

TComplejo
operator+ (const double& d, const TComplejo& com)
{
  TComplejo res = com + d;

  return res;
}

// Resta
TComplejo
TComplejo::operator- (const TComplejo& com) const
{
  TComplejo res(re - com.Re(), im - com.Im());

  res.corregirCero();

  return res;
}

TComplejo
TComplejo::operator- (const double& d) const
{
  TComplejo com(d);

  return (*this) - com;
}

TComplejo
operator- (const double& d, const TComplejo& com)
{
  // TComplejo res = com - d;
  TComplejo aux(d);
  TComplejo res = aux - com;

  return res;
}

// Multiplicación
TComplejo
TComplejo::operator* (const TComplejo& com) const
{
  TComplejo res (re * com.Re() - im * com.Im(), re * com.Im() + im * com.Re());

  res.corregirCero();

  return res;
}

TComplejo
TComplejo::operator* (const double& d) const
{
  TComplejo com (d);

  return (*this) * com;
}

TComplejo
operator* (const double& d, const TComplejo& com)
{
  TComplejo res = com * d;

  return res;
}

// OTROS OPERADORES
bool
TComplejo::operator== (const TComplejo& com) const
{
  if ((re == com.Re()) && (im == com.Im())) {
    return true;
  }

  return false;
}

bool
TComplejo::operator!= (const TComplejo& com) const
{
  return !((*this) == com);
}

// GETTERS Y SETTERS
double
TComplejo::Re () const
{
  return re;
}

double
TComplejo::Im () const
{
  return im;
}

void
TComplejo::Re (const double& d)
{
  re = d;
}

void
TComplejo::Im (const double& d)
{
  im = d;
}

// MÉTODOS Y FUNCIONES

void
TComplejo::corregirCero ()
{
  // Comprueba la PARTE REAL
  if (re == 0 && signbit(re)) {
    re = 0.0;
  }
  // Comprueba la PARTE IMAGINARIA
  if (im == 0 && signbit(im)) {
    im = 0.0;
  }
}

// Ángulo que forma en el eje OX (Eje Real)
double TComplejo::Arg () const {
  double argumento = atan2(im, re);

  return argumento;
}

// Valor absoluto
double
TComplejo::Mod () const
{
  double modulo = sqrt(pow(re, 2) + pow(im, 2));

  return modulo;
}

// Operador salida
ostream&
operator<< (ostream& s, const TComplejo& com)
{
  s << "(" << com.re << " " << com.im << ")";

  return s;
}