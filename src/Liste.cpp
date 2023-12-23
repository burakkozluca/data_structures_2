#include "Liste.hpp"
#include<iomanip>

Liste::Liste()
{
    ilk=0;
}
Liste::~Liste()
{
    LDugum* gec =ilk;
    while(gec!=0)
    {
        LDugum* silinecek = gec;
        gec=gec->sonraki;

        delete silinecek;
    }
}
void Liste::ekle(AVLAgaci agac)
{
    LDugum* yeniDugum = new LDugum(agac);
    if(ilk==0)
    {
        ilk = yeniDugum;
    }
    else
    {
        LDugum* gec = ilk;

        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
    }
}
int Liste::uzunluk()
{
    int uzunluk=0;
    LDugum* gec = ilk;

    while(gec!=0)
    {
        uzunluk++;
        gec=gec->sonraki;
    }

    return uzunluk;
}
AVLAgaci Liste::ilkGetir()
{
    if(ilk!=0)
        return ilk->agac;
    throw std::out_of_range("Liste::ilkGetir(): Liste bos Hatasi");
}
void Liste::cikar()
{
    if(ilk==0)      return;

    if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
        LDugum* gec = ilk;

        while(gec->sonraki->sonraki!=0)
            gec= gec->sonraki;
        
        delete gec->sonraki;
        gec->sonraki = 0;
    }


}
void Liste::onuneEkle(int sira,AVLAgaci agac)
{
    LDugum* aktifDugum= dugumGetir(sira);

    if(aktifDugum)
    {
        LDugum* aktifsol = aktifDugum->onceki;

        LDugum* yeniDugum =new LDugum(agac);

        aktifDugum->onceki = yeniDugum;

        yeniDugum->sonraki = aktifDugum;
        yeniDugum->onceki = aktifsol;

        if(aktifsol)
            aktifsol->sonraki = yeniDugum;
        else
            ilk=yeniDugum;

    }
}
void Liste::cikar(int sira)
{
    LDugum* silinecek= dugumGetir(sira);

    if(silinecek)
    {
        
        LDugum* silineceksol = silinecek->onceki;
        LDugum* silineceksag = silinecek->sonraki;

        if(silineceksag)
            silineceksag->onceki = silineceksol;
        
        if(silineceksol)
            silineceksol->sonraki = silineceksag;
        else
            ilk = silineceksag;
        delete silinecek;
    }
}
LDugum* Liste::dugumGetir(int sira)
{
    LDugum* gec = ilk;

    if (sira < 0 || sira >= uzunluk()) {
            return nullptr;
    }
    while(sira>=0&&gec!=0)
    {
       
        if(sira==0)
            return gec;
        gec=gec->sonraki;

        sira--;
    }

    return 0;
}
ostream& operator<<(ostream& os,Liste& liste)
{
    using namespace std;

    LDugum* gec = liste.ilk;

    while(gec!=0)
    {
        os<<gec->agac<<endl;
        gec=gec->sonraki;
    }

    os<<"-------------------------------------"<<endl;

    return os;
}