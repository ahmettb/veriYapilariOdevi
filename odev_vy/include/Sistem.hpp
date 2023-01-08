#ifndef Sistem_hpp
#define Sistem_hpp

#include "Dugum.hpp"
#include "Doku.hpp"
#include "Organ.hpp"

class Sistem
{
    public:
Sistem();
~Sistem();
Organ**organlar;
void sistemeOrganEkle(Organ*organ);
    private:
int sayac;
 void sistemOlustur(Organ*organ,int index);


};

#endif




