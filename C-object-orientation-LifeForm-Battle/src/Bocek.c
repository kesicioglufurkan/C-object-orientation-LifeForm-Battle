#include "Bocek.h"
// Bocek tipinde bir yapý oluþturur ve baþlangýç deðerlerini atar
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

// Bocek yapýsýný yok eder
void bocekYoket(const Bocek this) {
	if (this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
