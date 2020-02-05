#ifndef _TVECTORCOM_
#define _TVECTORCOM_

#include "tcomplejo.h";

class TVectorCom {
  // Sobrecarga del operador salida
  friend ostream& operator<< (ostream&, const TVectorCom&);

  private:
  TComplejo *c;
  int tamaño;
};

#endif