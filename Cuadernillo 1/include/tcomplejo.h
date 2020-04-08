#ifndef _TCOMPLEJO_
#define _TCOMPLEJO_

#include <iostream>
#include <math.h>

using namespace std;

class TComplejo {
  // Sobrecarga del operador SALIDA
  friend ostream& operator<< (ostream&, const TComplejo&);

  friend TComplejo operator+ (const double&, const TComplejo&);
  friend TComplejo operator- (const double&, const TComplejo&);
  friend TComplejo operator* (const double&, const TComplejo&);

  private:
    double re;  // PARTE REAL
    double im;  // PARTE IMAGINARIA

    void Copia(const TComplejo&);
    void corregirCero();  // Comprueba si hay un -0.0 y lo corrige

  public:
  /* FORMA CANÓNINCA */
    /*
    // Constructor por defecto : PARTE REAL e IMAGINARIA inicializadas a 0
    TComplejo ();
    // Constructor a partir de la PARTE REAL
    TComplejo (double);
    // Constructor a partir de la PARTE REAL e IMAGINARIA
    TComplejo (double, double);
    */
    // Se pueden agrupar en un constructor:
    TComplejo (const double& = 0, const double& = 0);
    // Constructor copia
    TComplejo (const TComplejo&);
    // Destructor : PARTE REAL e IMAGINARIA asignadas a 0
    ~TComplejo ();
    // Sobrecarga del operador asignación
    TComplejo& operator= (const TComplejo&);
  /* MÉTODOS */
    // SOBRECARGA DE OPERADORES ARITMÉTICOS
    TComplejo operator+ (const TComplejo&) const;
    TComplejo operator- (const TComplejo&) const;
    TComplejo operator* (const TComplejo&) const;
    TComplejo operator+ (const double&) const;
    TComplejo operator- (const double&) const;
    TComplejo operator* (const double&) const;
    // OTROS OPERADORES
    bool operator== (const TComplejo&) const; // IGUALDAD de números complejos
    bool operator!= (const TComplejo&) const;  // DESIGUALDAD de números complejos

    double Re () const;  // Devuelve PARTE REAL
    double Im () const;  // Devuelve PARTE IMAGINARIA
    
    void Re (const double&); // Modifica PARTE REAL
    void Im (const double&); // Modifica PARTE IMAGINARIA

    double Arg () const;  // Calcula el Argumento (en Radianes)
    double Mod () const;  // Calcula el Módulo
};

#endif