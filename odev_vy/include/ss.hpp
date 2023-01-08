#ifndef Queue_hpp
#define Queue_hpp


class Queue
{

private:
int ilk;
int son;
int *basEleman;
int uzunluk;
int kapasite;
int *dizi;

public:
void genislet(int miktar);  

 Queue();
void elemanEkle(int veri);
int elemanGetir();
void elemanSil();
int count();
bool bosMu(); 
 


};




#endif