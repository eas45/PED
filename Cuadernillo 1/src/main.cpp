#include "tcomplejo.h"
#include "tlistacom.h"

int
main(void)
{
  TListaCom tl1;
  TComplejo c1;
  TComplejo c2(1, 2);

  tl1.InsCabeza(c2);
  tl1.InsCabeza(c1);
  tl1.InsCabeza(c2);
  tl1.InsCabeza(c1);
  tl1.InsCabeza(c2);
  tl1.InsCabeza(c1);
  cout << tl1 << endl;

  TListaCom tl2(tl1);
  cout << tl2 << endl;

  TListaCom tl3;
  tl3 = tl2;
  cout << tl3 << endl;

  return 0;
}