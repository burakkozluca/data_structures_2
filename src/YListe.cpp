#include "YListe.hpp"

YListe::YListe(){
    ilk = 0;
}
YListe::~YListe(){
    YDugum* gec = ilk;
    while(gec != 0)
    {
        YDugum* silinecek = gec;
        gec=gec->sonraki;

        delete silinecek;
    }
}
void YListe::tumElemanlariSil() {
    while (ilk != nullptr) {
        YDugum* eskiDugum = ilk;
        ilk = ilk->sonraki;
        delete eskiDugum;
    }
}
void YListe::ekle(Yigin yigin)
{
    YDugum* yeniDugum = new YDugum(yigin);
    if(ilk==0)
    {
        ilk = yeniDugum;
    }
    else
    {
        YDugum* gec = ilk;

        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
    }
}

int YListe::uzunluk()
{
    int uzunluk=0;
    YDugum* gec = ilk;

    while(gec!=0)
    {
        uzunluk++;
        gec=gec->sonraki;
    }

    return uzunluk;
}

Yigin YListe::ilkGetir()
{
    if(ilk!=0)
        return ilk->yigin;
    throw std::out_of_range("Liste::ilkGetir(): Liste bos Hatasi");
}

void YListe::cikar()
{
    if(ilk==0)      return;

    if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
        YDugum* gec = ilk;

        while(gec->sonraki->sonraki!=0)
            gec= gec->sonraki;
        
        delete gec->sonraki;
        gec->sonraki = 0;
    }
}

void YListe::onuneEkle(int sira,Yigin yigin)
{
    YDugum* aktifDugum= dugumGetir(sira);

    if(aktifDugum)
    {
        YDugum* aktifsol = aktifDugum->onceki;

        YDugum* yeniDugum =new YDugum(yigin);

        aktifDugum->onceki = yeniDugum;

        yeniDugum->sonraki = aktifDugum;
        yeniDugum->onceki = aktifsol;

        if(aktifsol)
            aktifsol->sonraki = yeniDugum;
        else
            ilk=yeniDugum;

    }
}

void YListe::cikar(int sira)
{
    YDugum* silinecek= dugumGetir(sira);

    if(silinecek)
    {
        
        YDugum* silineceksol = silinecek->onceki;
        YDugum* silineceksag = silinecek->sonraki;

        if(silineceksag)
            silineceksag->onceki = silineceksol;
        
        if(silineceksol)
            silineceksol->sonraki = silineceksag;
        else
            ilk = silineceksag;
        delete silinecek;
    }
}

YDugum* YListe::dugumGetir(int sira)
{
    YDugum* gec = ilk;

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

YListe& YListe::operator=(const YListe& other) {
    
    if (this != &other) {

        while (ilk != nullptr) {
            cikar();
        }

        YDugum* current = other.ilk;
        while (current != nullptr) {
            Yigin copiedyigin = current->yigin;
            ekle(copiedyigin);
            current = current->sonraki;
        }
    }
    return *this;
}

ostream& operator<<(ostream& os,YListe& liste)
{
    using namespace std;

    YDugum* gec = liste.ilk;

    while(gec!=0)
    {
        os<<gec->yigin<<endl;
        gec=gec->sonraki;
    }

    os<<"-------------------------------------"<<endl;

    return os;
}