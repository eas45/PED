#ifndef _TAVLCOM_
#define _TAVLCOM_

#include "tvectorcom.h"
#include <queue>

class TNodoAVL;
class TAVLCom;

class TAVLCom
{
  friend class TNodoAVL;
  friend ostream& operator<< (ostream&, const TAVLCom&);

  private:
    // Puntero al nodo
    TNodoAVL *nodo;
    // Item_error
    TComplejo error;
    // AUXILIAR : Devuelve el recorrido en inorden
    void InordenAux (TVectorCom&, int&) const;
    // AUXILIAR : Devuelve el recorrido en preorden
    void PreordenAux (TVectorCom&, int&) const;
    // AUXILIAR : Devuelve el recorrido en postorden
    void PostordenAux (TVectorCom&, int&) const;
    // MÉTODOS
    void Inic ();
    void Copia (const TAVLCom&);
    void BorrarHoja (const TComplejo&);
    TComplejo Mayor ();
    void BorrarAux (TAVLCom*, const TComplejo&, bool&);
    bool InsertarAux (const TComplejo&, bool&);
    void EquilibrarIzquierda ();
    void EquilibrarDerecha ();

  public:
    // FORMA CANÓNICA
    TAVLCom ();
    TAVLCom (const TAVLCom&);
    ~TAVLCom ();
    TAVLCom& operator= (const TAVLCom&);
    // MÉTODOS
    bool operator== (const TAVLCom&) const;
    bool operator!= (const TAVLCom&) const;
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

class TNodoAVL
{
  friend class TAVLCom;

  private:
    // El elemento del nodo
    TComplejo item;
    // Subárbol izquierdo y derecho
    TAVLCom iz, de;
    // Factor de equilibrio
    int fe;
    void Copia (const TNodoAVL&);
    bool EsHoja () const;
    int FactorEquilibrio () const;

  public:
    // FORMA CANÓNICA
    TNodoAVL (const int&);
    TNodoAVL (const TComplejo&, const int&);
    TNodoAVL (const TNodoAVL&);
    ~TNodoAVL ();
    TNodoAVL& operator= (const TNodoAVL&);
};

#endif