#include "Canli.h"
// Can� tipinde bir yap� olu�turur ve ba�lang�� de�erlerini atar
Canli canliOlustur(int sayi, char simge) {


	Canli this;
	this = (Canli)malloc(sizeof(struct CANLI));
	this->sayi = sayi;
	this->simge = simge;
	this->setSayi = &setSayi;
	this->setSimge = &setSimge;
	this->gorunum = &canliGorunum;
	this->yoket = &canliYoket;
	return this;

}

// Sayi de�erini atamak i�in kullan�l�r
void setSayi(const Canli this, int sayi) {
	this->sayi = sayi;
}
// Simge de�erini atamak i�in kullan�l�r
void setSimge(const Canli this, char simge) {
	this->simge = simge;
}
// Canl� yap�s�n� yok eder
void canliYoket(const Canli this) {
	if (this == NULL) return;
	free(this);
}
// Canl� yap�s�n�n simgesini d�nd�r�r
char canliGorunum(const Canli this) {
	return this->simge;
}
