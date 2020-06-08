/* Prueba:
    - CONSTR. COPIA , "=" ; posible copia de punteros 
*/

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
using namespace std;

int
main(void)
{
  /*
    BORRADO DE ÁRBOL NORMAL (No hoja)
  */
  // TABBCom a;
  // cout << "ARBOL:" << a << endl;
  // TComplejo c3(3), c4(4), c5(5), c6(6), c7(7), c8(8), c10(10), c12(12), c20(20), c69(69), c96(96);

  // a.Insertar(c8);
  // a.Insertar(c3);
  // a.Insertar(c5);
  // a.Insertar(c4);
  // a.Insertar(c6);
  // a.Insertar(c7);
  // a.Insertar(c69);
  // a.Insertar(c12);
  // a.Insertar(c10);
  // a.Insertar(c20);
  // a.Insertar(c96);

  // TVectorCom preorden(11);
  // preorden[1] = c8;
  // preorden[2] = c3;
  // preorden[3] = c5;
  // preorden[4] = c4;
  // preorden[5] = c6;
  // preorden[6] = c7;
  // preorden[7] = c69;
  // preorden[8] = c12;
  // preorden[9] = c10;
  // preorden[10] = c20;
  // preorden[11] = c96;

  // cout << "Preorden manual: " << preorden << endl;
  // cout << "Función preorden: " << a.Preorden() << endl;
  // cout << "Inorden: " << a.Inorden() << endl;

  // cout << "BORRADO HOJA\n";
  // if (a.Borrar(c7))
  // {
  //   cout << "Borrado" << endl;
  //   cout << a.Preorden() << endl;
  // }

  // a.Insertar(c7);

  // cout << "BORRADO 1 HIJO\n";
  // a.Borrar(c3);
  // cout << a.Preorden() << endl;

  // a.Insertar(c3);

  // cout << "BORRADO 2 HIJOS\n";
  // a.Borrar(c69);
  // cout << a.Preorden() << endl;

  // a.Insertar(c69);

  // a.Insertar(c1);
  // cout << "Raiz: " << a.Raiz() << endl;
  // cout << c1 << endl;
  // cout << "ARBOL:" << a << endl;
  
  // TABBCom b(a), c;
  // b.Insertar(c2);
  // c=b;

  // a.Insertar(c2);
  // if( a.Inorden() == b.Inorden() )
  //       cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
  // else
	// cout << "CORRECTO CONSTRUCTOR DE COPIA" << endl;


  // b.Insertar(c2);
  // if( b.Inorden() == c.Inorden() )
  //       cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
  // else
	// cout << "CORRECTA ASIGNACION" << endl;

  /*
    COPIA DE ÁRBOL VACÍO
  */
  // TABBCom arbol;
  // TABBCom arbolVacio;

  // cout << "Inorden vacío : " << arbol.Inorden() << endl;
  // arbol = arbolVacio;
  // cout << "Inorden vacío : " << arbol.Inorden() << endl;

  // /*
  //   BORRAR ÁRBOL HOJA
  // */
  // arbol.Insertar(c3);
  // cout << arbol << endl;
  // arbol.Borrar(c3);
  // cout << "Borrado : " << arbol << endl;

  // /*
  //   BUSCAR ELEMENTO
  // */
  // cout << "## BUSCAR ##" << endl;
  // cout << "1) En árbol vacío" << endl;
  // if (!arbolVacio.Buscar(c3))
  // {
  //   cout << "No encontrado (Bien)" << endl;
  // }
  // else
  // {
  //   cout << "(Error)" << endl;
  // }

  // arbol.Insertar(c4);
  // cout << "2) En árbol hoja ->" << arbol << endl;
  // if (arbol.Buscar(c4))
  // {
  //   cout << c4 << " encontrado (Bien)" << endl;
  // }
  // else
  // {
  //   cout << "Error\n";
  // }

  // if (arbol.Buscar(c3))
  // {
  //   cout << "(Error)\n";
  // }
  // else
  // {
  //   cout << c3 << " no encontrado (Bien)\n";
  // }

  // arbol.Insertar(c20);
  // cout << "3) En árbol con hijo derecho -> " << arbol << endl;
  // if (arbol.Buscar(c4))
  // {
  //   cout << c4 << " encontrado (Bien)" << endl;
  // }
  // else
  // {
  //   cout << "Error\n";
  // }
  
  // if (arbol.Buscar(c20))
  // {
  //   cout << c20 << " encontrado (Bien)" << endl;
  // }
  // else
  // {
  //   cout << "Error\n";
  // }

  // if (arbol.Buscar(c3))
  // {
  //   cout << "(Error)\n";
  // }
  // else
  // {
  //   cout << c3 << " no encontrado (Bien)\n";
  // }

  // cout << "OK" << endl;
  // cout << "A->" << a << endl;
  // cout << "B->" << b << endl;
  // cout << "C->" << c << endl;

  TComplejo a(-3, 2), b(3, -2), c(-3, -2), d(3, 2), e(1, -2), f(7, 4);

  cout << "Módulo de a = " << a.Mod() << endl;
  cout << "Módulo de b = " << b.Mod() << endl;
  cout << "Módulo de c = " << c.Mod() << endl;
  cout << "Módulo de d = " << d.Mod() << endl;
  cout << "Módulo de e = " << e.Mod() << endl;
  cout << "Módulo de f = " << f.Mod() << endl;

  return 1;
}