/**
* @file LDugum.hpp
* @description AVL agaclari uzerinde islemler yapan program daha detayli bilgi raporda mevcut.
* @course 1. Ogretim A
* @assignment 2. Odev
* @date 19/12/2023
* @author Burak Kozluca burak.kozluca@ogr.sakarya.edu.tr
*/
#ifndef YDugum_hpp
#define YDugum_hpp

#include "Yigin.hpp"

using namespace std;

class YDugum
{
public:
    YDugum(Yigin yigin);
    Yigin yigin;
    YDugum* sonraki;
    YDugum* onceki;
};

#endif