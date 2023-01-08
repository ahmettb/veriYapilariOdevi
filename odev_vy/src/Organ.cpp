/** 
* @file Organ.cpp
* @description Oluşan her ikili arama ağacı nesnesinin kök adresi organ nesnesine dokulariGetir fonksiyonuyla aktarılıyor.
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/



#include "Organ.hpp"
#include "Doku.hpp"
#include "Dugum.hpp"
#include "IkiliAramaAgaci.hpp"

#include"Hucre.hpp"
Organ::Organ()
{
    kokAdres=0;
}

void Organ::dokulariGetir(IkiliAramaAgaci*agac)
{
    kokAdres=agac->kok;
}
