#include "Yigin.hpp"
#include <exception>
#include <iostream>
#include <iomanip>
using namespace std;

Yigin::Yigin()
{
    tepe=0;
}

void Yigin::ekle(int veri)
{
    DYigin* yeni = new DYigin(veri);
    if(tepe!=0)
        yeni->sonraki=tepe;
    tepe= yeni;
}
void Yigin::cikar()
{
    if(tepe!=0)
    {
        DYigin* silinecek = tepe;
        tepe=tepe->sonraki;
        delete silinecek;
    }
}

void Yigin::sil(int veri)
{
    DYigin* aktif = tepe;
    DYigin* onceki = 0;
    while(aktif!=0 && aktif->veri!=veri)
    {
        onceki=aktif;
        aktif=aktif->sonraki;
    }
    if(aktif==0 || tepe == 0)
        return;
    if(aktif==tepe)
    {
        tepe=tepe->sonraki;
        delete aktif;
    }
    else
    {
        onceki->sonraki=aktif->sonraki;
        delete aktif;
    }
}

void Yigin::toplam()
{
    int toplam=0;
    DYigin* aktif = tepe;
    while(aktif!=0)
    {
        toplam+=aktif->veri;
        aktif=aktif->sonraki;
    }
    cout<<"Toplam: "<<toplam<<endl;
}

ostream& operator<<(ostream& os,Yigin& yigin)
{
    cout<<setw(5)<<"---->";
    DYigin* aktif = yigin.tepe;
    while(aktif!=0)
    {
        cout<<setw(5)<<aktif->veri<<endl<<setw(5)<<"     ";
        aktif=aktif->sonraki;
    }
    cout<<endl;
    return os;
}

int Yigin::getir()
{
    if(tepe!=0)
        return tepe->veri;
    else
        return 0;
}