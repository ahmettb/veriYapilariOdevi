/** 
* @file TestProgrami.cpp
* @description  Organizma ve mutasyonun ekrana yazdırılma işlemleri,doku organ ve sisten sayılarına bağlı olarak dokuları organa,organı sistemlere ve
sistemleri organizmaya aktarıp gerekli koşulların sağlanmasıyla birlikte ekrana yazdırma işlemleri gerçekleşti 
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/


#include "Radix.hpp"
#include "Queue.hpp"
#include "Hucre.hpp"
#include "Organ.hpp"
#include "Sistem.hpp"
#include "Organizma.hpp"
#include "IkiliAramaAgaci.hpp"
#include "Dugum.hpp"
#include "Doku.hpp"
#include "Kontrol.hpp"
#include <iostream>
#include <sstream>
#include<fstream>
#include <string>
#include <windows.h>

using namespace std;


int main()
{      
        system("cls");
        cout<<"     ORGANIZMA   "<<endl;
        Kontrol *kontrol=new Kontrol();
        Organizma *organizma=new Organizma();
        Organ*organ=new Organ();
        Sistem*sistem=new Sistem();
        int agacSayisi=1;
        int dokuSayi=0;           
        int organSayisi=0;
        int sistemSayisi=0;
        IkiliAramaAgaci *agac=new IkiliAramaAgaci(); 
        int sayac2=1;
        int dokuUzunluk=0;

        ifstream dosya;
        dosya.open("gulenyuz.txt");       
        string satirVeri;

    while(getline(dosya,satirVeri))
    {          
         int dosyadanOkunanSayi=0;
        int dosyadanOkunanSayiYedek=0;
 
        stringstream veri(satirVeri);
        stringstream veri2(satirVeri);
        while(veri2>>dosyadanOkunanSayiYedek)dokuUzunluk++;
        int sayac=0;               
        int *gecici=new int[dokuUzunluk];
        int index=0;
        Doku *doku=new Doku();
      
        while(veri>>dosyadanOkunanSayi)
        {
        Hucre *hucre=new Hucre(dosyadanOkunanSayi);
        gecici[index]=dosyadanOkunanSayi;
        sayac++;
        index++;
        }     
            doku->dokuDiziOlustur(gecici,sayac);
            agac->elemanEkle(doku);
            
        if(sayac2%20==0&&sayac2!=0)
        {
            organ->dokulariGetir(agac);
            sistem->sistemeOrganEkle(organ);
            organ=new Organ();
            agac=new IkiliAramaAgaci();
            organSayisi++;
            agacSayisi++;                   
        }
    
        if(organSayisi%100==0&&organSayisi!=0)
        {
            organizma->sistemEkle(sistem);
               for(int k=0;k<100;k++)
                {
                     if(kontrol->dengeliMi(organizma->sistemler[sistemSayisi]->organlar[k]->kokAdres))cout<<" ";
                    else  cout<<"#";        
                }    
            cout<<endl;                    
            sistemSayisi++;
            organSayisi=0;
            sistem=new Sistem();   
            agacSayisi=1;
            }            
        delete []gecici;
        delete doku;
        sayac2++;
        dokuSayi++;

            }
char secim;
cin>>secim;
if(cin.get()=='\n')
{
    system("cls");
    cout<<"    ORGANIZMA(MUTASYONA UGRADI) " <<endl;
    for(int i=0;i<27;i++)
    {
              for(int k=0;k<100;k++)
                {                               
              if(kontrol->mutasyonOlacakMi(organizma->sistemler[i]->organlar[k]->kokAdres))
                {
                     agac->mutasyonOlustur(kontrol->postOrder);
                     organizma->sistemler[i]->organlar[k]->kokAdres = agac->mutasyonlu;       
                }
                    kontrol=new Kontrol();
                     if(kontrol->dengeliMi(organizma->sistemler[i]->organlar[k]->kokAdres)) cout<<" ";
                     else  cout<<"#";
                }
                cout<<endl;
     }

}


}
                    
                            

    
            





    
        
          
        
 
            








    
      
          
    


        

   











/*ifstream dosya;
dosya.open("veriler.txt");
string satirVeri;
int sayac=0;
while(getline(dosya,satirVeri))
{   
    int sayi=0;
    stringstream veri(satirVeri);
    //Radix *radix = new Radix(veri,10);
    while(veri>>sayi)
    {
        
        
    }

    
}*/


	





