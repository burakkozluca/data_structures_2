#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include <iostream>
#include <stack>
#include "Dugum.hpp"
#include "Yigin.hpp"

using namespace std;

class AVLAgaci
{
public:
	AVLAgaci();
	~AVLAgaci();
	int sira;
	int haricitoplam;
	int asciideger;
	bool varmi(int veri);
	void ekle(int veri);
	void sil(int veri);
    friend ostream& operator<<(ostream& os,AVLAgaci& kuyruk);
	int yukseklik();
	
	int ascii();
	int toplam();
	void preOrder();
	Yigin postOrder();
	void inOrder();
	void boslukBirak(int adet);
private:
	int toplam(Dugum* aktif);
	int dengesizlikYonu(Dugum* aktif);
	int ascii(int haricitoplam);
	Dugum* solaDondur(Dugum* dugum);
	Dugum* sagaDondur(Dugum* dugum);
	int minDeger(Dugum* aktif);	
	void levelOrder();
	void preOrder(Dugum* aktif);
	void postOrder(Dugum* aktif, Yigin& yigin);
	void inOrder(Dugum* index);
	int yukseklik(Dugum* aktifDugum);
	Dugum* ekle(int veri,Dugum* aktifDugum);
	bool varmi(int aranan,Dugum* aktif);
	Dugum* sil(int veri,Dugum* aktif);
	int maxDeger(Dugum* aktif);
	Dugum* kok;
};
//diger fonksiyonlar eklenecek
#endif