#ifndef Yigin_hpp
#define Yigin_hpp
#include "DYigin.hpp"
#include <exception>
#include <iostream>
#include <iomanip>
using namespace std;

class Yigin
{
public:
    Yigin();
    void ekle(int veri);

    void cikar();
    void sil(int veri);
    void toplam();
    friend ostream& operator<<(ostream& os,Yigin& yigin);
    int getir();
private:
    DYigin* tepe;
};

#endif