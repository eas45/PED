#ifndef _TABBCOM_
#define _TABBCOM_

#include "tvectorcom.h"

class TNodoABB
{
  friend class TABBCom;

  private:
    // El elemento del nodo
    TComplejo item;
    // Subárbol izquierdo y derecho
    TABBCom iz, de;
    // MÉTODOS
    void Inic ();
    void Copia (const TNodoABB&);
    bool EsHoja () const;

  public:
    // FORMA CANÓNICA
    TNodoABB ();
    TNodoABB (const TNodoABB&);
    ~TNodoABB ();
    TNodoABB& operator= (const TNodoABB&);
};

class TABBCom
{
  friend class TNodoABB;
  friend ostream& operator<< (ostream&, const TABBCom&);

  private:
    // Puntero al nodo
    TNodoABB *nodo;
    // Item_error
    TComplejo error;
    // AUXILIAR : Devuelve el recorrido en inorden
    void InordenAux (TVectorCom&, int&);
    // AUXILIAR : Devuelve el recorrido en preorden
    void PreordenAux (TVectorCom&, int&);
    // AUXILIAR : Devuelve el recorrido en postorden
    void PostordenAux (TVectorCom&, int&);
    // MÉTODOS
    void Inic ();
    void Copia (const TABBCom&);

  public:
    // FORMA CANÓNICA
    TABBCom ();
    TABBCom (const TABBCom&);
    ~TABBCom ();
    TABBCom& operator= (const TABBCom&);
    // MÉTODOS
    bool operator== (const TABBCom&) const;
    bool EsVacio () const;
    bool Insertar (const TComplejo&);
    bool Borrar (const TComplejo&);
    bool Buscar (const TComplejo&) const;
    TComplejo Raiz () const;
    int Altura () const;
    int Nodos () const;
    int NodosHoja () const;
    // RECORRIDOS
    TVectorCom Inorden () const;
    TVectorCom Preorden () const;
    TVectorCom Postorden () const;
    TVectorCom Niveles () const;
};

#endif