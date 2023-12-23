#ifndef Liste_hpp
#define Liste_hpp
#include<exception>
#include<iostream>
#include<iomanip>
#include "LDugum.hpp"

class Liste
{
public:
    Liste();
    ~Liste();
    void ekle(AVLAgaci agac);
    void cikar();
    int uzunluk();
    void cikar(int sira);
    void onuneEkle(int sira,AVLAgaci agac);
    AVLAgaci ilkGetir();
    friend ostream& operator<<(ostream& os,Liste& liste);
    LDugum* dugumGetir(int sira);
private:
    LDugum* ilk;
};
#endif