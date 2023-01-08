#ifndef Organizma_hpp
#define Organizma_hpp

#include "Sistem.hpp"
#include "Doku.hpp"
#include "Organ.hpp"
#include "Organizma.hpp"


class Organizma
{
public:
Sistem**sistemler;
Organizma();
~Organizma();
void sistemEkle(Sistem*sistem);
private:
int sayac;
void orgnzmaSistemEkle(Sistem*sistem,int index);
};
#endif





