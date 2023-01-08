/** 
* @file Sistem.cpp
* @description  Sistem sınıfına ait organlar işaretci dizisine organları nesne olarak direk olarak aktarıldı. 
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/

#include "Sistem.hpp"
#include "Dugum.hpp"
#include "Doku.hpp"
#include "Organ.hpp"  
#include <iostream>
using namespace std;
Sistem::Sistem()
{
         organlar=new Organ*[100];
         sayac=0;
}
Sistem::~Sistem()
{
    for(int i=0;i<100;i++)
    {
        delete organlar[i];
        cout<<"sislindi"<<endl;
    }
    delete []organlar;

}


void Sistem::sistemOlustur(Organ*organ,int index)
{    

    organlar[index]=organ;


}
    
  
void Sistem ::sistemeOrganEkle(Organ*organ)
{

    sistemOlustur(organ,sayac);
    sayac++;

}


