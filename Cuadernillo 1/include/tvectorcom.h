#ifndef _TVECTORCOM_
#define _TVECTORCOM_

#include "tcomplejo.h";

class TVectorCom
{
  // Sobrecarga del operador salida
  friend ostream& operator<< (ostream&, const TVectorCom&);

  private:
  TComplejo *c;
  int tamano;
  TComplejo error;      // No hace falta inicializar

  void Inic(const int& = 0);
  void Copia (const TVectorCom&);
  bool EstaDentro (const int&) const;
  bool PosVacia (const TComplejo&) const;

  public:
  // Constructor por defecto
  TVectorCom ();
  // Constructor a partir de un tamaño
  TVectorCom (const int&);
  // Constructor de copia
  TVectorCom (const TVectorCom&);
  // Destructor
  ~TVectorCom ();
  // Sobrecarga del operador asignación
  TVectorCom& operator= (const TVectorCom&);

  // Sobrecarga operador igualdad
  bool operator== (const TVectorCom&) const;
  // Sobrecarga del operador desigualdad
  bool operator!= (const TVectorCom&) const;
  // Sobrecarga del operador corchete (parte IZQUIERDA)
  TComplejo& operator[] (const int&);
  // Sobrecarga del operador corchete (parte DERECHA)
  TComplejo operator[] (const int&) const;
  // Tamaño del vector (posiciones TOTALES)
  int Tamano () const;
  // Cantidad de posiciones OCUPADAS (TComplejo NO VACÍO) en el vector
  int Ocupadas () const;
  // Devuelve TRUE si existe el TComplejo en el vector
  bool ExisteCom (const TComplejo&) const;
  // Mostrar los elementos TComplejo del vector con PARTE REAL IGUAL O POSTERIOR al argumento
  void MostrarComplejos (const double&) const;
  // REDIMENSIONAR el vector de TComplejo
  bool Redimensionar (const int&);
};

#endif