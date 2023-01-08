
/** 
* @file Dugum.cpp
* @description Dugum yapıcı fonkisyonu aldığı int türünden veriyi sahip olduğu veri değişkenine aktarıyor.İlk defa oluştuğu zaman sağ ve solCocuklar 0 oluyor. 
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/

#include "Dugum.hpp"
#include "Sistem.hpp"

Dugum::Dugum(int veri)
{
this->veri=veri;
solCocuk=0;
sagCocuk=0;
}

