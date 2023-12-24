/**
* @file YListe.hpp
* @description AVL agaclari uzerinde islemler yapan program daha detayli bilgi raporda mevcut.
* @course 1. Ogretim A
* @assignment 2. Odev
* @date 19/12/2023
* @author Burak Kozluca burak.kozluca@ogr.sakarya.edu.tr
*/
#ifndef YListe_hpp
#define YListe_hpp
#include <exception>
#include <iostream>
#include <iomanip>
#include "YDugum.hpp"

class YListe
{
public:
    YListe();
    ~YListe();
    void ekle(Yigin yigin);
    void cikar();
    int uzunluk();
    void cikar(int sira);
    void onuneEkle(int sira,Yigin yigin);
    Yigin ilkGetir();
    friend ostream& operator<<(ostream& os,YListe& liste);
    YDugum* dugumGetir(int sira);
    YListe& operator=(const YListe& other);
    void tumElemanlariSil();
private:
    YDugum* ilk;
};
#endif