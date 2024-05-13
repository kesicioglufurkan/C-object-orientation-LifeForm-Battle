#include "Canli.h"
// Canı tipinde bir yapı oluşturur ve başlangıç değerlerini atar
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

// Sayi değerini atamak için kullanılır
void setSayi(const Canli this, int sayi) {
	this->sayi = sayi;
}
// Simge değerini atamak için kullanılır
void setSimge(const Canli this, char simge) {
	this->simge = simge;
}
// Canlı yapısını yok eder
void canliYoket(const Canli this) {
	if (this == NULL) return;
	free(this);
}
// Canlı yapısının simgesini döndürür
char canliGorunum(const Canli this) {
	return this->simge;
}
