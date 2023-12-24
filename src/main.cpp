#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "AVLAgaci.hpp"
#include "Liste.hpp"
#include "YListe.hpp"

using namespace std;

int main()
{
  std::string dosyaAdi = "Veri.txt";
  std::ifstream dosya(dosyaAdi);

  if(!dosya.is_open()){
    std::cerr << "Dosya acilamadi: " << dosyaAdi << std::endl;
    return 1;
  }
    Liste liste;
    YListe yliste;
    std::string satir;
    int sira = 1;
    while (std::getline(dosya, satir))
    {
        if (satir.empty()) {
          continue; // Skip empty lines
        }
        AVLAgaci agac;
        std::stringstream satirStream(satir);
        int sayi;

        while (satirStream >> sayi)
        {
          //eklerken ayni sayi geldi mi kontrolü yap
          if(agac.varmi(sayi))
            continue;
          agac.ekle(sayi);
        }
        yliste.ekle(agac.postOrder());
        agac.haricitoplam = agac.toplam();
        agac.sira = sira; 
        agac.asciideger = agac.ascii();
        liste.ekle(agac);
        sira++;
    }
    sira = 0;

    bool a = false;
    while(liste.uzunluk() >= 2)
    {
      int i = 0;
      int j = 0;
      int k = 0;
      int min = INT_MAX;
      int max = INT_MIN;
      
      if(sira % 2 == 0)
      {
        while(yliste.dugumGetir(i) != 0)
        {
          if(yliste.dugumGetir(i)->yigin.getir() != 0)
          {
            if(yliste.dugumGetir(i)->yigin.getir() < min){
              min = yliste.dugumGetir(i)->yigin.getir();
              k = i;
            } 
            i++;
          }
        }
        yliste.dugumGetir(k)->yigin.cikar();
        i = 0;
        k = 0;
      }
      else
      {
        while(yliste.dugumGetir(i) != 0)
        {
          if(yliste.dugumGetir(i)->yigin.getir() != 0)
          {
            if(yliste.dugumGetir(i)->yigin.getir() > max){
              max = yliste.dugumGetir(i)->yigin.getir();
              k = i;
            }
            i++;
          }
        }
        i = 0;
        yliste.dugumGetir(k)->yigin.cikar();
        k=0;
      }
      //eğerki silerken yığınlarda aynı sayi varsa ilk oluşturulan yığındakşini sil
      while(yliste.dugumGetir(j) != 0)
      {
        if(yliste.dugumGetir(j)->yigin.getir() == 0)
        {
          liste.cikar(j);
          yliste.tumElemanlariSil();
          for(int i = 0; i < liste.uzunluk(); i++)
          {
            cout << (char)liste.dugumGetir(i)->agac.asciideger;
            yliste.ekle(liste.dugumGetir(i)->agac.postOrder());
          }
          cout << "\033[2J\033[H";
          a = true;

          if(liste.uzunluk() == 1)
            break;
          j--;
        }
        j++;
      }
      if(a)
        sira = 0;
      else
        sira++;
      a = false;
    }
    cout << endl;
    cout << "=============================" << endl;
    cout << "|                           |" << endl;
    cout << "|                           |" << endl;
    cout << "|    Son Karakter:"<< char(liste.dugumGetir(0)->agac.asciideger) << "         |" << endl;
    cout << "|    AVL No      :"<< to_string(liste.dugumGetir(0)->agac.sira); for(int i=0;i< 10 - to_string(liste.dugumGetir(0)->agac.sira).size();i++){cout << " ";}cout <<"|" << endl;
    cout << "|                           |" << endl;
    cout << "|                           |" << endl;
    cout << "=============================" << endl;

  dosya.close();
}