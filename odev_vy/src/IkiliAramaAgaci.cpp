/** 
* @file IkiliAramaAgaci.cpp
* @description Ikiliaramağacında doku nesneleri ekle fonksiyonuyla,orta verileri ekleniyor ve ağaç oluşuyor.
  Mutasyona uğrayan ağaçlarda burada uğrayıp,ağaçtaki veriler postorder dizisine aktarılıyor.Bunu için farklı bir ikili arama ağacı ekleme
  fonksiyonu bulunmakta(yenidenOlustur(int veri,Dugum*kok))
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/



#include "IkiliAramaAgaci.hpp"
#include "Dugum.hpp"
#include "Doku.hpp"
#include <iostream>
#include <windows.h>
 #include "Organ.hpp"
using namespace std;
IkiliAramaAgaci:: IkiliAramaAgaci()
{
    kok=0;
    
}
void IkiliAramaAgaci::yenidenOlustur(int veri,Dugum*kokA)
{          Dugum*geciciKok=kokA;
           
        if(mutasyonlu==0)mutasyonlu=new Dugum(veri);
        else if(geciciKok->veri<veri)
        {
            if(geciciKok->sagCocuk) yenidenOlustur(veri,geciciKok->sagCocuk);
            else geciciKok->sagCocuk=new Dugum(veri);
        }            
         else if(geciciKok->veri>veri)
        {
            if(geciciKok->solCocuk) yenidenOlustur(veri,geciciKok->solCocuk);
            else geciciKok->solCocuk=new Dugum(veri);
        }  
        
}


Dugum *IkiliAramaAgaci::mutasyonOlustur(int *dizi)
  {
    mutasyonlu=0;
  
    for(int i=0;i<20;i++)
    {
    yenidenOlustur(dizi[i],mutasyonlu);
    }
    return kok;
  }

void IkiliAramaAgaci::ekle(Doku*doku,Dugum*kokAdres)
{

        doku->ortaDeger=doku->ortaDegerGetir();
        Dugum*geciciKok=kokAdres;

        if(kok==0){
            kok=new Dugum(doku->ortaDeger);   
         
           }

         else if(geciciKok->veri<doku->ortaDeger)
        {
            if(geciciKok->sagCocuk) ekle(doku,geciciKok->sagCocuk);
            else geciciKok->sagCocuk=new Dugum(doku->ortaDeger);
        }            
         else if(geciciKok->veri>doku->ortaDeger)
        {
            if(geciciKok->solCocuk) ekle(doku,geciciKok->solCocuk);
            else geciciKok->solCocuk=new Dugum(doku->ortaDeger);
        }     
        
}
  void::IkiliAramaAgaci::postOrder(Dugum*kok)
  {
    if(kok)
    {
    postOrder(kok->solCocuk);
    postOrder(kok->sagCocuk);
    cout<<kok->veri<<endl;
    }

  }   



 


int IkiliAramaAgaci::Height()
{
    return Height1(kok);
}


int IkiliAramaAgaci::Height1(Dugum*kok)
{
    if(kok==NULL)return -1;
    return 1+max(Height1(kok->solCocuk),Height1(kok->sagCocuk));
}



void IkiliAramaAgaci::elemanEkle(Doku*doku)
{
           return ekle(doku,kok);


}