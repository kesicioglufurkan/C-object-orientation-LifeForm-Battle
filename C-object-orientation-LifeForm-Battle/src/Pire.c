#include "Pire.h"
// Pire tipinde bir yapý oluþturur ve baþlangýç deðerlerini atar
Pire pireOlustur(int sayi) {

	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	this->super = bocekOlustur(sayi);
	this->super->super->simge = 'P';
	this->gorunum = this->super->gorunum;
	this->yoket = &pireYoket;

	return this;

}
// Pire yapýsýný yok eder
void pireYoket(const Pire this) {
	if (this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
