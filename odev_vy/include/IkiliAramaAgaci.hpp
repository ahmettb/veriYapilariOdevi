#ifndef IkiliAramaAgaci_hpp
#define IkiliAramaAgaci_hpp

#include "Doku.hpp"
#include "Dugum.hpp"

class IkiliAramaAgaci
{
public:
Dugum*kok;
void ekle(Doku *doku,Dugum *kokAdres);
void yenidenOlustur(int veri,Dugum*kokA);
IkiliAramaAgaci();
void elemanEkle(Doku *doku);
void postOrder(Dugum*kok);
int Height();
int Height1(Dugum*kok);
Dugum* mutasyonOlustur(int dizi[20]);
Dugum*mutasyonlu;
};



#endif