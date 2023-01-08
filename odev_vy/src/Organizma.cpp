/** 
* @file Organizma.cpp
* @description organizmaya her bir sistem dizi yardımıyla ekleniyor.
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/



#include "Organizma.hpp"
#include "Sistem.hpp"
#include "Dugum.hpp"

Organizma::Organizma()
{
    sistemler=new Sistem*[27];
    sayac=0;
}
Organizma::~Organizma()

{

for(int i=0;i<27;i++)
{
    delete sistemler[i];
}
delete []sistemler;

}





void Organizma::orgnzmaSistemEkle(Sistem*sistem,int index)
{
sistemler[index]=sistem;
}


void Organizma::sistemEkle(Sistem*sistem)
{
    orgnzmaSistemEkle(sistem,sayac);
    sayac++;

}
