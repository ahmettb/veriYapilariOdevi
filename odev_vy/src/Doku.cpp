/** 
* @file Doku.cpp
* @description Doku sınıfı,almış olduğu dizi parametresi ve uzunluğuyla birlikte radix ile sıralanıp DokuDizisi dizisine eşitleniyor.
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/


#include "Doku.hpp"
#include "Hucre.hpp"
#include "Radix.hpp"
#include "Queue.hpp"
#include "Radix.hpp"
#include <iostream>
using namespace std;

void Doku::dokuDiziOlustur(int dizi[], int uzunluk)
{
    this->uzunluk=uzunluk;
   Radix *radix=new Radix(dizi,uzunluk);
    DokuDizi=radix->Sort();
   delete radix;

}


int Doku::ortaDegerGetir()
{

return DokuDizi[uzunluk/2];

}






