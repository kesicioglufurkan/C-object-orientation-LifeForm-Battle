#include "Bocek.h"
// Bocek tipinde bir yap� olu�turur ve ba�lang�� de�erlerini atar
Bocek bocekOlustur(int sayi) {

	Bocek this;

	this = (Bocek)malloc(sizeof(struct BOCEK));
	char simge = 'C';
	this->super = canliOlustur(sayi, simge);	
	this->super->sayi = sayi;
	this->super->simge = simge;
	this->gorunum = this->super->gorunum;
	this->yoket = &bocekYoket;

	return this;

}

// Bocek yap�s�n� yok eder
void bocekYoket(const Bocek this) {
	if (this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
