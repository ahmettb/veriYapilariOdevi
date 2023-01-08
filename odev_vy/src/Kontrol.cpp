
/** 
* @file Kontrol.cpp
* @description Post order olarak sıralanmak üzere,mutasyona uğrayan ağaç kökleri buraya geliyor.Ve her bir düğüm taranıp burdaki veriler postorder
olarak bu sınıfa ait post order dizisine aktarılıyor.Ağacın mutasyona uğrayıp uğramaması burada kontrol ediliyor.
Avl ağacı mantığına göre ağacın dengeli olup olmadığı,yükseklik fonksiyonu yardımıyla belirleniyor
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/



#include "Kontrol.hpp"
#include  "Organ.hpp"
#include "Doku.hpp"
#include "Dugum.hpp"
#include "algorithm"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <iostream>
using namespace std;

Kontrol::Kontrol()
{
  sayac=0;
  postOrder=new int[20];
}

  void Kontrol::pstOrder(Dugum*kok)
  {
        if(kok)
    {
   if((kok->veri)%2==0)kok->veri=(kok->veri)/2;
    pstOrder(kok->solCocuk);
    pstOrder(kok->sagCocuk);
    postOrder[sayac]=kok->veri;
    sayac++;
    }

  }


  bool Kontrol:: mutasyonOlacakMi(Dugum*kokAdres)
  {

        if((kokAdres->veri)%50==0)
    {

      pstOrder(kokAdres);
                                
      return true;
    }
    return false;


  }  



int Kontrol::yukseklik(Dugum*basDoku)
{
        if (basDoku == NULL)
        {
            
            return 0;
        }
            
        int solAltYukseklik = yukseklik (basDoku->solCocuk);
        if (solAltYukseklik == -1)  return -1;                           

        int sagAltYukseklik = yukseklik (basDoku->sagCocuk);
    
        if (sagAltYukseklik == -1)  return -1;
           
        if (abs(solAltYukseklik - sagAltYukseklik) > 1)
        {
        
            return -1;
        }
        return  (max(solAltYukseklik, sagAltYukseklik) + 1);
}


bool Kontrol::dengeliMi(Dugum *basi)
{

    agacYukseklik= yukseklik(basi);

     if(agacYukseklik ==-1)
     {
        return false;
     }
     return true;
        
}