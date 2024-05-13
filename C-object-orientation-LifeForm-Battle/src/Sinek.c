#include "Sinek.h"
// Sinek tipinde bir yap� olu�turur ve ba�lang�� de�erlerini atar
Sinek sinekOlustur(int sayi) {

	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	this->super = bocekOlustur(sayi);
	this->super->super->simge = 'S';
	this->gorunum = this->super->gorunum;
	this->yoket = &sinekYoket;

	return this;

}
// Sinek yap�s�n� yok eder
void sinekYoket(const Sinek this) {
	if (this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}