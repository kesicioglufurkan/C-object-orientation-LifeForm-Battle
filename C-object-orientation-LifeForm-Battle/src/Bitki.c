#include "Bitki.h"
// Bitki tipinde bir yap� olu�turur ve ba�lang�� de�erlerini atar
Bitki bitkiOlustur(int sayi) {

	Bitki this;

	this = (Bitki)malloc(sizeof(struct BITKI));
	char simge = 'B';
	this->super = canliOlustur(sayi, simge);
	this->super->sayi = sayi;
	this->super->simge = simge;
	this->gorunum = this->super->gorunum;
	this->yoket = &bitkiYoket;

	return this;

}

// Bitki yap�s�n� yok eder
void bitkiYoket(const Bitki this) {
	if (this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
