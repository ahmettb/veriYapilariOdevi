#ifndef Kontrol_hpp
#define Kontrol_hpp

#include "Dugum.hpp"
#include "Organ.hpp"

class Kontrol
{
public:
int *postOrder;
Kontrol();
int sayac;
int yukseklik(Dugum *basDoku);
bool dengeliMi(Dugum*basi);
int agacYukseklik;
Dugum*mutasyonlu[21];
void  pstOrder(Dugum*kok);
bool mutasyonOlacakMi(Dugum*kokAdres);
};


#endif