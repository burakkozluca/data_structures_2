#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "AVLAgaci.hpp"
#include "Liste.hpp"

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
        agac.postOrder();
        agac.haricitoplam = agac.toplam();
        agac.sira = sira; 
        agac.asciideger = agac.ascii();
        liste.ekle(agac);
        sira++;
    }
    sira = 0;
    while(liste.uzunluk() >= 2)
    {
      int i = 0;
      int j = 0;
      int min = INT_MAX;
      int max = INT_MIN;
      if(sira % 2 == 0)
      {
        while(liste.dugumGetir(i) != 0)
        {
          if(liste.dugumGetir(i)->agac.yaprak.getir() != 0)
          {
            if(liste.dugumGetir(i)->agac.yaprak.getir() < min)
              min = liste.dugumGetir(i)->agac.yaprak.getir();
            i++;
          }
        }
        i = 0;
        while(liste.dugumGetir(i) != 0){
          liste.dugumGetir(i)->agac.yaprak.sil(min);
          i++;
        }
      }
      else
      {
        while(liste.dugumGetir(i) != 0)
        {
          if(liste.dugumGetir(i)->agac.yaprak.getir() != 0)
          {
            if(liste.dugumGetir(i)->agac.yaprak.getir() > max)
              max = liste.dugumGetir(i)->agac.yaprak.getir();
            i++;
          }
        }
        i = 0;
        while(liste.dugumGetir(i) != 0){
          liste.dugumGetir(i)->agac.yaprak.sil(max);
          i++;
        }
      }
      //eğerki silerken yığınlarda aynı sayi varsa ilk oluşturulan yığındakşini sil
      while(liste.dugumGetir(j) != 0)
      {
        if(liste.dugumGetir(j)->agac.yaprak.getir() == 0)
        {
          for(int i = 0; i < liste.uzunluk(); i++)
          {
            cout << (char)liste.dugumGetir(i)->agac.asciideger;
          }
          cout << "\033[2J\033[H";
          liste.cikar(j);
          if(liste.uzunluk() == 1)
            break;
          j--;
        }
        j++;
      }
      sira++;
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